# INameSpaceTreeControl::HitTest

## Description

Retrieves the item that a given point is in, if any.

## Parameters

### `ppt` [in]

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)***

A pointer to the point to be tested.

### `ppsiOut` [out]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)****

The address of a pointer to the item in which the point exists, or **NULL** if the point does not exist in an item.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function returns **S_FALSE** with a **NULL** item if the point does not exist in an item.