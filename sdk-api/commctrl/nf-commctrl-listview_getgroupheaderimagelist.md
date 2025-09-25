# ListView_GetGroupHeaderImageList macro

## Syntax

```cpp
HIMAGELIST ListView_GetGroupHeaderImageList(
  [in] HWND hwnd
);
```

## Return value

Type: **HIMAGELIST**

Returns the handle to the group header image list if successful, or **NULL** otherwise.

## Description

Gets the group header image list that has been set for an existing list-view control.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

## Remarks

To specify an image list another way, such as, by large icons, small icons, or state images, send the [LVM_GETIMAGELIST](https://learn.microsoft.com/windows/desktop/Controls/lvm-getimagelist) message explicitly.