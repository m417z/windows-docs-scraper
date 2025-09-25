# PFND3D10DDI_RESOURCEUPDATESUBRESOURCEUP callback function

## Description

The *DefaultConstantBufferUpdateSubresourceUP* function updates a destination subresource region that stores constant buffers from a source system-memory region.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hDstResource* [in]

A handle to the destination resource to copy to.

### `unnamedParam3`

*DstSubresource* [in]

An index that indicates the destination subresource to copy to.

### `unnamedParam4`

*pDstBox* [in, optional]

A pointer to a [D3D10_DDI_BOX](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_ddi_box) structure that specifies the region of the destination subresource to copy data to. If **pDstBox** is **NULL**, the driver should copy to the entire destination subresource.

### `unnamedParam5`

*pSysMemUP* [in]

A pointer to the beginning address of the source data that *DefaultConstantBufferUpdateSubresourceUP* uses to update the destination subresource.

### `unnamedParam6`

*RowPitch* [in]

The offset, in bytes, to move to the next row of source data.

### `unnamedParam7`

*DepthPitch* [in]

The offset, in bytes, to move to the next depth slice of source data.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

For more information about *DefaultConstantBufferUpdateSubresourceUP*, see the Remarks section of the [ResourceUpdateSubresourceUP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourceupdatesubresourceup) function.

The driver should not encounter any error, except for D3DDDIERR_DEVICEREMOVED. Therefore, if the driver passes any error, except for D3DDDIERR_DEVICEREMOVED, in a call to the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) function, the Direct3D runtime will determine that the error is critical. Even if the device was removed, the driver is not required to return D3DDDIERR_DEVICEREMOVED; however, if device removal interfered with the operation of *DefaultConstantBufferUpdateSubresourceUP* (which typically should not happen), the driver can return D3DDDIERR_DEVICEREMOVED.

## See also

[D3D10DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_devicefuncs)

[D3D10_DDI_BOX](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_ddi_box)

[ResourceUpdateSubresourceUP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourceupdatesubresourceup)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)