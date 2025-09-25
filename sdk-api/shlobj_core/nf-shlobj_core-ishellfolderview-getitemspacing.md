# IShellFolderView::GetItemSpacing

## Description

[This method has been deprecated. Use [IFolderView::GetSpacing](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifolderview-getspacing) instead.]

Gets the spacing for small and large view modes only.

## Parameters

### `pSpacing` [out]

Type: **[ITEMSPACING](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-itemspacing)***

A pointer to a structure that, when this method returns successfully, receives the information that describes the view mode spacing.

## Return value

Type: **HRESULT**

Returns **S_OK** if the current view mode is positionable; otherwise, **S_FALSE**.

## Remarks

This method sends an [LVM_GETITEMSPACING](https://learn.microsoft.com/windows/desktop/Controls/lvm-getitemspacing) message to get the view mode spacing.

This method retrieves mode spacing for only the large and small view modes.

In Windows Vista and later, this method stores the small view mode spacing in both pairs of values returned in the [ITEMSPACING](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-itemspacing) structure.