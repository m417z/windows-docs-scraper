# _DXGKMDT_OPM_INTERLEAVE_FORMAT enumeration

## Description

The DXGKMDT_OPM_INTERLEAVE_FORMAT enumeration indicates the scan line ordering of a video frame from a protected output's signal.

## Constants

### `DXGKMDT_OPM_INTERLEAVE_FORMAT_OTHER`

Indicates that the video frame has a scan line ordering other than those given in the following constants of this enumeration.

### `DXGKMDT_OPM_INTERLEAVE_FORMAT_PROGRESSIVE`

Indicates that each video frame has a scan line ordering that is progressive (that is, not interlaced).

### `DXGKMDT_OPM_INTERLEAVE_FORMAT_INTERLEAVED_EVEN_FIRST`

Indicates that each video frame has a scan line ordering that is interlaced, each field contains half of a frame, and the even scan lines are displayed first.

### `DXGKMDT_OPM_INTERLEAVE_FORMAT_INTERLEAVED_ODD_FIRST`

Indicates that each video frame has a scan line ordering that is interlaced, each field contains half of a frame, and the odd scan lines are displayed first.

### `DXGKMDT_OPM_INTERLEAVE_FORMAT_FORCE_ULONG`

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. You should not use this value.

## See also

[DXGKMDT_OPM_ACTUAL_OUTPUT_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_actual_output_format)