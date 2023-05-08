// Copyright (c) 2023 Damitha Fernando <damitha.fernando@outlook.com>
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include <iostream>
#include "FilterExpression.h"
#include "FilterDescriptorLibrary.h"
#include "FilterDescriptor.h"

int main() {
    // TEMP: to check if dependencies from libpktfltr can be used
    // in the executable successfully
    pktfltr::FilterExpression expression("ip.addr == 1.2.3.0/24 && tcp");

    pktfltr::FilterDescriptorLibrary library;
    library.addFilterDescriptor(pktfltr::FilterDescriptor("ip"));
    library.addFilterDescriptor(pktfltr::FilterDescriptor("tcp"));
    library.addFilterDescriptor(pktfltr::FilterDescriptor("udp"));

    std::cout << "Filter count : " << library.getFilterCount() << std::endl;

    std::cout << "Hello Cruel World :(" << std::endl;
    return 0;
}
