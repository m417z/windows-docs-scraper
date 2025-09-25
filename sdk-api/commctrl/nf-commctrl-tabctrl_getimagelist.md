# TabCtrl_GetImageList macro

## Syntax

```cpp
HIMAGELIST TabCtrl_GetImageList(
   HWND hwnd
);
```

## Return value

Type: **HIMAGELIST**

Returns the handle to the image list if successful, or **NULL** otherwise.

## Description

Retrieves the image list associated with a tab control. You can use this macro or send the [TCM_GETIMAGELIST](https://learn.microsoft.com/windows/desktop/Controls/tcm-getimagelist) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tab control.