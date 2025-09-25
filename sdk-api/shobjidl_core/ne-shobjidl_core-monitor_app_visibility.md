# MONITOR_APP_VISIBILITY enumeration

## Description

Specifies whether a display is showing desktop windows instead of Windows Store apps.

## Constants

### `MAV_UNKNOWN:0`

The display state is not known.

### `MAV_NO_APP_VISIBLE:1`

The display is showing desktop windows.

### `MAV_APP_VISIBLE:2`

The display is not showing desktop windows.

## Remarks

The **MONITOR_APP_VISIBILITY** enum is used by the [GetAppVisibilityOnMonitor](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iappvisibility-getappvisibilityonmonitor) method.

## See also

[IAppVisibility](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iappvisibility)