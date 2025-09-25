# AreDpiAwarenessContextsEqual function

## Description

Determines whether two **DPI_AWARENESS_CONTEXT** values are identical.

## Parameters

### `dpiContextA` [in]

The first value to compare.

### `dpiContextB` [in]

The second value to compare.

## Return value

Returns **TRUE** if the values are equal, otherwise **FALSE**.

## Remarks

A **DPI_AWARENESS_CONTEXT** contains multiple pieces of information. For example, it includes both the current and the inherited [DPI_AWARENESS](https://learn.microsoft.com/windows/desktop/api/windef/ne-windef-dpi_awareness) values. **AreDpiAwarenessContextsEqual** ignores informational flags and determines if the values are equal. You can't use a direct bitwise comparison because of these informational flags.