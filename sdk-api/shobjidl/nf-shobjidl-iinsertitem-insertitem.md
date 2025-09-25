# IInsertItem::InsertItem

## Description

Adds an [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure to a list of such structures.

## Parameters

### `pidl` [in]

Type: **LPCITEMIDLIST**

A pointer to an [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure that corresponds to an item in a Shell folder.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.