# IFsiNamedStreams::get_Count

## Description

Returns the number of the named streams associated with a file in the file system image.

## Parameters

### `count` [out]

Pointer to a value indicating the total number of named streams in the collection.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code/value | Description |
| --- | --- |
| **E_POINTER**<br><br>Value: 0x80004003 | Pointer is not valid. |

## Remarks

This method is supported in Windows Server 2003 with Service Pack 1 (SP1), Windows XP with Service Pack 2 (SP2), and Windows Vista via the Windows Feature Pack for Storage. All features provided by this update package are supported natively in Windows 7 and Windows Server 2008 R2.

## See also

[IFsiNamedStreams](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifsinamedstreams)