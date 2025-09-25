# _DXVAHDDDI_OUTPUT_RATE enumeration

## Description

The DXVAHDDDI_OUTPUT_RATE enumeration contains values that identify the output rate that the driver should use.

## Constants

### `DXVAHDDDI_OUTPUT_RATE_NORMAL`

A value that specifies that the driver should use normal output rate, which is when one progressive frame becomes one progressive frame and one interlaced frame (two fields) becomes two progressive frames.

### `DXVAHDDDI_OUTPUT_RATE_HALF`

A value that specifies that the driver should use half output rate, which is when one progressive frame becomes one progressive frame and one interlaced frame (two fields) becomes one progressive frame.

### `DXVAHDDDI_OUTPUT_RATE_CUSTOM`

A value that specifies that the driver should use a custom output rate for the frame rate conversion or the inverse telecine. For more information about custom output rate, see [DXVAHDDDI_CUSTOM_RATE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_custom_rate_data).

## Remarks

For more information about output rate, see [DXVAHDDDI_STREAM_STATE_OUTPUT_RATE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_state_output_rate_data) and [DXVAHDDDI_STREAM_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_data).

## See also

[DXVAHDDDI_CUSTOM_RATE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_custom_rate_data)

[DXVAHDDDI_STREAM_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_data)

[DXVAHDDDI_STREAM_STATE_OUTPUT_RATE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_state_output_rate_data)