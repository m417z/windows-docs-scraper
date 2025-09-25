# IFsiFileItem2::AddStream

## Description

Associates a named stream with a specific file in the file system image.

## Parameters

### `name` [in]

A string represents the name of the named stream. This should not include the path and should only contain valid characters as per file system naming conventions.

### `streamData` [in]

An **IStream** interface of the named stream used to write to the resultant file system image.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code/value | Description |
| --- | --- |
| **IMAPI_S_IMAGE_FEATURE_NOT_SUPPORTED**<br><br>Value: 0x00AAB15FL | Feature is not supported for the current file system revision, and as a result, will be created without this feature. |
| **E_POINTER**<br><br>Value: 0x80004003 | Pointer is not valid. |
| **IMAPI_E_INVALID_PARAM**<br><br>Value: 0xC0AAB101 | The value specified for parameter '*%1!ls!*' is invalid. |
| **IMAPI_E_NOT_IN_FILE_SYSTEM**<br><br>Value: 0xC0AAB10B | *ls!'* is not part of the file system. It must be added to complete this operation. |
| **IMAPI_E_READONLY**<br><br>Value: 0xC0AAB102 | The referenced [IFileSystemImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage) object is in read only mode. |
| **IMAPI_E_FSI_INTERNAL_ERROR**<br><br>Value: 0xC0AAB100L | Internal file system error has occurred. |
| **IMAPI_E_DUP_NAME**<br><br>Value: 0xC0AAB112L | *'%1!ls!'* name already exists. |
| **IMAPI_E_DATA_STREAM_READ_FAILURE**<br><br>Value: 0xC0AAB129L | Cannot read data from stream supplied for file *'%1!ls!'*. |
| **IMAPI_E_IMAGE_SIZE_LIMIT**<br><br>Value: 0xC0AAB120L | Adding *'%1!ls!'* would result in a result image having a size larger than the current configured limit. |
| **IMAPI_E_DATA_STREAM_INCONSISTENCY**<br><br>Value: 0xC0AAB128L | The data stream supplied for the file *'%1!ls!'* is inconsistent; expected *%2!I64d!* bytes, found *%3!I64d!* |
| **E_OUTOFMEMORY**<br><br>Value: 0x8007000EL | Failed to allocate required memory. |

## Remarks

The file to which the named stream will be added must already exist within the file system image. If this method is called with a *name* that already exists for a named stream, it will return an error and will not replace the existing named stream.

If this method is invoked for a file system object that does not contain UDF in the list of file systems enabled for creation in the resultant image or if the UDF revision is below 2.00, this method returns success code **IMAPI_S_IMAGE_FEATURE_NOT_SUPPORTED**. This success code indicates that the named stream has been added but will not appear in the resultant file system image unless UDF revision 2.00 or higher is enabled in the file system object.

Currently, **IMAPI_E_READONLY** is returned when this method is called on an imported file system image, regardless of the read only status of the image.

This method is supported in Windows Server 2003 with Service Pack 1 (SP1), Windows XP with Service Pack 2 (SP2), and Windows Vista via the Windows Feature Pack for Storage. All features provided by this update package are supported natively in Windows 7 and Windows Server 2008 R2.

## See also

[IFsiFileItem2](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifsifileitem2)