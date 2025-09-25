# TabCtrl_RemoveImage macro

## Syntax

```cpp
void TabCtrl_RemoveImage(
   HWND hwnd,
   int  i
);
```

## Description

Removes an image from a tab control's image list. You can use this macro or send the [TCM_REMOVEIMAGE](https://learn.microsoft.com/windows/desktop/Controls/tcm-removeimage) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tab control.

### `i`

Type: **int**

Index of the image to remove.

## Remarks

The tab control updates each tab's image index, so each tab remains associated with the same image as before. If a tab is using the image being removed, the tab will be set to have no image.