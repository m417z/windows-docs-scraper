# GetKeyboardType function

## Description

Retrieves information about the current keyboard.

## Parameters

### `nTypeFlag` [in]

Type: **int**

The type of keyboard information to be retrieved. This parameter can be one of the following values.

| Value | Meaning |
|:-----:|---------------------------------------------|
| 0 | Keyboard type |
| 1 | Keyboard subtype |
| 2 | The number of function keys on the keyboard |

## Return value

Type: **int**

If the function succeeds, the return value specifies the requested information.

If the function fails and *nTypeFlag* is not 1, the return value is 0; 0 is a valid return value when *nTypeFlag* is 1 (keyboard subtype). To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Valid keyboard types are:

| Value | Description |
|:-----:|------------------------------------------------------|
| 0x4 | Enhanced 101- or 102-key keyboards (and compatibles) |
| 0x7 | Japanese Keyboard |
| 0x8 | Korean Keyboard |
| 0x51 | Unknown type or HID keyboard |

Keyboard subtypes are original equipment manufacturer (OEM)-dependent values.

## See also

[Keyboard Input Functions](https://learn.microsoft.com/windows/desktop/inputdev/keyboard-input-functions)