# _DXVAHDDDI_FRAME_FORMAT enumeration

## Description

The DXVAHDDDI_FRAME_FORMAT enumeration contains values that identify the frame format.

## Constants

### `DXVAHDDDI_FRAME_FORMAT_PROGRESSIVE`

A value that specifies that the frame format is progressive.

### `DXVAHDDDI_FRAME_FORMAT_INTERLACED_TOP_FIELD_FIRST`

A value that specifies that the frame format is interlaced with two fields. The top (even) field is displayed first.

### `DXVAHDDDI_FRAME_FORMAT_INTERLACED_BOTTOM_FIELD_FIRST`

A value that specifies that the frame format is interlaced with two fields. The bottom (odd) field is displayed first.

## Remarks

The [FOURCC](https://learn.microsoft.com/windows-hardware/drivers/) format of the surface defines whether the interlaced fields are interleaved or not. For example, NV12 is an interlaced format with interleaved fields whereas NV24 is an interlaced format with non-interleaved fields.

## See also

[DXVAHDDDI_STREAM_STATE_FRAME_FORMAT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_state_frame_format_data)