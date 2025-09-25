# IBrowserService::SetReferrer

## Description

Deprecated. Sets the pointer to an item identifier list (PIDL) used for zone checking when creating a new window.

## Parameters

### `pidl` [in]

Type: **LPITEMIDLIST**

A pointer to the [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure (PIDL) used for zone checking.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.