# IProgressItem::get_BlockCount

## Description

Retrieves the number of blocks in the progress item.

## Parameters

### `blocks` [out]

Number of blocks in the segment.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## See also

[IProgressItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-iprogressitem)

[IProgressItem::get_FirstBlock](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-iprogressitem-get_firstblock)

[IProgressItem::get_LastBlock](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-iprogressitem-get_lastblock)