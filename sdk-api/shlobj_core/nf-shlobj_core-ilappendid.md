# ILAppendID function

## Description

Appends or prepends an [SHITEMID](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-shitemid) structure to an [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure.

## Parameters

### `pidl` [in, optional]

Type: **PIDLIST_RELATIVE**

A pointer to an [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure. When the function returns, the [SHITEMID](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-shitemid) structure specified by *pmkid* is appended or prepended.

### `pmkid` [in]

Type: **LPSHITEMID**

A pointer to a [SHITEMID](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-shitemid) structure to be appended or prepended to *pidl*.

### `fAppend`

Type: **BOOL**

Value that is set to **TRUE** to append *pmkid* to *pidl*. Set this value to **FALSE** to prepend *pmkid* to *pidl*.

## Return value

Type: **PIDLIST_RELATIVE**

Returns the [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure specified by *pidl*, with *pmkid* appended or prepended. Returns **NULL** on failure.