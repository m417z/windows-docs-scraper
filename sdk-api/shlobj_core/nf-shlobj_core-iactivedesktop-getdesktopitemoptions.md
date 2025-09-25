# IActiveDesktop::GetDesktopItemOptions

## Description

Gets the options for the desktop item.

## Parameters

### `pco` [in, out]

Type: **LPCOMPONENTSOPT**

The address of the [COMPONENTSOPT](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-componentsopt) structure containing the options that are currently set.

### `dwReserved`

Type: **DWORD**

Reserved. Must be set to zero.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IActiveDesktop](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iactivedesktop)