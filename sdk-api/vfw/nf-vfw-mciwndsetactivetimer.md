# MCIWndSetActiveTimer macro

## Description

The **MCIWndSetActiveTimer** macro sets the update period used by MCIWnd to update the trackbar in the MCIWnd window, update position information displayed in the window title bar, and send notification messages to the parent window when the MCIWnd window is active. You can use this macro or explicitly send the [MCIWNDM_SETACTIVETIMER](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-setactivetimer) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

### `active`

Update period, in milliseconds. The default is 500 milliseconds.