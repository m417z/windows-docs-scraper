# IAppVisibilityEvents::AppVisibilityOnMonitorChanged

## Description

Notifies a client that the mode of a display has changed.

## Parameters

### `hMonitor` [in]

The display that has a changing mode.

### `previousMode` [in]

The previous mode of *hMonitor*, which may be **MAV_UNKNOWN** if the client was unaware of the display previously.

### `currentMode` [in]

The current mode of *hMonitor*, which will not be **MAV_UNKNOWN**.

## Return value

The return value is ignored.

## See also

[IAppVisibilityEvents](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iappvisibilityevents)