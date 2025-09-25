# Header_SetImageList macro

## Syntax

```cpp
HIMAGELIST Header_SetImageList(
   HWND       hwnd,
   HIMAGELIST himl
);
```

## Return value

Type: **HIMAGELIST**

Returns the handle to the image list previously assigned to the header control, or **NULL** if there is no previous image list.

## Description

Assigns an image list to an existing header control. You can use this macro or send the [HDM_SETIMAGELIST](https://learn.microsoft.com/windows/desktop/Controls/hdm-setimagelist) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to a header control.

### `himl`

Type: **HIMAGELIST**

A handle to an image list.