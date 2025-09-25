# GET_DEVICE_LPARAM macro

## Syntax

```cpp
WORD GET_DEVICE_LPARAM(
    LPARAM lParam
);
```

## Description

Retrieves the input device type from the specified **LPARAM** value.

## Parameters

### `lParam`

The value to be converted.

## Return value

Type: **WORD**

The return value is the bit of the high-order word representing the input device type. It can be one of the following values.

| Return code | Value | Description |
|--|--|--|
| **FAPPCOMMAND_KEY** | 0 | User pressed a key. |
| **FAPPCOMMAND_MOUSE** | 0x8000 | User clicked a mouse button. |
| **FAPPCOMMAND_OEM** | 0x1000 | An unidentified hardware source generated the event. It could be a mouse or a keyboard event. |

## Remarks

This macro is identical to the [GET_MOUSEORKEY_LPARAM macro](https://learn.microsoft.com/windows/win32/winmsg/nf-winuser-get_mouseorkey_lparam).

## See also

[GET_MOUSEORKEY_LPARAM macro](https://learn.microsoft.com/windows/win32/winmsg/nf-winuser-get_mouseorkey_lparam), [Mouse Input](https://learn.microsoft.com/windows/win32/inputdev/mouse-input)