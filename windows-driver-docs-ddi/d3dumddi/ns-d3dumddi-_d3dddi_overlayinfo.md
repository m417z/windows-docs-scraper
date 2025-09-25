# _D3DDDI_OVERLAYINFO structure

## Description

The D3DDDI_OVERLAYINFO structure describes information about an overlay.

## Members

### `hResource` [in]

A handle to the resource that is displayed by using the overlay. The resource is created through a call to the [CreateResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createresource) function with the **Overlay** bit-field flag set in the **Flags** member of the [D3DDDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddiarg_createresource) structure that is pointed to by the *pResource* parameter.

### `SubResourceIndex` [in]

The index to the subresource if the resource that is specified by the **hResource** member contains a list of allocations.

### `DstRect` [in]

A [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure for the destination rectangle, which contains the output coordinates for the display.

### `SrcRect` [in]

A RECT structure for the source rectangle that is displayed.

### `DstColorKeyLow` [in]

A value for the destination color key when the **DstColorKey** bit-field flag is set in the **Flags** member. If the color key is a range, **DstColorKeyLow** contains the low end of the range. The value is in the native format of the primary surface that is overlayed.

### `DstColorKeyHigh` [in]

The high end of the destination color key range when the **DstColorKeyRange** bit-field flag is set in **Flags**. The value is in the native format of the primary surface that is overlayed.

### `SrcColorKeyLow` [in]

A value for the source color key when the **SrcColorKey** bit-field flag is set in the **Flags** member. If the color key is a range, **SrcColorKeyLow** contains the low end of the range. The value is in the native format of the overlay resource that is displayed.

### `SrcColorKeyHigh` [in]

The high end of the source color key range when the **SrcColorKeyRange** bit-field flag is set in **Flags**. The value is in the native format of the overlay resource that is displayed.

### `Flags` [in]

A [D3DDDI_OVERLAYINFOFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_overlayinfoflags) structure that identifies the type of overlay operation to perform. Note that some flags are mutually exclusive with other flags. For more information, see the following Remarks section.

## Remarks

The **SrcColorKey**, **SrcColorKeyRange**, **DstColorKey**, and **DstColorKeyRange** bit-field flags are never set simultaneously in the **Flags** member.

## See also

[CreateOverlay](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createoverlay)

[CreateResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createresource)

[D3DDDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddiarg_createresource)

[D3DDDI_OVERLAYINFOFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_overlayinfoflags)

[RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)

[UpdateOverlay](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_updateoverlay)