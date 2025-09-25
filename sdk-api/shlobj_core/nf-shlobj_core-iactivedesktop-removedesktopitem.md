# IActiveDesktop::RemoveDesktopItem

## Description

Removes the specified desktop item from the desktop.

## Parameters

### `pcomp` [in]

Type: **LPCCOMPONENT**

The address of the [COMPONENT](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-component) structure that specifies the item to be removed. The desktop item associated with the **wszSource** member of the structure will be removed.

### `dwReserved`

Type: **DWORD**

Reserved. Must be set to zero.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IActiveDesktop](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iactivedesktop)