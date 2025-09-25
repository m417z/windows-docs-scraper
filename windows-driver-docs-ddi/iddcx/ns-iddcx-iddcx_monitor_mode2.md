## Description

The **IDDCX_MONITOR_MODE2** structure contains information about a monitor mode.

## Members

### `Size`

Size in bytes of this structure.

### `Origin`

An [**IDDCX_MONITOR_MODE_ORIGIN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_monitor_mode_origin) value that identifies where the driver derived the mode from.

### `MonitorVideoSignalInfo`

A [**DISPLAYCONFIG_VIDEO_SIGNAL_INFO**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-displayconfig_video_signal_info) structure that contains details about the monitor mode. **AdditionalSignalInfo.vSyncFreqDivider** must be set to zero.

### `BitsPerComponent`

A [**IDDCX_WIRE_BITS_PER_COMPONENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_wire_bits_per_component) structure that specifies the number of bits per component that can be used to send pixels of each format to a monitor.

## Remarks

For more information about HDR support, see [IddCx version 1.10 updates](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx1.10-updates).

## See also

[**EVT_IDD_CX_PARSE_MONITOR_DESCRIPTION2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_parse_monitor_description2)

[**IDARG_IN_PARSEMONITORDESCRIPTION2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_parsemonitordescription2)

[**IDARG_OUT_PARSEMONITORDESCRIPTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_parsemonitordescription)