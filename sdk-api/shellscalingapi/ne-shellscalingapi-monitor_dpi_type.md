# MONITOR_DPI_TYPE enumeration

## Description

Identifies the dots per inch (dpi) setting for a monitor.

## Constants

### `MDT_EFFECTIVE_DPI:0`

The effective DPI. This value should be used when determining the correct scale factor for scaling UI elements. This incorporates the scale factor set by the user for this specific display.

### `MDT_ANGULAR_DPI:1`

The angular DPI. This DPI ensures rendering at a compliant angular resolution on the screen. This does not include the scale factor set by the user for this specific display.

### `MDT_RAW_DPI:2`

The raw DPI. This value is the linear DPI of the screen as measured on the screen itself. Use this value when you want to read the pixel density and not the recommended scaling setting. This does not include the scale factor set by the user for this specific display and is not guaranteed to be a supported DPI value.

### `MDT_DEFAULT`

The default DPI setting for a monitor is MDT_EFFECTIVE_DPI.

## Remarks

All of these settings are affected by the [PROCESS_DPI_AWARENESS](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/ne-shellscalingapi-process_dpi_awareness) of your application

## See also

[GetDpiForMonitor](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/nf-shellscalingapi-getdpiformonitor)