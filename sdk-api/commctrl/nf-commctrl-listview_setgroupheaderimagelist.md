# ListView_SetGroupHeaderImageList macro

## Syntax

```cpp
HIMAGELIST ListView_SetGroupHeaderImageList(
  [in] HWND hwnd,
  [in] HIML himl
);
```

## Return value

Type: **HIMAGELIST**

Returns the handle to the group header image list previously associated with the control if successful, or **NULL** otherwise.

## Description

Assigns an image list to the group header of a list-view control.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `himl` [in]

Type: **HIML**

A handle to the image list.

## Remarks

The current image list will be destroyed when the list-view control is destroyed unless the [LVS_SHAREIMAGELISTS](https://learn.microsoft.com/windows/desktop/Controls/list-view-window-styles) style is set. If you use this message to replace one image list with another, your application must explicitly destroy all image lists other than the current one.