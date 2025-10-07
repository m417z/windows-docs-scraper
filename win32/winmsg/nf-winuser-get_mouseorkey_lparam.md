# GET_MOUSEORKEY_LPARAM macro

Retrieves the input device type from the specified **LPARAM** value.

### `lParam`

The value to be converted.

## Return value

The return value is the bit of the high-order word representing the input device type. It can be one of the following values.

| Return code/value | Description |
| --- | --- |
| **FAPPCOMMAND_KEY** 0 | User pressed a key. |
| **FAPPCOMMAND_MOUSE** 0x8000 | User clicked a mouse button. |
| **FAPPCOMMAND_OEM** 0x1000 | An unidentified hardware source generated the event. It could be a mouse or a keyboard event. |

## Remarks

This macro is identical to the [GET_DEVICE_LPARAM macro](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-get_device_lparam) macro.

## See also

[GET_DEVICE_LPARAM macro](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-get_device_lparam), [Mouse Input](https://learn.microsoft.com/windows/win32/inputdev/mouse-input)