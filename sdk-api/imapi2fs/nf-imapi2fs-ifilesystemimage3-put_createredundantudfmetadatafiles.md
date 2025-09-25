# IFileSystemImage3::put_CreateRedundantUdfMetadataFiles

## Description

Sets the property that specifies if the UDF Metadata will be redundant in the file system image.

## Parameters

### `newVal` [in]

Specifies if the UDF metadata is redundant in the resultant file system image or not. A value of **VARIANT_TRUE** indicates that UDF metadata will be redundant; otherwise, **VARIANT_FALSE**.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code/value | Description |
| --- | --- |
| **IMAPI_S_IMAGE_FEATURE_NOT_SUPPORTED**<br><br>Value: 0x00AAB15FL | Option changed, but the feature is not supported for the implemented file system revision, and the image will be created without this feature. |

## Remarks

The UDF metadata redundancy option affects only UDF revisions 2.50 and higher. If this method is invoked for a file system object that does not contain the required UDF revision in the list of file systems enabled for creation in the resultant image this method returns **IMAPI_S_IMAGE_FEATURE_NOT_SUPPORTED**.

This method is supported in Windows Server 2003 with Service Pack 1 (SP1), Windows XP with Service Pack 2 (SP2), and Windows Vista via the Windows Feature Pack for Storage. All features provided by this update package are supported natively in Windows 7 and Windows Server 2008 R2.

## See also

[IFileSystemImage3](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage3)