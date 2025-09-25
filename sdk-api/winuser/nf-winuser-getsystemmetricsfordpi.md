# GetSystemMetricsForDpi function

## Description

Retrieves the specified system metric or system configuration setting taking into account a provided DPI.

## Parameters

### `nIndex` [in]

The system metric or configuration setting to be retrieved. See [GetSystemMetrics](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetrics) for the possible values.

### `dpi` [in]

The DPI to use for scaling the metric.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function returns the same result as [GetSystemMetrics](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetrics) but scales it according to an arbitrary DPI you provide if appropriate.