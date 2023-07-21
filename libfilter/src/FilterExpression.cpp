// Copyright (c) 2023 Damitha Fernando <damitha.fernando@outlook.com>
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

// Parse filter expression in string form such as "ip.src == 1.2.3.0/24 && tcp"
// and build filter object that can be efficiently executed on a packet

#include "FilterExpression.h"

#include <string>
#include <utility>
#include <iostream>

pktfltr::FilterExpression::FilterExpression(std::string filterString)
        : filterString(std::move(filterString)) {}

bool pktfltr::FilterExpression::isExpressionParsed() const {
    return isParsingComplete;
}

/**
 * @brief Parse the filter expression string and build a filter object
 *
 * Filter expression could have one or more simple filters joined together
 * using boolean operators. A simple filter is in the form of
 *  filter_name [operator] [operand]. e.g., "ip.addr == 1.2.3.0/24"
 * The operator and operand pair can be optional ("tcp").
 *
 * TODO: add return when available
 */
void pktfltr::FilterExpression::parseExpression() {

    if (isParsingComplete) {
        return;
    }

    // The parser looks for the syntax for a simple filter. If the entire
    // input is just one simple filter (e.g., "tcp.port == 22"), the parser
    // returns a filter object. If there are more than one filter in the
    // expression (combined together with boolean operators, e.g.,
    // "ip.addr == 1.2.3.4 && udp") a composite filter object which encompasses
    // individual simple filters, is returned.
    //
    // Parser is based on the following state machine
    //
    //                            ┌─────┐
    //                            │Start│
    //                            └─────┘
    //                               │
    //                               ▼
    //                     ┌────────────────────┐
    //                     │    Parse Simple    │
    //                     │    Filter Expr     │
    //                  ┌─▶│ (Open parentheses  │──┐
    //                  │  │    are allowed)    │  │
    //                  │  └────────────────────┘  │
    //            &, || │                          │ Simple
    //           found  │                          │ filter
    //                  │                          │ found
    //                  │  ┌────────────────────┐  │
    //                  │  │   Expect boolean   │  │
    //                  │  │  operator or end   │  │
    //                  └──│     of string      │◀─┘
    //                     │ (Close parentheses │
    //                     │    are allowed)    │
    //                     └────────────────────┘
    //                                │
    //                   End of input │  All open
    //                  string reached│  parentheses
    //                                │  are closed
    //                                ▼
    //                             ┌────┐
    //                             │End │
    //                             └────┘
    // Opening or closing parentheses are only allowed at the respective state
    // and would not result in a state transition.
    //
    // By the time the end of filter string is reached, any state other
    // than the end is an error condition.

    bool expectSimpleFilter = true; // false == expect boolean operator
    int openParenthesesCount = 0;

    while (nextToParse < filterString.size()) {

        std::cout << "Rest of filterString = " // TODO: remove
                  << filterString.substr(nextToParse) << std::endl;

        nextToParse = filterString.find_first_not_of(" \t", nextToParse);

        if (expectSimpleFilter) {
            // Find next token and run it through FilterDescriptorLibrary
            // to see if it is a valid filter. If so, process further.
            expectSimpleFilter = false;
        } else {
            // Expect a boolean operator || or &&
            expectSimpleFilter = true;
        }
        //TODO: update nextToParse based on the state machine
    }

    // Super awesome outer/inner state machine to parse

    // TODO: trim leading whitespace from filterString
    filterString.erase(0, filterString.find_first_not_of(' '));


    isParsingComplete = true;
}
