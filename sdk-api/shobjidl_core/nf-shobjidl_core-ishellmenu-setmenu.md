# IShellMenu::SetMenu

## Description

Appends a static menu to the menu band.

## Parameters

### `hmenu` [in]

Type: **HMENU**

The handle of the static menu that is to be appended. This value can be **NULL**.

### `hwnd` [in]

Type: **HWND**

The **HWND** of the owner window. This value can be **NULL**.

### `dwFlags` [in]

Type: **DWORD**

Flags that specify how the menu operates.

#### SMSET_BOTTOM

Attach the menu to the bottom of the parent menu.

#### SMSET_TOP

Attach the menu to the top of the parent menu.

#### SMSET_DONTOWN

The menu band does not own the menu named in *hwnd*, so should that menu eventually be replaced, it should not be destroyed.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.