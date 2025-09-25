# IProgressItems::ProgressItemFromBlock

## Description

Retrieves a progress item based on the specified block number.

## Parameters

### `block` [in]

Block number of the progress item to retrieve. The method returns the progress item if the block number is in the first and last block range of the item.

### `item` [out]

An [IProgressItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-iprogressitem) interface associated with the specified block number.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **E_OUTOFMEMORY** | Failed to allocate the required memory.<br><br>Value: 0x8007000E |
| **E_INVALIDARG** | One or more arguments are not valid.<br><br>Value: 0x80070057 |

## See also

[IProgressItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-iprogressitem)

[IProgressItems](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-iprogressitems)

[IProgressItems::ProgressItemFromDescription](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-iprogressitems-progressitemfromdescription)

[IProgressItems::get_Item](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-iprogressitems-get_item)