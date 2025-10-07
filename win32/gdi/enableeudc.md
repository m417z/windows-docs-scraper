# EnableEUDC function

This function enables or disables support for end-user-defined characters (EUDC).

## Parameters

*fEnableEUDC* \[in\]

Boolean that is set to **TRUE** to enable EUDC, and to **FALSE** to disable EUDC.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

If EUDC is disabled, trying to display EUDC characters will result in missing or bad glyphs.

During multi-session, this function affects the current session only.

It is recommended that you use this function with Windows XP SP2 or later.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Library<br> | Gdi32.lib |
| DLL<br> | Gdi32.dll |

