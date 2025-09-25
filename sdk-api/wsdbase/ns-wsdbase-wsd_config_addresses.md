# WSD_CONFIG_ADDRESSES structure

## Description

Information about specific addresses that a host should listen on.

## Members

### `addresses`

An array of pointers to [IWSDAddress](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdaddress) interfaces.

If *pszLocalId* contains a logical address, the resulting behavior is a mapping between the logical address and a specific set of physical addresses (instead of a mapping between the logical address and a default physical address).

### `dwAddressCount`

The number of items in the **addresses** array.