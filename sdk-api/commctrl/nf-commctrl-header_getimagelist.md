# Header_GetImageList macro

## Syntax

```cpp
HIMAGELIST Header_GetImageList(
   HWND hwnd
);
```

## Return value

Type: **HIMAGELIST**

Returns the handle to the image list that is set for the header control.

## Description

Gets the handle to the image list that has been set for an existing header control. You can use this macro or send the [HDM_GETIMAGELIST](https://learn.microsoft.com/windows/desktop/Controls/hdm-getimagelist) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to a header control.