# _D3DDDIARG_COMPOSERECTS structure

## Description

The D3DDDIARG_COMPOSERECTS structure describes the parameters that are used to compose rectangular areas.

## Members

### `hSrcResource` [in]

A handle to the source resource that contains the source surface. When the surface is created, the user-mode display driver receives the D3DDDIFMT_A1 (one bit per pixel) value in the **Format** member and the **TextApi** bit-field flag in the **Flags** member of the [D3DDDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddiarg_createresource) structure in a call to the driver's [CreateResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createresource) function. The surface must be created as part of a texture.

### `SrcSubResourceIndex` [in]

The index to the source surface within the source resource.

### `hDstResource` [in]

A handle to the destination resource that contains the destination surface. When the surface is created, the user-mode display driver receives the D3DDDIFMT_A1 (one bit per pixel) value in the **Format** member of [D3DDDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddiarg_createresource) in a call to the driver's [CreateResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createresource). The surface must be created as part of a texture. The surface might have been created with the **TextApi** bit-field flag.

### `DstSubResourceIndex` [in]

The index to the destination surface within the destination resource.

### `hSrcRectDescsVB` [in]

A handle to a vertex buffer that contains an array of D3DCOMPOSERECTSRCDESC structures. Each element in the array defines a rectangle on the source surface. When the vertex buffer is created, the user-mode display driver receives the **TextApi** bit-field flag in the **Flags** member of the [D3DDDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddiarg_createresource) structure in a call to the driver's [CreateResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createresource) function.

### `NumRects` [in]

The number of rectangular areas to copy, which is the number of D3DCOMPOSERECTDSTDESC structures in the vertex buffer that is identified by the **hDstRectDescsVB** member. Drivers should ignore calls to [ComposeRects](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_composerects) with **NumRects** set to greater than 0xFFFF.

### `hDstRectDescsVB` [in]

A handle to a vertex buffer that contains an array of D3DCOMPOSERECTDSTDESC structures. Each element in the array defines where to copy a source rectangle on the destination surface. For more information, see the following Remarks section. When the vertex buffer is created, the user-mode display driver receives the **TextApi** bit-field flag in the **Flags** member of the [D3DDDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddiarg_createresource) structure in a call to the driver's [CreateResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createresource) function.

### `Operation` [in]

A D3DDDI_COMPOSERECTSOP value that describes how to compose the rectangular areas. This member can be one of the following values.

| **Value** | **Meaning** |
|:--|:--|
| D3DDDICOMPOSERECTS_COPY | Copy each source bit to the destination. |
| D3DDDICOMPOSERECTS_OR | Combine source and destination bits in an OR operation and copy to the destination. |
| D3DDDICOMPOSERECTS_AND | Combine source and destination bits in an AND operation and copy to the destination. |
| D3DDDICOMPOSERECTS_NEG | Combine the negative of the source bits with the destination bits and copy to the destination. [Dest bit & (~ Src bit)] |

### `XOffset` [in]

An offset to add to the *x*-coordinates of all of the destination rectangular areas. The offset can be negative, which might cause the resultant rectangles to be rejected or clipped.

### `YOffset` [in]

An offset to add to the *y*-coordinates of all of the destination rectangular areas. The offset can be negative, which might cause the resultant rectangles to be rejected or clipped.

## Remarks

The vertex buffers that contain the composing instructions are created with D3DUSAGE_TEXTAPI usage. The following code defines the structures that are contained in the vertex buffer arrays. For more information about these structures, see the DirectX SDK documentation.

```cpp
struct D3DCOMPOSERECTSRCDESC {
USHORT X, Y;          // Coordinates of top-left corner
USHORT width, height; // Width and height of the glyph in bits
};

struct D3DCOMPOSERECTDSTDESC {
USHORT RectDescIndex; // Index of one of the D3DCOMPOSERECTSRCDESC structures in the vertex buffer represented by hSrcRectDescsVB
USHORT reserved;      // Use to align the struct and fields to good boundaries
SHORT X, Y;            // Position in bits in the destination surface
};
```

## See also

[ComposeRects](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_composerects)

[RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)