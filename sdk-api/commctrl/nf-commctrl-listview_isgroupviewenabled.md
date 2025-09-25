# ListView_IsGroupViewEnabled macro

## Syntax

```cpp
BOOL ListView_IsGroupViewEnabled(
   HWND hwnd
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if group view is enabled, or **FALSE** otherwise.

## Description

Checks whether the list-view control has group view
enabled. You can use this macro or send the [LVM_ISGROUPVIEWENABLED](https://learn.microsoft.com/windows/desktop/Controls/lvm-isgroupviewenabled) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

## Remarks

To use **ListView_IsGroupViewEnabled**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).