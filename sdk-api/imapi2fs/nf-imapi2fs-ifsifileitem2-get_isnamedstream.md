# IFsiFileItem2::get_IsNamedStream

## Description

Determines if the item is a named stream. Data streams for named streams contained within the file system image are read-only. Stream data can only be replaced by overwriting the existing named stream.

## Parameters

### `pVal` [out]

Pointer to a value that indicates if the item is a named stream. to **VARIANT_TRUE** if an ; otherwise, **VARIANT_FALSE**.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## Remarks

The user must enable UDF and set the UDF revision to 2.00 or higher to support named streams.

This method is supported in Windows Server 2003 with Service Pack 1 (SP1), Windows XP with Service Pack 2 (SP2), and Windows Vista via the Windows Feature Pack for Storage. All features provided by this update package are supported natively in Windows 7 and Windows Server 2008 R2.

## See also

[IFsiFileItem2](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifsifileitem2)