# DateTime_CloseMonthCal macro

## Syntax

```cpp
LRESULT DateTime_CloseMonthCal(
   HWND hdp
);
```

## Return value

Type: **[LRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns zero.

## Description

Closes the date and time picker (DTP) control. Use this macro or send the [DTM_CLOSEMONTHCAL](https://learn.microsoft.com/windows/desktop/Controls/dtm-closemonthcal) message explicitly.

## Parameters

### `hdp`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the DTP control.

## Remarks

Destroys the control and sends a [DTN_CLOSEUP](https://learn.microsoft.com/windows/desktop/Controls/dtn-closeup) notification that the control is closing—as opposed to the control is opening (dropping-down as in the [DTN_DROPDOWN](https://learn.microsoft.com/windows/desktop/Controls/dtn-dropdown) notification)—to the control's parent.

## See also

[DTN_CLOSEUP](https://learn.microsoft.com/windows/desktop/Controls/dtn-closeup)

[DTN_DROPDOWN](https://learn.microsoft.com/windows/desktop/Controls/dtn-dropdown)

**Reference**