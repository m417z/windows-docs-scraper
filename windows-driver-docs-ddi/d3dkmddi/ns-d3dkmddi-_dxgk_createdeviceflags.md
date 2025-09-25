# _DXGK_CREATEDEVICEFLAGS structure

## Description

The DXGK_CREATEDEVICEFLAGS structure identifies how to create devices.

## Members

### `SystemDevice`

A UINT value that specifies whether devices that the driver's [DxgkDdiCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdevice) function creates are system devices.

Setting this member is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `GdiDevice`

A UINT value that specifies whether the devices that the driver's [DxgkDdiCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdevice) function creates are GDI-specific devices.

Setting this member is equivalent to setting the second bit of the 32-bit Value member (0x00000002).

This member is available beginning with Windows 7.

### `Reserved`

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting bits 3 through 31 (0x7FFFFFFC) of the 32-bit **Value** member to zeros.

### `DXGK_DEVICE_RESERVED0`

Supported beginning with Windows 8.

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting the last bit (0x80000000) of the 32-bit **Value** member to zero.

### `Value`

A member in the union that DXGK_CREATEDEVICEFLAGS contains that can hold a 32-bit value that identifies how to create devices.

## See also

[DXGKARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createdevice)

[DxgkDdiCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdevice)