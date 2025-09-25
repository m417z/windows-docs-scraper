# IFsiFileItem::put_Data

## Description

Sets the data stream of the file's content.

## Parameters

### `newVal` [in]

An **IStream** interface of the content of the file to add to the file system image.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **IMAPI_E_READONLY** | FileSystemImage object is in read only mode.<br><br>Value: 0xC0AAB102 |

## Remarks

The contents of the file becomes read-only once the file item is added to file system image.

## See also

[IFsiFileItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifsifileitem)

[IFsiFileItem::get_Data](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsifileitem-get_data)