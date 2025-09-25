# DDSETSURFACESTATE structure

## Description

The DDSETSURFACESTATE structure contains the surface state information.

## Members

### `hDirectDraw`

Specifies the Microsoft DirectDraw handle.

### `hSurface`

Specifies the DirectDrawSurface handle.

### `dwState`

Indicates the surface state. One of the following:

| Flag | Meaning |
| --- | --- |
| DDSTATE_BOB | Bob mode is to be used on this surface. |
| DDSTATE_WEAVE | Weave mode is to be used on this surface. |

### `dwStartField`

Indicates the field on which the state change should occur. A value of 0 indicates it should occur at the start of the next field, a value of 1 indicates the start of the following field, and so on.

## See also

[DD_DXAPI_SET_SURFACE_STATE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff551504(v=vs.85))

[DxApi](https://learn.microsoft.com/previous-versions/windows/drivers/display/nf-dxapi-dxapi)