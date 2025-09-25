# _D3DKMDT_VIDPN_PRESENT_PATH_IMPORTANCE enumeration

## Description

The D3DKMDT_VIDPN_PRESENT_PATH_IMPORTANCE enumeration indicates the importance of a video present path.

## Constants

### `D3DKMDT_VPPI_UNINITIALIZED`

Indicates that a variable of type D3DKMDT_VIDPN_PRESENT_PATH_IMPORTANCE has not yet been assigned a meaningful value.

### `D3DKMDT_VPPI_PRIMARY`

Indicates importance level 1.

### `D3DKMDT_VPPI_SECONDARY`

Indicates importance level 2.

### `D3DKMDT_VPPI_TERTIARY`

Indicates importance level 3.

### `D3DKMDT_VPPI_QUATERNARY`

Indicates importance level 4.

### `D3DKMDT_VPPI_QUINARY`

Indicates importance level 5.

### `D3DKMDT_VPPI_SENARY`

Indicates importance level 6.

### `D3DKMDT_VPPI_SEPTENARY`

Indicates importance level 7.

### `D3DKMDT_VPPI_OCTONARY`

Indicates importance level 8.

### `D3DKMDT_VPPI_NONARY`

Indicates importance level 9.

### `D3DKMDT_VPPI_DENARY`

Indicates importance level 10.

## Remarks

As the numeric value of a D3DKMDT_VIDPN_PRESENT_PATH_IMPORTANCE value increases, the importance decreases. For example, level 3 is less important than level 2.

A variable of type D3DKMDT_VIDPN_PRESENT_PATH_IMPORTANCE can have any integer value in the range 0 through 255, but only the values 0 through 10 have names.

It is useful to rank the video present paths in a video present network (VidPN) according to importance. For example, a path that represents the primary view can be assigned a higher importance than other paths so that it gets the best source and target mode sets.

The **ImportanceOrdinal** member of the [D3DKMDT_VIDPN_PRESENT_PATH](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path) structure is a D3DKMDT_VIDPN_PRESENT_PATH_IMPORTANCE value. Path importance ordinal numbers are unique within a given VidPN topology.

## See also

[D3DKMDT_VIDPN_PRESENT_PATH](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path)