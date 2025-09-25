# D3D11DDIARG_POINTERDATA structure

## Description

The D3D11DDIARG_POINTERDATA structure describes the location of the data that is reference by a class instance that has been assigned to an interface implementation.

## Members

### `uCBOffset`

A UINT value that specifies the offset, in bytes, into the constant buffer that the **uCBID** member specifies to reach the data for the interface.

Setting this member is equivalent to setting the first 12 bits of a 32-bit value (0x00000FFF).

### `uCBID`

A UINT value that identifies the constant buffer that data for the interface is in.

Setting this member is equivalent to setting bits 13 through 16 of a 32-bit value (0x0000F000).

### `uBaseSamp`

A UINT value that specifies the index of the first sampler that is used by the class instance of the interface implementation.

Setting this member is equivalent to setting bits 17 through 20 of a 32-bit value (0x000F0000).

### `uBaseTex`

A UINT value that specifies the index of the first texture that is used by the class instance of the interface implementation.

Setting this member is equivalent to setting bits 21 through 27 of a 32-bit value (0x07F00000).

### `uReserved`

Reserved for future use. This member makes the size of D3D11DDIARG_POINTERDATA 32-bit aligned and should always be set to zero. Setting this member to zero is equivalent to setting the remaining 5 bits (0xF8000000) of a 32-bit value to zeros.

## Remarks

D3D11DDIARG_POINTERDATA contains the location of the data for one of the interfaces that is referred to in a call to the driver's [CsSetShaderWithIfaces](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_setshader_with_ifaces), [DsSetShaderWithIfaces](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_setshader_with_ifaces), [GsSetShaderWithIfaces](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_setshader_with_ifaces), [HsSetShaderWithIfaces](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_setshader_with_ifaces), [PsSetShaderWithIfaces](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_setshader_with_ifaces), or [VsSetShaderWithIfaces](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_setshader_with_ifaces) function.

## See also

[CsSetShaderWithIfaces](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_setshader_with_ifaces)

[DsSetShaderWithIfaces](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_setshader_with_ifaces)

[GsSetShaderWithIfaces](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_setshader_with_ifaces)

[HsSetShaderWithIfaces](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_setshader_with_ifaces)

[PsSetShaderWithIfaces](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_setshader_with_ifaces)

[VsSetShaderWithIfaces](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_setshader_with_ifaces)