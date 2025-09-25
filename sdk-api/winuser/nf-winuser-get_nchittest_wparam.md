# GET_NCHITTEST_WPARAM macro

## Syntax

```cpp
short GET_NCHITTEST_WPARAM(
    WPARAM wParam
);
```

## Return value

Type: **short**

The return value is the low-order word representing the hit-test value. For a list of hit-test values, see [WM_NCHITTEST](https://learn.microsoft.com/windows/win32/inputdev/wm-nchittest).

## Description

Retrieves the hit-test value from the specified **WPARAM** value.

## Parameters

### `wParam`

The value to be converted.

## See also

[Mouse Input Overview](https://learn.microsoft.com/windows/desktop/inputdev/mouse-input)