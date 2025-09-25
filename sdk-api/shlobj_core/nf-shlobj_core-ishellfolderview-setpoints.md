# IShellFolderView::SetPoints

## Description

[**SetPoints** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Copies the points at which the current selection is located into a data object.

## Parameters

### `pDataObject` [in]

Type: **[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)***

A pointer to the data object. This data object contains the points of location of the current selection. These points are given in coordinates relative to the ListView control that the view contains. These points can be used for positioning the object at the end of a drag-and-drop operation.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This call is not needed if the drag-and-drop operation was originated by [IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview).