## Description

**IDDCX_TARGET_MODE2** provides information about a target mode.

## Members

### `Size`

Size in bytes of this structure.

### `TargetVideoSignalInfo`

A [**DISPLAYCONFIG_TARGET_MODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-displayconfig_target_mode) structure that describes the display path target mode, including information about the video signal for the display.

### `RequiredBandwidth`

The display pipeline bandwidth required for this mode. The driver reports pipeline bandwidth in [**IDDCX_ADAPTER_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_adapter_caps)**.MaxDisplayPipelineRate**. The OS will never pick a combination of modes across all targets that exceeds this value.

### `BitsPerComponent`

An [**IDDCX_WIRE_BITS_PER_COMPONENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_wire_bits_per_component) value that specifies how many bits per component can be used to send pixels of each format to a monitor.

## Remarks

For more information about HDR support, see [IddCx version 1.10 updates](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx1.10-updates).

## See also

[**EVT_IDD_CX_MONITOR_QUERY_TARGET_MODES2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_monitor_query_target_modes2)

[**IDDCX_ADAPTER_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_adapter_caps)

[**IddCxMonitorUpdateModes2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorupdatemodes2)