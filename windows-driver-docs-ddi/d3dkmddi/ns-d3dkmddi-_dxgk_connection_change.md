# DXGK_CONNECTION_CHANGE structure

## Description

**DXGK_CONNECTION_CHANGE** describes the most recently updated status of the link for a target.

## Members

### `ConnectionChangeId`

The per target unique ID for the transition being reported. This value must be unique across all targets on the adapter and must be monotonically increasing for each change reported.

### `TargetId`

The target ID for which the change is being reported. This target ID must have been reported to the OS before and must be in a state that supports the given change.

### `ConnectionStatus`

A [**DXGK_CONNECTION_STATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_connection_status) value that specifies the status of the connection. **ConnectionStatus** typically indicates the type of change, guiding which structure within the union member to use.

### `Reserved`

Reserved for system use.

### `MonitorConnect`

Describes the monitor that has been connected. This structure is used when **ConnectionStatus** is **MonitorStatusConnected**.

### `MonitorConnect.LinkTargetType`

A [**D3DKMDT_VIDEO_OUTPUT_TECHNOLOGY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_video_output_technology) value that identifies the video output technology of the monitor that has been connected. The **D3DKMDT_VOT_INTERNAL** and **D3DKMDT_VOT_MIRACAST** values are not allowed.

### `MonitorConnect.MonitorConnectFlags`

A [**DXGK_CONNECTION_MONITOR_CONNECT_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_connection_monitor_connect_flags) structure with flags for the connected monitor. This member is available starting with Windows 11 (WDDM 3.0).

### `TargetConnect`

Describes the current target's connector. This structure is used when **ConnectionStatus** is **TargetStatusConnected**.

#### `TargetConnect.BaseTargetType`

A [**D3DKMDT_VIDEO_OUTPUT_TECHNOLOGY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_video_output_technology) value that identifies the video output technology of the current target's connector. As with **MonitorConnect.LinkTargetType**, the **D3DKMDT_VOT_INTERNAL** and **D3DKMDT_VOT_MIRACAST** values are not allowed.

#### `TargetConnect.NewTargetId`

The target ID for which the change is being reported. This target ID must have been reported to the OS before and must be in a state which supports the given change.

### `TargetJoin`

Describes the joining target's connector. This structure is used when **ConnectionStatus** is **TargetStatusJoined**.

#### `TargetJoin.BaseTargetType`

A [**D3DKMDT_VIDEO_OUTPUT_TECHNOLOGY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_video_output_technology) value that identifies the video output technology of the connector of the new target. As with **MonitorConnect.LinkTargetType**, the **D3DKMDT_VOT_INTERNAL** and **D3DKMDT_VOT_MIRACAST** values are not allowed.

> [!NOTE]
> The same **BaseTargetType** must be reported for all targets that are being joined to each other.

#### `TargetJoin.NewTargetId`

The target ID for which the change is being reported. This target ID must have been reported to the OS before and must be in a state which supports the given change.

## See also

[**D3DKMDT_VIDEO_OUTPUT_TECHNOLOGY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_video_output_technology)

[**DXGK_SET_TIMING_PATH_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_set_timing_path_info)

[**DXGKARG_QUERYCONNECTIONCHANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_queryconnectionchange)

[**DXGKDDI_QUERYCONNECTIONCHANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryconnectionchange)