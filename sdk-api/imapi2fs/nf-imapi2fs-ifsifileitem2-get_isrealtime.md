# IFsiFileItem2::get_IsRealTime

## Description

Retrieves the property value that specifies if a file item in the file system image is a 'Real-Time' or standard file.

## Parameters

### `pVal` [out]

Pointer to a value that indicates if the Real-Time attribute of the file is set in the file system image. A value of **VARIANT_TRUE** indicates the attribute is set; otherwise, **VARIANT_FALSE**.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code/value | Description |
| --- | --- |
| **E_POINTER**<br><br>Value: 0x80004003 | Pointer is not valid. |
| **IMAPI_E_PROPERTY_NOT_ACCESSIBLE**<br><br>Value: 0xC0AAB160L | Property '*%1!ls!*' is not accessible. |

## Remarks

If this method is invoked for a file item representing a named stream, this method returns error code **IMAPI_E_PROPERTY_NOT_ACCESSIBLE** as
named streams do not have the Real-Time attribute.

The user must enable UDF and set the UDF revision to 2.01 or higher to support Real-Time files.

This method is supported in Windows Server 2003 with Service Pack 1 (SP1), Windows XP with Service Pack 2 (SP2), and Windows Vista via the Windows Feature Pack for Storage. All features provided by this update package are supported natively in Windows 7 and Windows Server 2008 R2.

## See also

[IFsiFileItem2](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifsifileitem2)