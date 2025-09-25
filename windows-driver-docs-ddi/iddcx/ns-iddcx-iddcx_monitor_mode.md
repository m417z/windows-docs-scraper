# IDDCX_MONITOR_MODE structure

## Description

A **IDDCX_MONITOR_MODE** structure provides information about the current monitor mode.

## Members

### `Size`

Total size in bytes of this structure.

### `Origin`

A [**IDDCX_MONITOR_MODE_ORIGIN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_monitor_mode_origin) value from which the driver derived this mode.

### `MonitorVideoSignalInfo`

A [**DISPLAYCONFIG_VIDEO_SIGNAL_INFO**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-displayconfig_video_signal_info) structure that provides the details of the Monitor mode.

**MonitorVideoSignalInfo.AdditionalSignalInfo**'s union value of **vSyncFreqDivider** must be zero.

## See also

[**EVT_IDD_CX_PARSE_MONITOR_DESCRIPTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_parse_monitor_description)

[**IDARG_IN_PARSEMONITORDESCRIPTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_parsemonitordescription)

[**IDARG_OUT_PARSEMONITORDESCRIPTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_parsemonitordescription)