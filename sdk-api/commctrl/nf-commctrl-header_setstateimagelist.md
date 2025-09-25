# Header_SetStateImageList macro

## Syntax

```cpp
BOOL Header_SetStateImageList(
   HWND       hwnd,
   HIMAGELIST himl
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the handle to the image list previously assigned to the header control state, or **NULL** if there is no previous image list.

## Description

Assigns an image list to an existing header control state.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to a header control.

### `himl`

Type: **HIMAGELIST**

A handle to an image list control.