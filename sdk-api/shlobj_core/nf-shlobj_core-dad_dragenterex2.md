# DAD_DragEnterEx2 function

## Description

[**DAD_DragEnterEx2** is available in Windows 2000 and Windows XP. It might be altered or unavailable in subsequent versions. Use [ImageList_DragEnter](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-imagelist_dragenter) instead.]

Locks updates to the specified window during a drag-and-drop operation and displays the drag image at the specified position within the window.

## Parameters

### `hwndTarget` [in]

Type: **HWND**

A handle to the window that owns the drag image.

### `ptStart`

Type: **const [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

Specifies the coordinates at which to begin displaying the drag image. The coordinates are relative to the upper-left corner of the window, not the client area.

### `pdtObject` [in, optional]

Type: **[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)***

A pointer to the [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface on the data object. This data object contains the data being transferred in the drag-and-drop operation. If the drop occurs, this data object will be incorporated into the target. This parameter may be **NULL**.

## Return value

Type: **BOOL**

Returns **TRUE** if successful, **FALSE** otherwise.

## See also

[DAD_DragEnterEx](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-dad_dragenterex)

[ImageList_DragEnter](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-imagelist_dragenter)