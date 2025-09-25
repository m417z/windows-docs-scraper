# Header_ClearAllFilters macro

## Syntax

```cpp
int Header_ClearAllFilters(
   HWND hwnd
);
```

## Return value

Type: **int**

Returns an integer that indicates **TRUE**(1) or **FALSE**(0).

## Description

Clears all of the filters for a given header control. You can use this macro or send the [HDM_CLEARFILTER](https://learn.microsoft.com/windows/desktop/Controls/hdm-clearfilter) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the header control.

## Remarks

When all the filters are cleared, the [HDN_FILTERCHANGE](https://learn.microsoft.com/windows/desktop/Controls/hdn-filterchange) notification will be sent only once.

## See also

[Header_ClearFilter](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-header_clearfilter)