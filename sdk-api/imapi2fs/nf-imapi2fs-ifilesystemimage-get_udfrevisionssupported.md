# IFileSystemImage::get_UDFRevisionsSupported

## Description

Retrieves a list of supported UDF revision levels.

## Parameters

### `pVal` [out]

List of supported UDF revision levels. Each element of the list is VARIANT. The variant type is **VT_I4**. The **lVal** member of the variant contains the revision level.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## Remarks

The value is encoded according to the UDF specification, except the variable size is LONG. For example, revision level 1.02 is represented as 0x102.

## See also

[IFileSystemImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage)

[IFileSystemImage::get_UDFRevision](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-get_udfrevision)

[IFileSystemImage::put_UDFRevision](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-put_udfrevision)