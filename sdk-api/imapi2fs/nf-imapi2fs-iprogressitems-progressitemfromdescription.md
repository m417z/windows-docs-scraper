# IProgressItems::ProgressItemFromDescription

## Description

Retrieves a progress item based on the specified file name.

## Parameters

### `description` [in]

String that contains the file name of the progress item to retrieve. The method returns the progress item if this string matches the value for item's description property.

### `item` [out]

An [IProgressItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-iprogressitem) interface of the progress item associated with the specified file name.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_FAIL** | *description* is **NULL**.<br><br>Value:0x80004005 |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **E_OUTOFMEMORY** | Failed to allocate the required memory.<br><br>Value: 0x8007000E |
| **E_INVALIDARG** | One or more arguments are not valid.<br><br>Value: 0x80070057 |

## See also

[IProgressItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-iprogressitem)

[IProgressItems](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-iprogressitems)

[IProgressItems::ProgressItemFromBlock](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-iprogressitems-progressitemfromblock)

[IProgressItems::get_Item](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-iprogressitems-get_item)