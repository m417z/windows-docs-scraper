# IActiveDesktop::AddDesktopItem

## Description

Adds a desktop item.

## Parameters

### `pcomp` [in]

Type: **LPCCOMPONENT**

A pointer to the [COMPONENT](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-component) structure that specifies the item to be added.

### `dwReserved`

Type: **DWORD**

Reserved. Must be set to zero.

## Return value

Type: **HRESULT**

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_FAIL** | Failed to add the desktop item, or an instance of the desktop item already exists on the Active Desktop. |
| **E_INVAILDARG** | One or more of the parameters were invalid. |
| **S_OK** | Desktop item has been added successfully. |

## Remarks

The desktop item is added to the desktop, but it does not save it to the registry. The client application must call [IActiveDesktop::ApplyChanges](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-iactivedesktop-applychanges) separately to update the registry.

## See also

[IActiveDesktop](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iactivedesktop)

[Using the Active Desktop Object](https://learn.microsoft.com/windows/desktop/lwef/active-desktop-interface)