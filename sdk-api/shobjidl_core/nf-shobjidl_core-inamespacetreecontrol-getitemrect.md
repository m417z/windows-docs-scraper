# INameSpaceTreeControl::GetItemRect

## Description

Gets the [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that describes the size and position of a given item.

## Parameters

### `psi` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

A pointer to the item for which the [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure is being retrieved.

### `prect` [out]

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

A pointer to the [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that describes the size and position of the item.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.