# MCIWndSetRepeat macro

## Description

The **MCIWndSetRepeat** macro sets the repeat flag associated with continuous playback. You can use this macro or explicitly send the [MCIWNDM_SETREPEAT](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-setrepeat) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

### `f`

New state of the repeat flag. Specify **TRUE** to turn on continuous playback.

## Remarks

The **MCIWndSetRepeat** macro only affects playback that the user initiates by hitting the play button on the toolbar. It will not affect playback started with the **MCIWndPlay** macro.

Currently, MCIAVI is the only device that supports continuous playback.