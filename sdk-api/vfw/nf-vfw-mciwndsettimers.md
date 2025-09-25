# MCIWndSetTimers macro

## Description

The **MCIWndSetTimers** macro sets the update periods used by MCIWnd to update the trackbar in the MCIWnd window, update the position information displayed in the window title bar, and send notification messages to the parent window. You can use this macro or explicitly send the [MCIWNDM_SETTIMERS](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-settimers) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

### `active`

Update period used by MCIWnd when it is the active window. The default value is 500 milliseconds. Storage for this value is limited to 16 bits.

### `inactive`

Update period used by MCIWnd when it is the inactive window. The default value is 2000 milliseconds. Storage for this value is limited to 16 bits.