# MCIWndValidateMedia macro

## Description

The **MCIWndValidateMedia** macro updates the starting and ending locations of the content, the current position in the content, and the trackbar according to the current time format. You can use this macro or explicitly send the [MCIWNDM_VALIDATEMEDIA](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-validatemedia) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

## Remarks

Typically, you should not need to use this macro; however, if your application changes the time format of a device without using MCIWnd; the starting and ending locations of the content, as well as the trackbar, continue to use the old format. You can use this macro to update these values.