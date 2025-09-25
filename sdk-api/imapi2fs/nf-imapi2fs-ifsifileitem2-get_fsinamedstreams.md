# IFsiFileItem2::get_FsiNamedStreams

## Description

Retrieves a collection of named streams associated with a file in the file system image.

## Parameters

### `streams` [out, optional]

Pointer to an [IFsiNamedStreams](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifsinamedstreams) object that represents a collection of named streams associated with the file.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code/value | Description |
| --- | --- |
| **E_POINTER**<br><br>Value: 0x80004003 | Invalid pointer. |
| **IMAPI_E_PROPERTY_NOT_ACCESSIBLE**<br><br>Value: 0xC0AAB160L | Property '*%1!ls!*' is not accessible. |
| **E_OUTOFMEMORY**<br><br>Value: 0x8007000E | Failed to allocate necessary memory. |

## Remarks

If this method is invoked for a file item which itself represents a named stream, the **IMAPI_E_PROPERTY_NOT_ACCESSIBLE** error code is returned, as a named streams cannot contain additional named streams.

The user must enable UDF and set the UDF revision to 2.00 or higher to support named streams.

This method is supported in Windows Server 2003 with Service Pack 1 (SP1), Windows XP with Service Pack 2 (SP2), and Windows Vista via the Windows Feature Pack for Storage. All features provided by this update package are supported natively in Windows 7 and Windows Server 2008 R2.

## See also

[IFsiFileItem2](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifsifileitem2)