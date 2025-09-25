# GetDpiForMonitor function

## Description

Queries the dots per inch (dpi) of a display.

## Parameters

### `hmonitor` [in]

Handle of the monitor being queried.

### `dpiType` [in]

The type of DPI being queried. Possible values are from the [MONITOR_DPI_TYPE](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/ne-shellscalingapi-monitor_dpi_type) enumeration.

### `dpiX` [out]

The value of the DPI along the X axis. This value always refers to the horizontal edge, even when the screen is rotated.

### `dpiY` [out]

The value of the DPI along the Y axis. This value always refers to the vertical edge, even when the screen is rotated.

## Return value

This function returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The function successfully returns the X and Y DPI values for the specified monitor. |
| **E_INVALIDARG** | The handle, DPI type, or pointers passed in are not valid. |

## Remarks

This API is not DPI aware and should not be used if the calling thread is per-monitor DPI aware. For the DPI-aware version of this API, see [GetDpiForWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdpiforwindow).

When you call **GetDpiForMonitor**, you will receive different DPI values depending on the DPI awareness of the calling application. DPI awareness is an application-level property usually defined in the application manifest. For more information about DPI awareness values, see [PROCESS_DPI_AWARENESS](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/ne-shellscalingapi-process_dpi_awareness). The following table indicates how the results will differ based on the **PROCESS_DPI_AWARENESS** value of your application.

|  |  |
| --- | --- |
| **PROCESS_DPI_UNAWARE** | 96 because the app is unaware of any other scale factors. |
| **PROCESS_SYSTEM_DPI_AWARE** | A value set to the system DPI because the app assumes all applications use the system DPI. |
| **PROCESS_PER_MONITOR_DPI_AWARE** | The actual DPI value set by the user for that display. |

The values of **dpiX* and **dpiY* are identical. You only need to record one of the values to determine the DPI and respond appropriately.

When [MONITOR_DPI_TYPE](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/ne-shellscalingapi-monitor_dpi_type) is **MDT_ANGULAR_DPI** or **MDT_RAW_DPI**, the returned DPI value does not include any changes that the user made to the DPI by using the desktop scaling override slider control in Control Panel.

For more information about DPI settings in Control Panel, see the [Writing DPI-Aware Desktop Applications in Windows 8.1 Preview](https://learn.microsoft.com/windows/win32/hidpi/high-dpi-desktop-application-development-on-windows) white paper.

## See also

[PROCESS_DPI_AWARENESS](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/ne-shellscalingapi-process_dpi_awareness)