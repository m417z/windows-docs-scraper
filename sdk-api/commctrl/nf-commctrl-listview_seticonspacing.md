# ListView_SetIconSpacing macro

## Syntax

```cpp
DWORD ListView_SetIconSpacing(
   HWND hwndLV,
   int  cx,
   int  cy
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns a **DWORD** value that contains the previous

## Description

Sets the spacing between icons in list-view controls set to the [LVS_ICON](https://learn.microsoft.com/windows/desktop/Controls/list-view-window-styles) style. You can use this macro or send the [LVM_SETICONSPACING](https://learn.microsoft.com/windows/desktop/Controls/lvm-seticonspacing) message explicitly.

## Parameters

### `hwndLV`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to a list-view control.

### `cx`

Type: **int**

The distance, in pixels, to set between icons on the x-axis.

### `cy`

Type: **int**

The distance, in pixels, to set between icons on the y-axis.

## Remarks

The
*cx* and *cy* parameters are relative to the upper-left corner of an icon bitmap. Therefore, to set spacing between icons that do not overlap, the *cx* or *cy* values must include the size of the icon, plus the amount of empty space desired between icons. Values that do not include the width of the icon will result in overlaps.

When defining the icon spacing, *cx* and *cy* must set to 4 or larger. Smaller values will not yield the desired layout. You can reset *cx* and *cy* to the default spacing by setting both values to -1. This approach only allows you to reset both default settings. You cannot reset only *cx* or *cy* to the default setting by setting one of them to -1.