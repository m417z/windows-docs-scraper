# IFileSystemImage::get_MultisessionInterfaces

## Description

Retrieves the list of multi-session interfaces for the optical media.

## Parameters

### `pVal` [out]

List of multi-session interfaces for the optical media. Each element of the list is a **VARIANT** of type **VT_Dispatch**. Query the **pdispVal** member of the variant for the [IMultisession](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-imultisession) interface.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **E_OUTOFMEMORY** | Failed to allocate the required memory.<br><br>Value: 0x8007000E |

## Remarks

Query the [IMultisession](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-imultisession) interface for a derived **IMultisession** interface, for example, the [IMultisessionSequential](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-imultisessionsequential) interface.

## See also

[IFileSystemImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage)

[IFileSystemImage::put_MultisessionInterfaces](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-put_multisessioninterfaces)