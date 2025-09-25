# ImmGetStatusWindowPos function

## Description

Retrieves the position of the status window.

## Parameters

### `HIMC` [in]

Handle to the input context.

### `lpptPos` [out]

Pointer to a [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure in which the function retrieves the position coordinates. These are screen coordinates, relative to the upper left corner of the screen.

## Return value

Returns a nonzero value if successful, or 0 otherwise.

## See also

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Functions](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-functions)