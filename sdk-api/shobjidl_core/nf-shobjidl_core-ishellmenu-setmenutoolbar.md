# IShellMenu::SetMenuToolbar

## Description

Adds a menu to the menuband.

## Parameters

### `punk` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to an object that supports **CLSID_MenuToolbarBase** in its [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) method.

### `dwFlags` [in]

Type: **DWORD**

Flags that control how the menu operates.

#### SMSET_TOP

Bias this namespace to the top of the menu.

#### SMSET_BOTTOM

Bias this namespace to the bottom of the menu.

#### SMSET_DONTOWN

The Menuband does not own the non-ref counted object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.