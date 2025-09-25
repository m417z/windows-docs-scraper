# Header_SetFilterChangeTimeout macro

## Syntax

```cpp
int Header_SetFilterChangeTimeout(
   HWND hwnd,
   int  i
);
```

## Return value

Type: **int**

Returns the index of the filter control being modified.

## Description

Sets the timeout interval between the time a change takes place in the filter attributes and the posting of an [HDN_FILTERCHANGE](https://learn.microsoft.com/windows/desktop/Controls/hdn-filterchange) notification. You can use this macro or send the [HDM_SETFILTERCHANGETIMEOUT](https://learn.microsoft.com/windows/desktop/Controls/hdm-setfilterchangetimeout) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the header control.

### `i`

Type: **int**

The timeout value, in milliseconds.

## See also

[HDM_SETFILTERCHANGETIMEOUT](https://learn.microsoft.com/windows/desktop/Controls/hdm-setfilterchangetimeout)

[HDN_FILTERCHANGE](https://learn.microsoft.com/windows/desktop/Controls/hdn-filterchange)

**Reference**