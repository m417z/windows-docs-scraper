# _DXGK_DEVICEINFOFLAGS structure

## Description

The DXGK_DEVICEINFOFLAGS structure identifies, in bit-field flags, information about a graphics device.

## Members

### `GuaranteedDmaBufferContract` [out]

Obsolete. A UINT value that specifies whether the device that is created through a call to [DxgkDdiCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdevice) uses the guaranteed contract model for direct memory access (DMA) buffers. For more information about the guaranteed contract model, see [Using the Guaranteed Contract DMA Buffer Model](https://learn.microsoft.com/windows-hardware/drivers/display/using-the-guaranteed-contract-dma-buffer-model). If this member is set, the device uses the guaranteed contract model; if this member is not set, the device does not use the guaranteed contract model. The display driver model for Windows Vista currently supports only the guaranteed contract DMA buffer model.

Setting this member is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `Reserved` [out]

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting remaining 31 bits (0xFFFFFFFE) of the 32-bit **Value** member to zeros.

### `Value` [out]

A member in the union that DXGK_DEVICEINFOFLAGS contains that can hold a 32-bit value that indicates information about a graphics device.

## See also

[DXGK_DEVICEINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_deviceinfo)

[DxgkDdiCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdevice)