# PFND3DDDI_CLEAR callback function

## Description

The **Clear** function performs hardware-assisted clearing on the rendering target, depth buffer, or stencil buffer.

## Parameters

### `hDevice` [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_CLEAR](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_clear) structure that describes the parameters of the hardware-assisted clearing operation.

### `unnamedParam3`

*NumRect* [in]

The number of rectangles in the array at **pRect** to be cleared. If the number of rectangles is set to zero, **Clear** should clear the entire render target, depth buffer, and stencil buffer. In this situation, the contents of the array at **pRect** are undefined and the driver should not attempt to read them.

### `unnamedParam4`

*pRect* [in]

 An array of [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structures that indicate the rectangular areas of the buffer that the driver should clear.

## Return value

**Clear** returns S_OK or an appropriate error result if the hardware-assisted clearing operation is not successfully performed.

## Remarks

How the driver performs the clear operation depends on the number of rectangular areas that are specified in the *NumRect* parameter and the values that are set in the **Flags** member of [D3DDDIARG_CLEAR](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_clear). The D3DCLEAR_TARGET, D3DCLEAR_STENCIL, and D3DCLEAR_ZBUFFER values (defined in *D3d8types.h*) indicate the type of buffer to clear. The D3DCLEAR_COMPUTERECTS value (defined in *D3dhal.h*) indicates how to clear the buffer. The following settings indicate how the driver should clear the specified buffer type:

* If *NumRect* is set to 0 (*NumRect*== 0) and D3DCLEAR_COMPUTERECTS is not set in **Flags**, the driver clears 0 pixels (that is, a no-op).
* If *NumRect* is set to 0 and D3DCLEAR_COMPUTERECTS is set in **Flags**, the driver clears the entire viewport (not the entire surface).
* If *NumRect* is set to a value greater than 0 (*NumRect*!= 0) and D3DCLEAR_COMPUTERECTS is set in **Flags**, the driver clips the rectangular areas that **pRect** specifies against the current viewport.

Scissor testing also affects how the driver performs the clear operation. An application sets the D3DRS_SCISSORTESTENABLE render state in a call to the **IDirect3DDevice9::SetRenderState** method to enable scissor testing. For more information about scissor testing, see [Scissor Test](https://learn.microsoft.com/windows/win32/direct3d9/scissor-test). If the D3DRS_SCISSORTESTENABLE render state is set and the D3DCLEAR_COMPUTERECTS flag is set, the driver must clip the rectangular areas that **pRect** specifies to the scissor rectangular area.

If *NumRect* is set to a value greater than 0 (*NumRect* > 0) and D3DCLEAR_COMPUTERECTS is set in **Flags**, the driver clips the specified rectangular areas to the current viewport, and to the scissor rectangle if an application previously set D3DRS_SCISSORTESTENABLE. If *NumRect* > 0 and D3DCLEAR_COMPUTERECTS is not set, the driver determines that the Direct3D runtime already clipped the specified rectangular areas to the current viewport, and to the scissor rectangle if an application previously set D3DRS_SCISSORTESTENABLE.

## See also

[D3DDDIARG_CLEAR](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_clear)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)

[RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)