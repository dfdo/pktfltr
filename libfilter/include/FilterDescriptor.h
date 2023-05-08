// Copyright (c)  2023 Damitha Fernando <damitha.fernando@outlook.com>
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#ifndef PKTFLTR_FILTERDESCRIPTOR_H
#define PKTFLTR_FILTERDESCRIPTOR_H

#include <string>

namespace pktfltr {
    class FilterDescriptor {
    public:
        explicit FilterDescriptor(const std::string &name);

    private:
        std::string name;
    public:
        const std::string &getName() const;
        //TODO: bit-field for supported operators (==, !=, >, <=, neq)
        //TODO: callback for parsing the said operand(s) and build predicate
    };
}

#endif //PKTFLTR_FILTERDESCRIPTOR_H
