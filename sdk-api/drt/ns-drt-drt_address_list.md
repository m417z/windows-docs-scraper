# DRT_ADDRESS_LIST structure

## Description

The **DRT_ADDRESS_LIST** structure contains a set of [DRT_ADDRESS](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_address) structures that represent the nodes contacted during a search for a key.

## Members

### `AddressCount`

The count of entries in **AddressList**.

### `AddressList`

An array of [DRT_ADDRESS](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_address) structures that contain information about addresses that participated in the search operation.

## See also

[DRT_ADDRESS](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_address)

[DrtGetSearchResult](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtgetsearchresult)