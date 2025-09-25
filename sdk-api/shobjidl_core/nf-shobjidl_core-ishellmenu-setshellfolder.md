# IShellMenu::SetShellFolder

## Description

Specifies the folder for the menu band to browse.

## Parameters

### `psf` [in]

Type: **[IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder)***

A pointer to the folder's [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder) interface. This pointer can be **NULL**.

### `pidlFolder` [in]

Type: **PCIDLIST_ABSOLUTE**

The folder's fully qualified [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist). This value can be **NULL**.

### `hKey` [in]

Type: **HKEY**

An HKEY with an "Order" value that is used to store the order of the menu. This value can be **NULL**.

### `dwFlags` [in]

Type: **DWORD**

Flags that specify how the menu band operates.

#### SMSET_BOTTOM

Put this folder at the bottom of the menu.

#### SMSET_USEBKICONEXTRACTION

Use the background icon extractor.

#### SMSET_HASEXPANDABLEFOLDERS

This folder contains expandable folders.

#### SMSET_COLLAPSEONEMPTY

Collapse the menu if empty.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Call this method after you call [IShellMenu::Initialize](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellmenu-initialize).