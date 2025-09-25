# PFND3DDDI_COMPOSERECTS callback function

## Description

The **ComposeRects** function composes two-dimensional areas from a source surface to a destination surface.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_COMPOSERECTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_composerects) structure that specifies the parameters that are used to compose rectangular areas.

## Return value

**ComposeRects** returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **S_OK** | The rectangular areas were successfully composed. |
| **E_OUTOFMEMORY** | [ComposeRects]() could not allocate the required memory for it to complete. |

## Remarks

The following constraints and validations apply to the **ComposeRects** function:

* The driver should ignore the source rectangular areas that are not completely inside the source surface.
* The destination rectangular areas--after applying offsets--can be partially or completely outside the destination surface. The destination rectangular areas are clipped if partially outside and rejected or completely clipped if completely outside.
* The same surface cannot be specified for the source and the destination.
* Surfaces and vertex buffers that are used with **ComposeRects** should not be locked.
* The source and destination surfaces are formatted as one bit per pixel (D3DDDIFMT_A1) when they are created.
* In the debug build, the Microsoft Direct3D runtime validates that a source rectangular area description exists for each index in the destination rectangular area description. In the retail build, **ComposeRects** returns an error if an invalid index exists.
* The number of rectangular areas should be less than 0xFFFF to prevent internal overflow during math operations.
* Surfaces and vertex buffers should be created by using the same display device (graphics context).
* Local display memory should be specified for the destination surface.

The following example code shows an operation that **ComposeRects** performs:

```cpp
for (UINT i=0; i < COMPOSERECTS.NumDstRects; i++) {
   if (i >= Size(VertexBuffer(hDstRectDescsVB)) / sizeof(D3DCOMPOSERECTDSTDESC))
      Ignore the rectangle;
   if (VertexBuffer(hDstRectDescsVB)[i].RectDescIndex >= Size(VertexBuffer(hSrcRectDescsVB)) / sizeof(D3DCOMPOSERECTSRCDESC))
      Ignore the rectangle;
   SourceRectangle = VertexBuffer(hSrcResource)[VertexBuffer(hDstRectDescsVB)[i].RectDescIndex];
   DestinationRectangle.X = {VertexBuffer(hDstRectDescsVB)[i].X + COMPOSERECTS.Xoffset;
   DestinationRectangle.Y = {VertexBuffer(hDstRectDescsVB)[i].Y + COMPOSERECTS.Yoffset;
   DestinationRectangle.Width = SourceRectangle.Width;
   DestinationRectangle.Height = SourceRectangle.Height;
   Perform COMPOSERECTS.Operation for each pixel;
}
```

## See also

[D3DDDIARG_COMPOSERECTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_composerects)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)