# LASTINPUTINFO structure

## Description

Contains the time of the last input.

## Members

### `cbSize`

Type: **UINT**

The size of the structure, in bytes. This member must be set to `sizeof(LASTINPUTINFO)`.

### `dwTime`

Type: **DWORD**

The tick count when the last input event was received.

## Remarks

This function is useful for input idle detection. For more information on tick counts, see [GetTickCount](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-gettickcount).

## See also

**Conceptual**

[GetLastInputInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getlastinputinfo)

[GetTickCount](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-gettickcount)

[Keyboard Input](https://learn.microsoft.com/windows/desktop/inputdev/keyboard-input)

**Reference**