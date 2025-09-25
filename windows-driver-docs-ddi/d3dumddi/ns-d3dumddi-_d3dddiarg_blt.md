# _D3DDDIARG_BLT structure

## Description

The D3DDDIARG_BLT structure describes the parameters of a bit-block transfer (bitblt).

## Members

### `hSrcResource` [in]

A handle to the source resource.

### `SrcSubResourceIndex` [in]

The index to the source surface within the resource.

### `SrcRect` [in]

A [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure for the source rectangle.

### `hDstResource` [in]

A handle to the destination resource.

### `DstSubResourceIndex` [in]

The index to the destination surface within the resource.

### `DstRect` [in]

A [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure for the destination rectangle.

### `ColorKey` [in]

A value for the color key. Note that the **SrcColorKey** and **DstColorKey** bit-field flags are never set simultaneously in the **Flags** member.

### `Flags` [in]

A [D3DDDI_BLTFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_bltflags) structure that identifies the type of bitblt to perform. Note that some bit-field flags in this structure are mutually exclusive with other flags. For more information about these flags, see the following Remarks section.

## Remarks

If a filtering option (for example, the **Point** or **Linear** bit-field flag) is not specified in the **Flags** member, the driver can use its own filtering technique.

The **SrcColorKey** and **DstColorKey** bit-field flags are never set simultaneously. Similarly, the **Point** bit-field flag is not simultaneously set with the **Linear** bit-field flag.

## See also

[Blt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_blt)

[D3DDDI_BLTFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_bltflags)

[RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)