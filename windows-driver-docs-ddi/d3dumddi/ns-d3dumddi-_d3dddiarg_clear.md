# _D3DDDIARG_CLEAR structure

## Description

The D3DDDIARG_CLEAR structure describes the parameters of a hardware-assisted clearing operation.

## Members

### `Flags` [in]

A UINT value that specifies which buffers the driver should clear and how the clear operation should be performed. This member can be a bitwise OR of the following values. For more information, see the Remarks section in the [Clear](https://learn.microsoft.com/windows-hardware/drivers/ddi/) reference page.

| **Value** | **Meaning** |
|:--|:--|
| D3DCLEAR_TARGET (0x00000001l) | The driver should clear the context's render target to the color that is specified by the FillColor member. This value is defined in D3d8types.h. |
| D3DCLEAR_STENCIL (0x00000004l) | The driver should clear the context's stencil buffer to the value that is specified by the FillStencil member. This value is defined in D3d8types.h. |
| D3DCLEAR_ZBUFFER (0x00000002l) | The driver should clear the context's depth buffer to the depth that is specified by the FillDepth member. This value is defined in D3d8types.h. |
| D3DCLEAR_COMPUTERECTS (0x00000008l) | If rectangles are specified for clearing, the driver should clip them against the current viewport. If no rectangles are specified, the driver should clear the entire viewport. This value is defined in D3dhal.h. |

### `FillColor` [in]

The color value that the driver should clear the context's render target to.

### `FillDepth` [in]

The value that the driver should use to set the depth in the context's depth buffer. This member can be a value in the range from 0.0 through 1.0.

### `FillStencil` [in]

The value that the driver should clear the context's stencil buffer to. This member can be an integer in the range from 0 through 2ⁿ-1, where *n* is the number of bits in the stencil buffer.

## Remarks

In a call to the user-mode display driver's [Clear](https://learn.microsoft.com/windows-hardware/drivers/ddi/) function, a pointer to a D3DDDIARG_CLEAR structure is passed in the *pData* parameter. The Microsoft Direct3D runtime passes information to the *NumRect* and *pRect* parameters in a call to the user-mode display driver's **Clear** function to specify the rectangular areas of the buffer that the driver should clear.

## See also

[Clear](https://learn.microsoft.com/windows-hardware/drivers/ddi/)