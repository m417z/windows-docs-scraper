# IFsiItem::get_IsHidden

## Description

Determines if the item's hidden attribute is set in the file system image.

## Parameters

### `pVal` [out]

Is VARIANT_TRUE if the hidden attribute of the item is marked in the file system image; otherwise, VARIANT_FALSE.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## See also

[IFsiItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifsiitem)

[IFsiItem::put_IsHidden](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsiitem-put_ishidden)