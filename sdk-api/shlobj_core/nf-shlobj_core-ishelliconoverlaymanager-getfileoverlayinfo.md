# IShellIconOverlayManager::GetFileOverlayInfo

## Description

Gets the index of the icon overlay or the icon image for the specified file with the specified attributes.

## Parameters

### `pwszPath` [in]

Type: **PCWSTR**

The full path of the file.

### `dwAttrib`

Type: **DWORD**

The attributes of the file. This parameter can be a combination of any of the file attribute flags (FILE_ATTRIBUTE_*) defined in the Windows header files. See [File Attribute Constants](https://learn.microsoft.com/windows/desktop/FileIO/file-attribute-constants).

### `pIndex` [out]

Type: **int***

A pointer to the icon index in the system image list.

### `dwflags`

Type: **DWORD**

For the index of the icon overlay, use SIOM_OVERLAYINDEX. For the index of the icon image, use SIOM_ICONINDEX.

## Return value

Type: **HRESULT**

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The appropriate index was found. |
| **E_FAIL** | Failure for any reason. |

## See also

[IShellIconOverlay](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-ishelliconoverlay)

[IShellIconOverlayManager](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-ishelliconoverlaymanager)