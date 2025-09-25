# IProgressItems::get_EnumProgressItems

## Description

Retrieves the list of progress items from the collection.

## Parameters

### `NewEnum` [out]

An [IEnumProgressItems](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ienumprogressitems) interface that contains a collection of the progress items contained in the collection.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **E_OUTOFMEMORY** | Failed to allocate the required memory.<br><br>Value: 0x8007000E |

## Remarks

This property returns the same results as the [IProgressItems::get__NewEnum](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-iprogressitems-get__newenum) property and is meant for use by C/C++ applications.

## See also

[IEnumProgressItems](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ienumprogressitems)

[IProgressItems](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-iprogressitems)