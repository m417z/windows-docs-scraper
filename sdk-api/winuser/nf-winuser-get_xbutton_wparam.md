# GET_XBUTTON_WPARAM macro

## Syntax

```cpp
int GET_XBUTTON_WPARAM(
    WPARAM wParam
);
```

## Return value

Type: **int**

The high-order word indicates which button was released. It can be either of the following values:

| Return code | Value | Description |
|--|--|--|
| **XBUTTON1** | 0x0001 | The first X button was released. |
| **XBUTTON2** | 0x0002 | The second X button was released. |

## Description

Retrieves the state of certain buttons from the specified **WPARAM** value.

## Parameters

### `wParam`

The value to be converted.

## See also

[Mouse Input Overview](https://learn.microsoft.com/windows/desktop/inputdev/mouse-input)