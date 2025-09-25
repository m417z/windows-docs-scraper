# GET_KEYSTATE_WPARAM macro

## Syntax

```cpp
int GET_KEYSTATE_WPARAM(
    WPARAM wParam
);
```

## Return value

Type: **int**

The return value is the low-order word representing the virtual key state. It can be one of the following values:

| Return code | Value | Description |
|--|--|--|
| **MK_CONTROL** | 0x0008 | The CTRL key is down. |
| **MK_LBUTTON** | 0x0001 | The left mouse button is down. |
| **MK_MBUTTON** | 0x0010 | The middle mouse button is down. |
| **MK_RBUTTON** | 0x0002 | The right mouse button is down. |
| **MK_SHIFT** | 0x0004 | The SHIFT key is down. |
| **MK_XBUTTON1** | 0x0020 | The first X button is down. |
| **MK_XBUTTON2** | 0x0040 | The second X button is down. |

## Description

Retrieves the state of certain virtual keys from the specified **WPARAM** value.

## Parameters

### `wParam`

The value to be converted.

## See also

[Mouse Input Overview](https://learn.microsoft.com/windows/desktop/inputdev/mouse-input)