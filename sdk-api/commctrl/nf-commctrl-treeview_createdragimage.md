# TreeView_CreateDragImage macro

## Syntax

```cpp
HIMAGELIST TreeView_CreateDragImage(
   HWND      hwnd,
   HTREEITEM hitem
);
```

## Return value

Type: **HIMAGELIST**

Returns the handle to the image list to which the dragging bitmap was added if successful, or **NULL** otherwise.

## Description

Creates a dragging bitmap for the specified item in a tree-view control. The macro also creates an image list for the bitmap and adds the bitmap to the image list. An application can display the image when dragging the item by using the image list functions. You can use this macro or send the [TVM_CREATEDRAGIMAGE](https://learn.microsoft.com/windows/desktop/Controls/tvm-createdragimage) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tree-view control.

### `hitem`

Type: **HTREEITEM**

Handle to the item that receives the new dragging bitmap.

## Remarks

If you create a tree-view control without an associated image list, you cannot use the **TreeView_CreateDragImage** macro to create the image to display during a drag operation. You must implement your own method of creating a drag cursor.

Your application is responsible for destroying the image list when it is no longer needed.