# _D3DHAL_DP2CLEAR structure

## Description

D3DHAL_DP2CLEAR contains all of the information that the driver needs to perform hardware-assisted clearing on the rendering target, depth buffer or stencil buffer.

## Members

### `dwFlags`

Specifies what buffers the driver should clear. This member can be a bitwise OR of the following values:

| **Value** | **Meaning** |
|:--|:--|
| D3DCLEAR_TARGET | The driver should clear the context's render target to the color specified by the dwFillColor member. |
| D3DCLEAR_STENCIL | The driver should clear the context's stencil buffer to the value specified by the dwFillStencil member. |
| D3DCLEAR_ZBUFFER | The driver should clear the context's depth buffer to the depth specified by the dwFillDepth member. |
| D3DCLEAR_COMPUTERECTS | DirectX 8.0 and later versions only.<br>If this flag is set, the specified rectangles should be clipped against the current viewport. Furthermore, it is possible that when D3DCLEAR_COMPUTERECTS is specified the number of rectangles to clear can be zero (the number of rectangles to clear can be found in the wStateCount/wPrimtiveCount union of the [D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command) structure for the clear). In this case the entire viewport should be cleared. |

### `dwFillColor`

Specifies the color that the driver should clear the context's render target to.

### `dvFillDepth`

Specifies the value that the driver should use to set the depth in the context's depth buffer. This member can be a value in the interval 0.0 to 1.0. The driver should convert this value to an integer using the **dwZBitMask** member of the depth buffer's [DDPIXELFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-_ddpixelformat) structure.

### `dwFillStencil`

Specifies the value that the driver should clear the context's stencil buffer to. This member can be an integer in the interval 0 to 2ⁿ-1, where *n* is the number of bits in the stencil buffer.

### `Rects`

Specifies the rectangular areas of the buffer that the driver should clear. The rectangles are specified in screen coordinates. This member of the structure contains the first rectangle area to be blitted. The **wStateCount** member of the [D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command) contains the total number of rectangle areas to be blitted. The other (**wStateCount**-1) RECT structures required follow the D3DHAL_DP2CLEAR structure without any padding.

## Remarks

This structure is used with the D3DDP2OP_CLEAR command token to replace the legacy **D3dClear** and **D3dClear2** callbacks.

It is important to note that when the number of rectangles is zero, the D3DHAL_DP2CLEAR data structure still includes space for a single RECT. Thus, the size of this single RECT should be included when advancing to the next DP2 instruction. However, the contents of the RECT in this case are undefined and the driver should not attempt to read them.

Display drivers must convert input color values for the ARGB and YUV classes of color formats. For clear operations, input color values are specified in the **dwFillColor** member. For more information, see [Handling Color Values for Pixel Formats](https://learn.microsoft.com/windows-hardware/drivers/display/handling-color-values-for-pixel-formats).

## See also

D3DDP2OP_CLEAR

[D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command)

[DDPIXELFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-_ddpixelformat)