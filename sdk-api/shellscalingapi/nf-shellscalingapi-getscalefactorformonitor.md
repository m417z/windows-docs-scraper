# GetScaleFactorForMonitor function

## Description

Gets the scale factor of a specific monitor. This function replaces [GetScaleFactorForDevice](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/nf-shellscalingapi-getscalefactorfordevice).

## Parameters

### `hMon` [in]

The monitor's handle.

### `pScale` [out]

When this function returns successfully, this value points to one of the [DEVICE_SCALE_FACTOR](https://learn.microsoft.com/windows/desktop/api/shtypes/ne-shtypes-device_scale_factor) values that specify the scale factor of the specified monitor.

If the function call fails, this value points to a valid scale factor so that apps can opt to continue on with incorrectly sized resources.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Your code needs to handle the [WM_WINDOWPOSCHANGED](https://learn.microsoft.com/windows/desktop/winmsg/wm-windowposchanged) message in addition to the scale change event registered through [RegisterScaleChangeEvent](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/nf-shellscalingapi-registerscalechangeevent), because the app window can be moved between monitors. In response to the **WM_WINDOWPOSCHANGED** message, call [MonitorFromWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-monitorfromwindow), followed by **GetScaleFactorForMonitor** to get the scale factor of the monitor which the app window is on. Your code can then react to any dots per inch (dpi) change by reloading assets and changing layout.

## See also

[RegisterScaleChangeEvent](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/nf-shellscalingapi-registerscalechangeevent)

[UnregisterScaleChangeEvent](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/nf-shellscalingapi-unregisterscalechangeevent)