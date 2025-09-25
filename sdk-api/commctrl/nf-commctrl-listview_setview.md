# ListView_SetView macro

## Syntax

```cpp
DWORD ListView_SetView(
   HWND  hwnd,
   DWORD iView
);
```

## Return value

Type: **DWORD**

Returns 1 if successful, or UINT_MAX otherwise. For example, returns UINT_MAX if the view is invalid.

## Description

Sets the view of a list-view control. You can use this macro or send the [LVM_SETVIEW](https://learn.microsoft.com/windows/desktop/Controls/lvm-setview) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `iView`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**DWORD**
[LVM_SETVIEW](https://learn.microsoft.com/windows/desktop/Controls/lvm-setview)

## Remarks

To use **ListView_SetView**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).