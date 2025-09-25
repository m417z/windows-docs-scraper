# DATETIMEPICKERINFO structure

## Description

Contains information about a date and time picker (DTP) control.

## Members

### `cbSize`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Set to `sizeof(DATETIMEPICKERINFO)`. This member must be set before sending a pointer to this structure with the [DTM_GETDATETIMEPICKERINFO](https://learn.microsoft.com/windows/desktop/Controls/dtm-getdatetimepickerinfo) message, or the [DateTime_GetDateTimePickerInfo](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-datetime_getdatetimepickerinfo) macro.

### `rcCheck`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

A [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure describing location of checkbox. If a checkbox is displayed and checked, an edit control should be available to update the selected date-time value.

### `stateCheck`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The state of **rcCheck**—one of the [Object State Constants](https://learn.microsoft.com/windows/desktop/WinAuto/object-state-constants), such as **STATE_SYSTEM_CHECKED** or **STATE_SYSTEM_INVISIBLE**.

### `rcButton`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

A [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure describing the location of a drop-down grid or up/down control.

### `stateButton`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The state of **rcButton**— one or a bitwise combination of the [Object State Constants](https://learn.microsoft.com/windows/desktop/WinAuto/object-state-constants), such as **STATE_SYSTEM_UNAVAILABLE**, **STATE_SYSTEM_INVISIBLE**, or **STATE_SYSTEM_PRESSED**. If the up/down control is in use, the state of the button is **STATE_SYSTEM_INVISIBLE**.

### `hwndEdit`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the edit control. For information see, [Edit Controls](https://learn.microsoft.com/windows/desktop/Controls/edit-controls).

### `hwndUD`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the up/down control—an alternative to using the drop-down grid (looks like month calendar control). For more information, see [Up-Down Controls](https://learn.microsoft.com/windows/desktop/Controls/up-down-controls).

### `hwndDropDown`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the drop-down grid.