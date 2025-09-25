# IRichEditOle::ActivateAs

## Description

Handles **Activate As** behavior by unloading all objects of the old class, telling OLE to treat those objects as objects of the new class, and reloading the objects. If objects cannot be reloaded, they are deleted.

## Parameters

### `rclsid`

Type: **REFCLSID**

Class identifier of the old class.

### `rclsidAs`

Type: **REFCLSID**

Class identifier of the new class.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK on success, or a failure code otherwise.

## See also

[IRichEditOle](https://learn.microsoft.com/windows/desktop/api/richole/nn-richole-iricheditole)