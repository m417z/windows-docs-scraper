# IActiveDesktop::GetDesktopItemBySource

## Description

Gets a desktop item using its source URL.

## Parameters

### `pwszSource` [in]

Type: **PCWSTR**

A pointer to a string that contains the source URL of the desktop item.

### `pcomp` [in, out]

Type: **LPCOMPONENT**

A pointer to the [COMPONENT](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-component) structure that, when this method returns successfully, receives the details about the desktop item. On entry, the size of the structure must be set.

### `dwReserved`

Type: **DWORD**

Reserved. Must be set to zero.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IActiveDesktop](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iactivedesktop)