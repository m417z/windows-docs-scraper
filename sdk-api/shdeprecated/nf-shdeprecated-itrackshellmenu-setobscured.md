# ITrackShellMenu::SetObscured

## Description

Coordinates obscured items on a toolbar with items in a menu.

## Parameters

### `hwndTB` [in]

Type: **HWND**

A handle to a toolbar control whose buttons have command IDs that correspond to menu IDs in the tracked menu.

### `punkBand` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

If this parameter points to a COM object that supports the [IShellMenu](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellmenu) interface, menu items that correspond to visible toolbar buttons are filtered out of the menu so that they do not appear in both places.

If this parameter is **NULL** or points to a COM object that does not support the [IShellMenu](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellmenu) interface, then the obscured buttons in the toolbar are added to the shell menu in the position specified in *dwSMSetFlags*.

### `dwSMSetFlags` [in]

Type: **DWORD**

One of the following values.

#### SMSET_TOP (0x10000000)

New menu items are added at the top of the menu.

#### SMSET_BOTTOM (0x20000000)

New menu items are added at the bottom of the menu.

#### SMSET_DONTOWN

Reserved; do not use.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Obscured buttons are those buttons that cannot be displayed due to toolbar size limitations. Commonly, to see them you must press the chevron at the end of the toolbar.