# GET_WHEEL_DELTA_WPARAM macro

## Syntax

```cpp
short GET_WHEEL_DELTA_WPARAM(
    WPARAM wParam
);
```

## Return value

Type: **short**

The return value is the high-order word representing the wheel-delta value. It indicates the distance that the wheel is rotated, expressed in multiples or divisions of WHEEL_DELTA, which is 120. A positive value indicates that the wheel was rotated forward, away from the user; a negative value indicates that the wheel was rotated backward, toward the user.

## Description

Retrieves the wheel-delta value from the specified **WPARAM** value.

## Parameters

### `wParam`

The value to be converted.

## See also

[Mouse Input Overview](https://learn.microsoft.com/windows/desktop/inputdev/mouse-input)