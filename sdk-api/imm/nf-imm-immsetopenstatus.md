# ImmSetOpenStatus function

## Description

Opens or closes the IME.

## Parameters

### `HIMC` [in]

Handle to the input context.

### `BOOL` [in]

**TRUE** if the IME is open, or **FALSE** if it is closed.

## Return value

Returns a nonzero value if successful, or 0 otherwise.

## Remarks

This function causes an [IMN_SETOPENSTATUS](https://learn.microsoft.com/windows/desktop/Intl/imn-setopenstatus) command to be sent to the application.

## See also

[IMN_SETOPENSTATUS](https://learn.microsoft.com/windows/desktop/Intl/imn-setopenstatus)

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Functions](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-functions)