# PFND3D11DDI_COPYSTRUCTURECOUNT callback function

## Description

The **CopyStructureCount** function copies the number of items in the filled portion (that is, the filled-size value) of an append buffer unordered access view (UAV) to an offset into a destination buffer.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hDstBuffer* [in]

A handle to a destination buffer to copy the filled-size value of an UAV to. To create this destination buffer, the runtime must have previously called the driver's [CreateResource(D3D11)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createresource) function with the **ResourceDimension** member of the [D3D11DDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_createresource) structure set to the D3D10DDIRESOURCE_BUFFER value.

### `unnamedParam3`

*DstAlignedByteOffset* [in]

The 4-byte aligned offset, in bytes, into the destination buffer that the *hDstBuffer* parameter specifies. **CopyStructureCount** copies the filled-size value of the append buffer view that the *hSrcView* parameter specifies to this offset in **hDstBuffer**. **DstAlignedByteOffset** must be a multiple of four.

### `unnamedParam4`

*hSrcView* [in]

A handle to the source append UAV, which must be an append buffer view. **CopyStructureCount** copies the filled-size value of this view to the destination buffer that the **hDstBuffer** parameter specifies. To create this append buffer view, the runtime must have previously called the driver's [CreateUnorderedAccessView](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createunorderedaccessview) function with the D3D11_DDI_BUFFER_UAV_FLAG_APPEND flag set.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

The driver should not encounter any error, except for D3DDDIERR_DEVICEREMOVED. Therefore, if the driver passes any error, except for D3DDDIERR_DEVICEREMOVED, in a call to the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) function, the Direct3D runtime determines that the error is critical. Even if the device is removed, the driver is not required to return D3DDDIERR_DEVICEREMOVED; however, if the device removal interferes with the operation of **CopyStructureCount** (which typically should not happen), the driver can return D3DDDIERR_DEVICEREMOVED.

**CopyStructureCount** takes the filled-size value of the append buffer UAV (a UAV that supports push and pop-up operations on structures like on a stack) and copies this value to an offset into the destination buffer. The graphics hardware uses a 4-byte filled-size value to keep track of how much data is filled in the append buffer UAV.

## See also

[CreateResource(D3D11)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createresource)

[CreateUnorderedAccessView](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createunorderedaccessview)

[D3D11DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_devicefuncs)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)