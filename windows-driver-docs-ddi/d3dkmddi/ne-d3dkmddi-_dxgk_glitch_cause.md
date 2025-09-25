# DXGK_GLITCH_CAUSE enumeration

## Description

Enumeration that describes what caused a glitch during a [**SetTimingsFromVidPn**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_settimingsfromvidpn) call.

## Constants

### `DXGK_GLITCH_CAUSE_DRIVER_ERROR`

Indicates that an internal driver error caused a glitch.

### `DXGK_GLITCH_CAUSE_TIMING_CHANGE`

Indicates that the timing requested necessitated a glitch. This cause should only be used if the OS requested a change which would always result in a glitch rather than something which could have been avoided under other circumstances.

For example, this should not be used if the driver switches to a different display pipe to support an additional path, but it should be used if the OS requests a different timing to the previous one.

### `DXGK_GLITCH_CAUSE_PIPELINE_CHANGE`

Indicates that reconfiguring the display pipeline caused a glitch.

### `DXGK_GLITCH_CAUSE_MEMORY_TIMING`

Indicates that changing graphics memory timings caused a glitch.

### `DXGK_GLITCH_CAUSE_ENCODER_RECONFIG`

Indicates that changing the configuration of the encoder for a target caused a glitch.

### `DXGK_GLITCH_CAUSE_MODIFIED_WIRE_USAGE`

Indicates that modifying the format of pixel data in the transport stream caused a glitch.

### `DXGK_GLITCH_CAUSE_METADATA_CHANGE`

Indicates that changing the frame metadata caused a glitch.

### `DXGK_GLITCH_CAUSE_NONE`

Indicates that there was no glitch.

## See also

[**DXGK_SET_TIMING_PATH_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_set_timing_path_info)

[**DXGKDDI_SETTIMINGSFROMVIDPN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_settimingsfromvidpn)