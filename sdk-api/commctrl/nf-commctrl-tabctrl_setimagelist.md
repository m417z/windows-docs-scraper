# TabCtrl_SetImageList macro

## Syntax

```cpp
BOOL TabCtrl_SetImageList(
   HWND       hwnd,
   HIMAGELIST himl
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the handle to the previous image list, or **NULL** if there is no previous image list.

## Description

Assigns an image list to a tab control. You can use this macro or send the [TCM_SETIMAGELIST](https://learn.microsoft.com/windows/desktop/Controls/tcm-setimagelist) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tab control.

### `himl`

Type: **HIMAGELIST**

Handle to the image list to assign to the tab control.