# ImmGetDefaultIMEWnd function

## Description

Retrieves the default window handle to the IME class.

## Parameters

### `HWND` [in]

Handle to the window.

## Return value

Returns the default window handle to the IME class if successful, or **NULL** otherwise.

## Remarks

The operating system creates a default IME window for every thread. The window is created based on the IME class. The application can send the [WM_IME_CONTROL](https://learn.microsoft.com/windows/desktop/Intl/wm-ime-control) message to this window.

## See also

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Functions](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-functions)

[WM_IME_CONTROL](https://learn.microsoft.com/windows/desktop/Intl/wm-ime-control)