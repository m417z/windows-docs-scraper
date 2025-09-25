# GET_Y_LPARAM macro

## Syntax

```cpp
int GET_Y_LPARAM(
    LPARAM lp
);
```

## Description

Retrieves the signed y-coordinate from the given **LPARAM** value.

## Parameters

### `lp`

The data from which the y-coordinate is to be extracted.

## Return value

Type: **int**

Y-coordinate.

## Remarks

Use **GET_Y_LPARAM** instead of [HIWORD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms632657(v=vs.85)) to extract signed coordinate data. Negative screen coordinates may be returned on multiple monitor systems.

## See also

**Conceptual**

[GET_X_LPARAM](https://learn.microsoft.com/windows/desktop/api/windowsx/nf-windowsx-get_x_lparam)

[HIWORD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms632657(v=vs.85))

**Reference**

[Windows Data Types](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)