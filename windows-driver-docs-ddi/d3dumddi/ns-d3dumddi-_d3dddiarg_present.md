# _D3DDDIARG_PRESENT structure

## Description

The D3DDDIARG_PRESENT structure describes a resource to display.

## Members

### `hSrcResource` [in]

A handle to the source resource to display. **hSrcResource** can be **NULL** if the user-mode display driver should perform a color-fill operation to the screen.

### `SrcSubResourceIndex` [in]

The zero-based index into the source resource, which is specified by the handle in the **hSrcResource** member. This index indicates the subresource or surface to display.

### `hDstResource` [in]

A handle to the destination resource to display to. If **NULL**, the user-mode display driver is informed that a color-fill operation will occur, but the user-mode driver is not expected to perform the operation. The display miniport driver does the actual color-fill operation and will be informed of the color value at that time.

### `DstSubResourceIndex`

 [in] The zero-based index into the destination resource, which is specified by the handle in the **hDstResource** member. This index indicates the subresource or surface to display to.

### `Flags` [in]

A [D3DDDI_PRESENTFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_presentflags) structure that identifies, in bit-field flags, how to display.

### `FlipInterval` [in]

A [D3DDDI_FLIPINTERVAL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-d3dddi_flipinterval_type)-typed value that indicates the flip interval (that is, if the flip occurs after zero, one, two, three, or four vertical syncs).

## See also

[Present](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_present)