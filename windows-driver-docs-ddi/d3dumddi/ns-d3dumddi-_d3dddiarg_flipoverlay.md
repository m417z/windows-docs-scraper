# _D3DDDIARG_FLIPOVERLAY structure

## Description

The D3DDDIARG_FLIPOVERLAY structure describes a new resource to display on a given overlay.

## Members

### `hOverlay` [in]

A handle to the overlay hardware to be flipped.

### `hSource` [in]

A handle to the new resource to be displayed. This resource might be the same as the resource that was previously displayed if deinterlacing interleaved data.

### `SourceIndex` [in]

The zero-based index of the subresource to be displayed.

### `Flags` [in]

A [D3DDDI_FLIPOVERLAYFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_flipoverlayflags) structure that indicates, in bit-field flags, how to flip the resource.

## See also

[D3DDDI_FLIPOVERLAYFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_flipoverlayflags)

[FlipOverlay](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_flipoverlay)