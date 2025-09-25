# PFND3D11_1DDI_RESOURCEUPDATESUBRESOURCEUP callback function

## Description

updates a destination subresource region that stores constant buffers from a source system-memory region. Implemented by Windows Display Driver Model (WDDM) 1.2 and later user-mode display drivers.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hDstResource*

A handle to the destination resource to copy to.

### `unnamedParam3`

*DstSubresource*

An index that indicates the destination subresource to copy to.

### `unnamedParam4`

*pDstBox* [in, optional]

A pointer to a [D3D10_DDI_BOX](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_ddi_box) structure that specifies the region of the destination subresource to copy data to. If *pDstBox* is **NULL**, the driver should copy to the entire destination subresource.

### `unnamedParam5`

*pSysMemUP* [in]

A pointer to the beginning address of the source data that **DefaultConstantBufferUpdateSubresourceUP(D3D11_1)** uses to update the destination subresource.

### `unnamedParam6`

*RowPitch*

The offset, in bytes, to move to the next row of source data.

### `unnamedParam7`

*DepthPitch*

The offset, in bytes, to move to the next depth slice of source data.

### `CopyFlags`

A value that specifies characteristics of copy operation as a bitwise **OR** of the values in the [D3D11_1_DDI_COPY_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1_ddi_copy_flags) enumeration type.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

The driver should not encounter any error, except for **D3DDDIERR_DEVICEREMOVED**. Therefore, if the driver passes any error, except for **D3DDDIERR_DEVICEREMOVED**, in a call to the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) function, the Direct3D runtime will determine that the error is critical. Even if the device was removed, the driver is not required to return **D3DDDIERR_DEVICEREMOVED**; however, if device removal interfered with the operation of **DefaultConstantBufferUpdateSubresourceUP(D3D11_1)** (which typically should not happen), the driver can return **D3DDDIERR_DEVICEREMOVED**.

## See also

[D3D11_1DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_devicefuncs)

[D3D11_1_DDI_COPY_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1_ddi_copy_flags)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)