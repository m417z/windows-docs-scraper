# ComboBox_SetMinVisible macro

## Syntax

```cpp
BOOL ComboBox_SetMinVisible(
   HWND hwnd,
   INT  iMinVisible
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

If the macro succeeds, it returns **TRUE**. Otherwise it returns **FALSE**.

## Description

Sets the minimum number of visible items in the drop-down list of a combo box.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The combo box.

### `iMinVisible`

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The minimum number of visible items.

## Remarks

When the number of items in the drop-down list is greater than the minimum, the combo box uses a scroll bar. By default, 30 is the minimum number of visible items.

`Combobox_SetMinVisible (hwnd, iMinVisible)`

is equivalent to the following call.

`SendMessage((hwnd), CB_SETMINVISIBLE, (WPARAM) iMinVisible, 0);`

To use **ComboBox_SetMinVisible**, the application must specify comctl32.dll version 6 in the manifest. For more information, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).

## See also

[CB_SETMINVISIBLE](https://learn.microsoft.com/windows/desktop/Controls/cb-setminvisible)