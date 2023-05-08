// Copyright (c) 2023 Damitha Fernando <damitha.fernando@outlook.com>
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "FilterDescriptor.h"

#include <string>

pktfltr::FilterDescriptor::FilterDescriptor(const std::string &name) : name(
        name) {}

const std::string &pktfltr::FilterDescriptor::getName() const {
    return name;
}
