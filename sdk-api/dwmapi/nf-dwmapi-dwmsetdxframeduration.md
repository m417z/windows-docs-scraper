# DwmSetDxFrameDuration function

## Description

Sets the number of monitor refreshes through which to display the presented frame.

**DwmSetDxFrameDuration** is no longer supported. Starting with Windows 8.1, calls to **DwmSetDxFrameDuration** always return E_NOTIMPL.

## Parameters

### `hwnd` [in]

The handle to the window that displays the presented frame.

### `cRefreshes` [in]

The number of refreshes through which to display the presented frame.

## Return value

This function always returns S_OK, even when the frame duration is not changed or DWM is not running.

## Remarks

The DWM will attempt to display the presented frame for at least the number of monitor refreshes specified. It might be impossible to display the frame for the precise number of refreshes due to the current composition rate. If the frame is presented late to the DWM or the DWM is late in composing, a frame could be displayed for fewer than the number of refreshes requested or even skipped completely.