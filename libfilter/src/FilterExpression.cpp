// Copyright (c) 2023 Damitha Fernando <damitha.fernando@outlook.com>
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

// Parse filter expression in string form such as "ip.src == 1.2.3.0/24 && tcp"
// and build filter object that can be efficiently executed on a packet

#include "FilterExpression.h"

#include <string>
#include <utility>

pktfltr::FilterExpression::FilterExpression(std::string  filterString) : filterString(std::move(filterString)) {}

bool pktfltr::FilterExpression::isExpressionParsed() const {
    return isParsingComplete;
}

void pktfltr::FilterExpression::parseExpression() {
    // Super awesome outer/inner state machine to parse
    isParsingComplete = true;
}
