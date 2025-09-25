# WINNLSEnableIME function

## Description

Temporarily enables or disables an Input Method Editor (IME) and, at the same time, turns on or off the display of all windows owned by the IME.

**Note** This function is obsolete and should not be used.

## Parameters

### `HWND` [in]

Must be **NULL**. Specifying a particular IME for each application is not supported.

### `BOOL` [in]

**TRUE** to enable the IME; **FALSE** to disable.

## Return value

The previous state of the IME. **TRUE** if it was enabled before this call, otherwise, **FALSE**.

## Remarks

The terms "enabled" and "disabled" in regard to this function are defined as follows:

If an IME is disabled, [IME_WINDOWUPDATE(FALSE)](https://learn.microsoft.com/windows/desktop/api/ime/ns-ime-imestruct) is issued to the IME, which responds by deleting the conversion and system windows. With the IME disabled, keyboard messages are not sent to the IME, but are sent directly to the application. Even if the IME is disabled, the API that uses the [SendIMEMessageEx](https://learn.microsoft.com/windows/desktop/api/ime/nf-ime-sendimemessageexa) function is still valid.

If an IME is enabled, [IME_WINDOWUPDATE(TRUE)](https://learn.microsoft.com/windows/desktop/api/ime/ns-ime-imestruct) is issued to the IME, which responds by redisplaying the conversion and system windows. With the IME enabled, keyboard messages are sent to the IME.