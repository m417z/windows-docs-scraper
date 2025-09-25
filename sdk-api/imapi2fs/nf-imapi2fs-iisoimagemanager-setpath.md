# IIsoImageManager::SetPath

## Description

Sets the **Path** property value with a logical path to an .iso image.

## Parameters

### `Val` [in]

The logical path to the .iso image. For example, "c:\\path\\file.iso".

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation.

| Return code | Description |
| --- | --- |
| **IMAPI_E_INVALID_PATH** | Path '%1!s!' is badly formed or contains invalid characters.<br><br>Value: 0xC0AAB110 |

## Remarks

This method is supported in Windows Server 2003 with Service Pack 1 (SP1), Windows XP with Service Pack 2 (SP2), and Windows Vista via the Windows Feature Pack for Storage. All features provided by this update package are supported natively in Windows 7 and Windows Server 2008 R2.

## See also

[IIsoImageManager](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-iisoimagemanager)

[IIsoImageManager::get_Path](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-iisoimagemanager-get_path)