// Copyright (c) 2023 Damitha Fernando <damitha.fernando@outlook.com>
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

// Parse filter expression such as "ip.src == 1.2.3.0/24 && tcp" and build
// filter object.

#ifndef PKTFLTR_FILTEREXPRESSION_H
#define PKTFLTR_FILTEREXPRESSION_H

#include <string>
#include <utility>

namespace pktfltr {
    class FilterExpression {
    public:
        explicit FilterExpression(std::string  filterString);

        [[nodiscard]] bool isExpressionParsed() const;
        void parseExpression();

    private:
        size_t nextToParse{}; // index of next char to parse
        std::string filterString;
        bool isParsingComplete{};
    };
}

#endif //PKTFLTR_FILTEREXPRESSION_H
