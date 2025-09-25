# IDDCX_TARGET_MODE structure

## Description

**IDDCX_TARGET_MODE** provides information about the target mode signal, including the bandwidth needed for the mode.

## Members

### `Size`

Size of the structure, in bytes.

### `TargetVideoSignalInfo`

A [**DISPLAYCONFIG_TARGET_MODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-displayconfig_target_mode) structure that describes the display path target mode, including information about the video signal for the display.

### `RequiredBandwidth`

The display pipeline bandwidth required for this mode. The driver reports pipeline bandwidth in **[IDDCX_ADAPTER_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_adapter_caps).MaxDisplayPipelineRate**. The OS will never pick a combination of modes across all targets that exceeds this value.

## Remarks

Using the values reported in [**DISPLAYCONFIG_VIDEO_SIGNAL_INFO**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-displayconfig_video_signal_info) (which is a member of [**DISPLAYCONFIG_TARGET_MODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-displayconfig_target_mode)), the desktop update rate will be calculated by the formula ```vSyncFreq / vSyncFreqDivider```, where:

* **vSyncFreq** is the Vsync rate between the indirect display device and the connected monitor
* **vSyncFreqDivider** is used to calculate the rate at which the OS will update the desktop image. This value cannot be zero.

## See also

[**EVT_IDD_CX_MONITOR_QUERY_TARGET_MODES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_monitor_query_target_modes)

[**IddCxMonitorUpdateModes**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorupdatemodes)

[**IDDCX_ADAPTER_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_adapter_caps)