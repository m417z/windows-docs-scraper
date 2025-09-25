# Header_CreateDragImage macro

## Syntax

```cpp
HIMAGELIST Header_CreateDragImage(
   HWND hwnd,
   int  i
);
```

## Return value

Type: **HIMAGELIST**

Returns a handle to an image list that contains the new image as its only element.

## Description

Creates a transparent version of an item image within an existing header control. You can use this macro or send the [HDM_CREATEDRAGIMAGE](https://learn.microsoft.com/windows/desktop/Controls/hdm-createdragimage) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to a header control.

### `i`

Type: **int**

A zero-based index of the item within the header control. The image assigned to this item is used as the basis for the transparent image.