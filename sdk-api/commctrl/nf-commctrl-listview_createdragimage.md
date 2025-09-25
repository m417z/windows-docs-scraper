# ListView_CreateDragImage macro

## Syntax

```cpp
HIMAGELIST ListView_CreateDragImage(
   HWND    hwnd,
   int     i,
   LPPOINT lpptUpLeft
);
```

## Return value

Type: **HIMAGELIST**

Returns the handle to the drag image list if successful, or **NULL** otherwise.

## Description

Creates a drag image list for the specified item. You can use this macro or send the [LVM_CREATEDRAGIMAGE](https://learn.microsoft.com/windows/desktop/Controls/lvm-createdragimage) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `i`

Type: **int**

The index of the item.

### `lpptUpLeft`

Type: **LPPOINT**

A pointer to a [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure that receives the initial location of the upper-left corner of the image, in view coordinates.

## Remarks

Your application is responsible for destroying the image list when it is no longer needed.