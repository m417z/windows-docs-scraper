# IFileSystemImage::put_UDFRevision

## Description

Sets the UDF revision level of the file system image.

## Parameters

### `newVal` [in]

A hexadecimal number representing the UDF revision level.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **IMAPI_E_INVALID_PARAM** | The value specified for parameter *%1!ls!* is not valid.<br><br>Value: 0xC0AAB101 |

## Remarks

The value is encoded according to the UDF specification, except the variable size is LONG. For example, revision level 1.02 is represented as 0x102.

This property is used to specify the UDF revision in a new file system image. If the file system is imported, you cannot call this method to change the UDF revision level.

To determine the supported UDF revision levels, call the [IFileSystemImage::get_UDFRevisionsSupported](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-get_udfrevisionssupported) method.

## See also

[IFileSystemImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage)

[IFileSystemImage::get_UDFRevision](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-get_udfrevision)