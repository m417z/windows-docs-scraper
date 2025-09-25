# Header_ClearFilter macro

## Syntax

```cpp
int Header_ClearFilter(
   HWND hwnd,
   int  i
);
```

## Return value

Type: **int**

Returns an integer that indicates **TRUE**(1) or **FALSE**(0).

## Description

Clears the filter for a given header control. You can use this macro or send the [HDM_CLEARFILTER](https://learn.microsoft.com/windows/desktop/Controls/hdm-clearfilter) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the header control.

### `i`

Type: **int**

A value specifying the column of the filter to be cleared. Specifying -1 will clear all of the filters.

## Remarks

If the column value is specified as -1, all the filters will be cleared and the [HDN_FILTERCHANGE](https://learn.microsoft.com/windows/desktop/Controls/hdn-filterchange) notification will be sent only once.

## See also

[Header_ClearAllFilters](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-header_clearallfilters)