# IFileSystemImage::get_UDFRevision

## Description

Retrieves the UDF revision level of the imported file system image.

## Parameters

### `pVal` [out]

UDF revision level of the imported file system image.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## Remarks

The value is encoded according to the UDF specification, except the variable size is LONG. For example, revision level 1.02 is represented as 0x102.

## See also

[IFileSystemImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage)

[IFileSystemImage::put_UDFRevision](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-put_udfrevision)