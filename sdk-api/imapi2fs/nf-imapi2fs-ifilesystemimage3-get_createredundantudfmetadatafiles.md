# IFileSystemImage3::get_CreateRedundantUdfMetadataFiles

## Description

Retrieves a property value that specifies if the UDF Metadata will be redundant in the file system image.

## Parameters

### `pVal` [out]

Pointer to a value that specifies if the UDF metadata is redundant in the resultant file system image. A value of **VARIANT_TRUE** indicates that UDF metadata will be redundant; otherwise, **VARIANT_FALSE**.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code/value | Description |
| --- | --- |
| **E_POINTER**<br><br>(HRESULT) 0x80004003L | Invalid pointer. |

## Remarks

This method is supported in Windows Server 2003 with Service Pack 1 (SP1), Windows XP with Service Pack 2 (SP2), and Windows Vista via the Windows Feature Pack for Storage. All features provided by this update package are supported natively in Windows 7 and Windows Server 2008 R2.

## See also

[IFileSystemImage3](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage3)