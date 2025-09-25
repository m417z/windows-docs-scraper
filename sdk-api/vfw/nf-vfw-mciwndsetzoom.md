# MCIWndSetZoom macro

## Description

The **MCIWndSetZoom** macro resizes a video image according to a zoom factor. This marco adjusts the size of an MCIWnd window while maintaining a constant aspect ratio. You can use this macro or explicitly send the [MCIWNDM_SETZOOM](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-setzoom) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

### `iZoom`

Zoom factor expressed as a percentage of the original image. Specify 100 to display the image at its authored size, 200 to display the image at twice its normal size, or 50 to display the image at half its normal size.