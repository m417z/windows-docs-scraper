# IEnumFsiItems::Clone

## Description

Creates another enumerator that contains the same enumeration state as the current one.

## Parameters

### `ppEnum` [out]

Receives the interface pointer to the enumeration object. If the method is unsuccessful, the value of this output variable is undefined. You must release *ppEnum* when done.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **E_OUTOFMEMORY** | Failed to allocate the required memory.<br><br>Value: 0x8007000E |

## Remarks

Using this method, a client can record a particular point in the enumeration sequence, and then return to that point at a later time. The new enumerator supports the same interface as the original one.

## See also

[IEnumFsiItems](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ienumfsiitems)