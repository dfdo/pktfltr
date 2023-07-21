// Copyright (c)  2023 Damitha Fernando <damitha.fernando@outlook.com>
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#ifndef PKTFLTR_FILTERDESCRIPTORLIBRARY_H
#define PKTFLTR_FILTERDESCRIPTORLIBRARY_H

#include "FilterDescriptor.h"

#include <string>
#include <unordered_map>

namespace pktfltr {
    class FilterDescriptorLibrary {
    public:
        void addFilterDescriptor(FilterDescriptor&& descriptor);
        [[nodiscard]] std::size_t getFilterCount() const;
        FilterDescriptor& getFilterDescriptor(const std::string& name);

    private:
        std::unordered_map<std::string, FilterDescriptor> descriptorMap;

    };
}


#endif //PKTFLTR_FILTERDESCRIPTORLIBRARY_H
