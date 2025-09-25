# WinUsb_GetCurrentFrameNumber function

## Description

The **WinUsb_GetCurrentFrameNumber** function gets the current frame number for the bus.

## Parameters

### `InterfaceHandle` [in]

The handle to the device that **CreateFile** returned.

### `CurrentFrameNumber` [out]

The current frame number value.

### `TimeStamp` [out]

The time stamp value when the current frame was read.

## Return value

**WinUsb_GetCurrentFrameNumber** returns TRUE if the operation succeeds. Otherwise this function returns FALSE, and the caller can retrieve the logged error by calling **GetLastError**.

## Remarks

The caller may compare the PerformanceCount with the value returned by the Win32 function [QueryPerformanceCounter](https://learn.microsoft.com/windows/desktop/api/profileapi/nf-profileapi-queryperformancecounter) to determine if there has been a delay in transitioning back to user-mode after the frame number was read. The caller can then adjust the starting frame number as needed.

## See also

[Send USB isochronous transfers from a WinUSB desktop app](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[WinUSB Functions](https://learn.microsoft.com/windows/iot-core/learn-about-hardware/hardwarecompatlist)