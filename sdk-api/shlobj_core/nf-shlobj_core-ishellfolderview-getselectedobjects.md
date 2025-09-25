# IShellFolderView::GetSelectedObjects

## Description

[This method has been deprecated. Use [IFolderView2::GetSelection](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifolderview2-getselection) instead.]

Gets an array of the objects in the view that are selected and the number of those objects.

## Parameters

### `pppidl` [out]

Type: **PCUITEMID_CHILD****

The address of a pointer that, when this method returns successfully, points to an array of the currently selected items in the view. The calling application is expected to free the array at *pppidl* using [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree). The calling application must not free the individual items contained in the array.

### `puItems` [out]

Type: **UINT***

A pointer to a value that, when this method returns successfully, receives the number of items in the *pppidl* array.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method provides constant pointers to internal data structures. The calling application is expected to act on them immediately and not cache them.