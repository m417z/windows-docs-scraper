# IActiveDesktop::SetDesktopItemOptions

## Description

Sets the item's options.

## Parameters

### `pco` [in]

Type: **LPCCOMPONENTSOPT**

The address of the [COMPONENTSOPT](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-componentsopt) structure that contains the options to set.

### `dwReserved`

Type: **DWORD**

Reserved. Must be set to zero.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IActiveDesktop](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iactivedesktop)