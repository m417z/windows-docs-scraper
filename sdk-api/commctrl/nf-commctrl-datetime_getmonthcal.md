# DateTime_GetMonthCal macro

## Syntax

```cpp
HWND DateTime_GetMonthCal(
   HWND hdp
);
```

## Return value

Type: **[HWND](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the handle to a DTP control's child month calendar control.

## Description

Gets the handle to a date and time picker's (DTP) child month calendar control. You can use this macro or send the [DTM_GETMONTHCAL](https://learn.microsoft.com/windows/desktop/Controls/dtm-getmonthcal) message explicitly.

## Parameters

### `hdp`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to a DTP control.

## Remarks

DTP controls create a child month calendar control when the user clicks the drop-down arrow ([DTN_DROPDOWN](https://learn.microsoft.com/windows/desktop/Controls/dtn-dropdown) notification). When the month calendar is no longer needed, it is destroyed (a [DTN_CLOSEUP](https://learn.microsoft.com/windows/desktop/Controls/dtn-closeup) notification is sent on destruction). So your application must not rely on a static handle to the DTP's child month calendar.

## See also

[DTN_CLOSEUP](https://learn.microsoft.com/windows/desktop/Controls/dtn-closeup)

[DTN_DROPDOWN](https://learn.microsoft.com/windows/desktop/Controls/dtn-dropdown)

**Reference**