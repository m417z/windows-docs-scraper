# IEnumProgressItems::Next

## Description

Retrieves a specified number of items in the enumeration sequence.

## Parameters

### `celt` [in]

Number of items to retrieve.

### `rgelt` [out]

Array of [IProgressItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-iprogressitem) interfaces. You must release each interface in rgelt when done.

### `pceltFetched` [out]

Number of elements returned in rgelt. You can set *pceltFetched* to **NULL** if *celt* is one. Otherwise, initialize the value of *pceltFetched* to 0 before calling this method.

## Return value

S_OK is returned when the number of requested elements (*celt*) are returned successfully or the number of returned items (*pceltFetched*) is less than the number of requested elements.

Other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **E_OUTOFMEMORY** | Failed to allocate the required memory.<br><br>Value: 0x8007000E |
| **E_INVALIDARG** | One or more arguments are not valid.<br><br>Value: 0x80070057 |

## Remarks

If there are fewer than the requested number of elements left in the sequence, it retrieves the remaining elements.

## See also

[IEnumProgressItems](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ienumprogressitems)

[IEnumProgressItems::RemoteNext](https://learn.microsoft.com/windows/desktop/imapi/ienumprogressitems-remotenext)