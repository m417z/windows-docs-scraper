# IFsiNamedStreams::get_EnumNamedStreams

## Description

Creates a non-variant enumerator for the collection of the named streams associated with a file in the file system image.

## Parameters

### `NewEnum` [out, optional]

Pointer to a pointer to an [IEnumFsiItems](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ienumfsiitems) object representing a collection of named streams associated with a file.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code/value | Description |
| --- | --- |
| **E_POINTER**<br><br>Value: 0x80004003 | Pointer is not valid. |
| **E_OUTOFMEMORY**<br><br>Value: 0x8007000EL | Failed to allocate required memory. |

## Remarks

This method is supported in Windows Server 2003 with Service Pack 1 (SP1), Windows XP with Service Pack 2 (SP2), and Windows Vista via the Windows Feature Pack for Storage. All features provided by this update package are supported natively in Windows 7 and Windows Server 2008 R2.

## See also

[IFsiNamedStreams](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifsinamedstreams)