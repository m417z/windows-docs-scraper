# IShellView2::HandleRename

## Description

Used to change an item's identifier.

## Parameters

### `pidlNew`

Type: **PCUITEMID_CHILD**

A pointer to an [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure. The current identifier is passed in and is replaced by the new one.

## Return value

Type: **HRESULT**

Return S_OK if successful, or a COM-defined error code otherwise.