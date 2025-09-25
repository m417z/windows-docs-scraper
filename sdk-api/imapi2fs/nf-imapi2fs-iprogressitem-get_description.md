# IProgressItem::get_Description

## Description

Retrieves the description in the progress item.

## Parameters

### `desc` [out]

String containing the description. The description contains the name of the file in the file system image.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## See also

[IProgressItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-iprogressitem)