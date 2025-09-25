# FWP_V6_ADDR_AND_MASK structure

## Description

The **FWP_V6_ADDR_AND_MASK** structure specifies an IPv6 address and mask.

## Members

### `addr`

An array of size **FWP_V6_ADDR_SIZE** bytes containing an IPv6 address. **FWP_V6_ADDR_SIZE** maps to 16.

### `prefixLength`

Value specifying the prefix length of the IPv6 address.

## Remarks

The mask is specified by the width in bits. For
example, a prefixLength of 16 specifies a mask consisting of 16 1's followed
by 112 0's.

## See also

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)