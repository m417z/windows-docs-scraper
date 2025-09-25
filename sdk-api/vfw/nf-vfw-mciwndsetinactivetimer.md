# MCIWndSetInactiveTimer macro

## Description

The **MCIWndSetInactiveTimer** macro sets the update period used by MCIWnd to update the trackbar in the MCIWnd window, update position information displayed in the window title bar, and send notification messages to the parent window when the MCIWnd window is inactive. You can use this macro or explicitly send the [MCIWNDM_SETINACTIVETIMER](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-setinactivetimer) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

### `inactive`

Update period, in milliseconds. The default is 2000 milliseconds.