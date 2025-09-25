# D3DDDIARG_PRESENTMULTIPLANEOVERLAY structure

## Description

Specifies a multiplane overlay resource to display.

## Members

### `VidPnSourceId` [in]

The zero-based video present network (VidPN) source identification number of the input that is to be displayed.

### `Flags` [in]

A [D3DDDI_PRESENTFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_presentflags) structure that identifies, in bit-field flags, how to display.

### `FlipInterval` [in]

A value of type [D3DDDI_FLIPINTERVAL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-d3dddi_flipinterval_type) that indicates the flip interval (that is, if the flip occurs after zero, one, two, three, or four vertical syncs).

### `PresentPlaneCount` [in]

The number of overlay planes that are available to display.

### `pPresentPlanes` [in]

A pointer to a structure of type [D3DDDI_PRESENT_MULTIPLANE_OVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_present_multiplane_overlay) that describes the overlay plane to display.

### `Reserved` [in]

Reserved for system use. The driver should ignore this member.

## See also

[D3DDDI_FLIPINTERVAL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-d3dddi_flipinterval_type)

[D3DDDI_PRESENTFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_presentflags)

[D3DDDI_PRESENT_MULTIPLANE_OVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_present_multiplane_overlay)