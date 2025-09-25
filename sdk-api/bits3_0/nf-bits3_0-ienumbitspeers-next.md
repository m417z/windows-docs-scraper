# IEnumBitsPeers::Next

## Description

Retrieves a specified number of items in the enumeration sequence. If there are fewer than the requested number of elements left in the sequence, it retrieves the remaining elements.

## Parameters

### `celt` [in]

Number of elements requested.

### `rgelt` [out]

Array of
[IBitsPeer](https://learn.microsoft.com/windows/desktop/api/bits3_0/nn-bits3_0-ibitspeer) objects. You must release each object in *rgelt* when done.

### `pceltFetched` [out]

Number of elements returned in *rgelt*. You can set *pceltFetched* to **NULL** if *celt* is one. Otherwise, initialize the value of *pceltFetched* to 0 before calling this method.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Successfully returned the number of requested elements. |
| **S_FALSE** | Returned less than the number of requested elements. |

## See also

[IEnumBitsPeers](https://learn.microsoft.com/windows/desktop/api/bits3_0/nn-bits3_0-ienumbitspeers)