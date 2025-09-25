# IAppVisibility::GetAppVisibilityOnMonitor

## Description

Queries the current mode of the specified monitor.

## Parameters

### `hMonitor` [in]

The monitor to query.

### `pMode` [out]

The current mode of *hMonitor*.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | *pMode* is **NULL**. |

## See also

[IAppVisibility](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iappvisibility)

[MONITOR_APP_VISIBILITY](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-monitor_app_visibility)