# ComboBox_GetMinVisible macro

## Syntax

```cpp
INT ComboBox_GetMinVisible(
   HWND hwnd
);
```

## Return value

Type: **[INT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

The return value is the minimum number of visible items.

## Description

Gets the minimum number of visible items in the drop-down list of a combo box.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the combo box.

## Remarks

When the number of items in the drop-down list is greater than the minimum, the combo box uses a scroll bar.

To use **ComboBox_GetMinVisible**, the application must specify comctl32.dll version 6 in the manifest. For more information, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).

## See also

[CB_GETMINVISIBLE](https://learn.microsoft.com/windows/desktop/Controls/cb-getminvisible)