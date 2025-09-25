# ImmSetStatusWindowPos function

## Description

Sets the position of the status window.

## Parameters

### `HIMC` [in]

Handle to the input context.

### `lpptPos` [in]

Pointer to a [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure containing the new position of the status window, in screen coordinates relative to the upper left corner of the display screen.

## Return value

Returns a nonzero value if successful, or 0 otherwise.

## Remarks

This function causes an [IMN_SETSTATUSWINDOWPOS](https://learn.microsoft.com/windows/desktop/Intl/imn-setstatuswindowpos) command to be sent to the application.

## See also

[IMN_SETSTATUSWINDOWPOS](https://learn.microsoft.com/windows/desktop/Intl/imn-setstatuswindowpos)

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Functions](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-functions)