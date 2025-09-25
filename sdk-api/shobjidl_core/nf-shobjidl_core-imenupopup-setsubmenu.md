# IMenuPopup::SetSubMenu

## Description

Sets the given menu bar interface to be the submenu of the calling application object's interface.

## Parameters

### `pmp` [in]

Type: **[IMenuPopup](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-imenupopup)***

A pointer to an [IMenuPopup](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-imenupopup) interface that specifies the menu bar of interest.

### `fSet`

Type: **BOOL**

Removes the submenu if *fSet* is set to **FALSE**.

## Return value

Type: **HRESULT**

Always returns S_OK.