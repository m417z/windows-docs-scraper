# GET_X_LPARAM macro

## Syntax

```cpp
int GET_X_LPARAM(
    LPARAM lp
);
```

## Description

Retrieves the signed x-coordinate from the specified **LPARAM** value.

## Parameters

### `lp`

The data from which the x-coordinate is to be extracted.

## Return value

Type: **int**

X-coordinate.

## Remarks

Use **GET_X_LPARAM** instead of [LOWORD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms632659(v=vs.85)) to extract signed coordinate data. Negative screen coordinates may be returned on multiple monitor systems.

## See also

**Conceptual**

[GET_Y_LPARAM](https://learn.microsoft.com/windows/desktop/api/windowsx/nf-windowsx-get_y_lparam)

[LOWORD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms632659(v=vs.85))

**Reference**

[Windows Data Types](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)