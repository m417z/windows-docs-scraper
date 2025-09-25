## Description

The **IDDCX_PATH2** structure describes the mode to be set on a given monitor.

## Members

### `Size`

Total size of this structure, in bytes.

### `MonitorObject`

An [**IDDCX_MONITOR**](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx-objects) object with the handle the driver provides to identify the monitor that this path is targeted at.

### `Flags`

A [**IDDCX_PATH_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_path_flags) value with flags for this path, such as the path's active state and whether it has changed.

### `TargetVideoSignalInfo`

A [**DISPLAYCONFIG_VIDEO_SIGNAL_INFO**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-displayconfig_video_signal_info) structure with details of the target mode signal. See Remarks.

### `WireFormatInfo`

An [**IDDCX_WIRE_FORMAT_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_wire_format_info) structure with details of the signal to send to the monitor.

## Remarks

The OS provides an **IDDCX_PATH2** to the driver for every connected monitor, even if that monitor is not active.

[**DISPLAYCONFIG_VIDEO_SIGNAL_INFO**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-displayconfig_video_signal_info)'s **vSyncFreq** value is the Vsync rate between the Indirect Display device and the connected monitor. **vSyncFreqDivider** is used to calculate the rate at which the OS will update the desktop image. The desktop update rate will be calculated by the formula: ```vSyncFreq / vSyncFreqDivider```. **vSyncFreqDivider** cannot be zero.

For more information about HDR support, see [IddCx version 1.10 updates](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx1.10-updates).

## See also

[**EVT_IDD_CX_ADAPTER_COMMIT_MODES2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_adapter_commit_modes2)

[**IDARG_IN_COMMITMODES2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_commitmodes2)