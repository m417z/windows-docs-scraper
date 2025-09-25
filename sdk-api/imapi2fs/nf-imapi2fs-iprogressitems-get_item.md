# IProgressItems::get_Item

## Description

Retrieves the specified progress item from the collection.

## Parameters

### `Index` [in]

Zero-based index number corresponding to a progress item in the collection.

### `item` [out]

An [IProgressItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-iprogressitem) interface associated with the specified index value.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **E_OUTOFMEMORY** | Failed to allocate the required memory.<br><br>Value: 0x8007000E |
| **E_INVALIDARG** | One or more arguments are not valid.<br><br>Value: 0x80070057 |

## Remarks

To enumerate all progress items, call the [IProgressItems::get__NewEnum](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-iprogressitems-get__newenum) method.

## See also

[IProgressItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-iprogressitem)

[IProgressItems](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-iprogressitems)

[IProgressItems::ProgressItemFromBlock](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-iprogressitems-progressitemfromblock)

[IProgressItems::ProgressItemFromDescription](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-iprogressitems-progressitemfromdescription)