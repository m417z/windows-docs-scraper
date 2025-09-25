# WinUsb_GetAdjustedFrameNumber function

## Description

The **WinUsb_GetAdjustedFrameNumber** function computes what the current USB frame number should be based on the frame number value and timestamp.

## Parameters

### `CurrentFrameNumber` [in, out]

The frame number to be adjusted.

### `TimeStamp` [in]

The timestamp recorded at the time the frame number was returned.

## Return value

**WinUsb_GetAdjustedFrameNumber** returns TRUE if the operation succeeds. Otherwise this function returns FALSE, and the caller can retrieve the logged error by calling **GetLastError**.

## See also

[Send USB isochronous transfers from a WinUSB desktop app](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[WinUSB Functions](https://learn.microsoft.com/windows/iot-core/learn-about-hardware/hardwarecompatlist)