# ListView_SetHoverTime macro

## Syntax

```cpp
void ListView_SetHoverTime(
   HWND  hwndLV,
   DWORD dwHoverTimeMsMs
);
```

## Description

Sets the amount of time that the mouse cursor must hover over an item before it is selected. You can use this macro or send the [LVM_SETHOVERTIME](https://learn.microsoft.com/windows/desktop/Controls/lvm-sethovertime) message explicitly.

## Parameters

### `hwndLV`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to a list-view control.

### `dwHoverTimeMsMs`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The new amount of time, in milliseconds, that the mouse cursor must hover over an item before it is selected. If this value is (**DWORD**)-1, then the hover time is set to the default hover time.

## Remarks

The hover time only affects list-view controls that have the [LVS_EX_TRACKSELECT](https://learn.microsoft.com/windows/desktop/Controls/extended-list-view-styles), [LVS_EX_ONECLICKACTIVATE](https://learn.microsoft.com/windows/desktop/Controls/extended-list-view-styles), or [LVS_EX_TWOCLICKACTIVATE](https://learn.microsoft.com/windows/desktop/Controls/extended-list-view-styles) extended list-view style.