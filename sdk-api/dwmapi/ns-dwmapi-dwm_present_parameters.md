# DWM_PRESENT_PARAMETERS structure

## Description

Specifies Desktop Window Manager (DWM) video frame parameters for frame composition. Used by the [DwmSetPresentParameters](https://learn.microsoft.com/windows/desktop/api/dwmapi/nf-dwmapi-dwmsetpresentparameters) function.

## Members

### `cbSize`

The size of the **DWM_PRESENT_PARAMETERS** structure.

### `fQueue`

**TRUE** if the caller is requesting queued presents; otherwise, **FALSE**. If **TRUE**, the remaining parameters must be specified. If **FALSE**, queued presentation is disabled for this window and present behavior returns to the default behavior.

### `cRefreshStart`

A **ULONGLONG** value that provides the refresh number that the next presented frame should begin to display.

### `cBuffer`

The number of frames the application is instructing DWM to queue. The valid range is 2-8.

### `fUseSourceRate`

**TRUE** if the application wants DWM to schedule presentation based on source rate. **FALSE** if the application will decide how many refreshes to display for each frame. If **TRUE**, **rateSource** must be specified. If **FALSE**, **cRefreshesPerFrame** must be specified.

### `rateSource`

The rate, in frames per second, of the source material being displayed.

### `cRefreshesPerFrame`

The number of monitor refreshes through which each frame should be displayed on the screen.

### `eSampling`

The frame sampling type to use for composition.

## Remarks

The **rateSource** member is expressed as a ratio so that content (like that using NTSC standards, which has a rate of 60000/1001) can be accurately expressed. DWM determines how long to display each frame by resampling between the source rate and the composition rate in use each time the desktop is composed.