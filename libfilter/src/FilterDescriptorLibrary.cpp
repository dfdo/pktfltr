// Copyright (c)  2023 Damitha Fernando <damitha.fernando@outlook.com>
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "FilterDescriptorLibrary.h"

void pktfltr::FilterDescriptorLibrary::addFilterDescriptor(
        pktfltr::FilterDescriptor &&descriptor) {

    descriptorMap.emplace(
            descriptor.getName(), std::forward<FilterDescriptor>(descriptor));

}

std::size_t pktfltr::FilterDescriptorLibrary::getFilterCount() const {
    return descriptorMap.size();
}

pktfltr::FilterDescriptor &
pktfltr::FilterDescriptorLibrary::getFilterDescriptor(const std::string &name) {
    return descriptorMap.at(name);
}
