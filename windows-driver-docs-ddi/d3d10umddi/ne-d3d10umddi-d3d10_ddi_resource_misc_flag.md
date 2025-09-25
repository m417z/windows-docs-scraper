# D3D10_DDI_RESOURCE_MISC_FLAG enumeration

## Description

**D3D10_DDI_RESOURCE_MISC_FLAG** is a bitmask of flag values that identify miscellaneous information about a resource.

## Constants

### `D3D10_DDI_RESOURCE_AUTO_GEN_MIP_MAP:0x00000001L`

The resource can be used with the [**GenMips**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_genmips) function.

### `D3D10_DDI_RESOURCE_MISC_SHARED:0x00000002L`

The resource can be shared by multiple devices and processes.

### `D3D10_DDI_RESOURCE_MISC_DISCARD_ON_PRESENT:0x00000008L`

The resource is not required to persist across presentations.

For more information about this value, see the Remarks section of the [**CreateResource(D3D10)**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createresource) reference page.

Supported starting with Windows Server 2008, and Windows Vista with Service Pack 1 (SP1).

### `D3D11_DDI_RESOURCE_MISC_DRAWINDIRECT_ARGS:0x00000010L`

The resource is a buffer that the runtime can use as the argument buffer in a call to the driver's [**DrawIndexedInstancedIndirect**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_drawindexedinstancedindirect), [**DrawInstancedIndirect**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_drawinstancedindirect), or [**DispatchIndirect**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_dispatchindirect) function.

Supported starting with Windows 7.

### `D3D11_DDI_RESOURCE_MISC_BUFFER_ALLOW_RAW_VIEWS:0x00000020L`

The resource is a buffer on which the driver's [**CreateShaderResourceView(D3D11)**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createshaderresourceview) function can create a raw-format view. A raw-format view is created through a call to the driver's **CreateShaderResourceView(D3D11)** function with the D3D11_DDI_BUFFEREX_SRV_FLAG_RAW flag set in the **BufferEx** member of the [**D3D11DDIARG_CREATESHADERRESOURCEVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_createshaderresourceview) structure. Raw-format views allow to read (and write in the case of unordered access view (UAV) objects) up to four DWORD values in one instruction.

Supported starting with Windows 7.

### `D3D11_DDI_RESOURCE_MISC_BUFFER_STRUCTURED:0x00000040L`

The resource is a buffer that has its memory sectioned into equally sized pieces (structures). The structure size of each piece is provided in the resource declaration. The drivers might be able to use this information to optimize memory layout.

Supported starting with Windows 7.

### `D3D11_DDI_RESOURCE_MISC_RESOURCE_CLAMP:0x00000080L`

The resource must consider any resource clamp, which a call to the driver's [**SetResourceMinLOD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_setresourceminlod) function applies.

Supported starting with Windows 7.

### `D3D10_DDI_RESOURCE_MISC_REMOTE:0x00000400:l`

This value is for internal use only. Do not use.

### `D3D11_1DDI_RESOURCE_MISC_RESTRICTED_CONTENT:0x00000800L`

The resource can contain protected content. This value should be used only if the driver and hardware support content protection.

Supported starting with Windows 8.

### `D3D11_1DDI_RESOURCE_MISC_RESTRICT_SHARED_RESOURCE_DRIVER:0x00001000L`

The driver should restrict access to the shared surface. This value should be used only when a shared surface is created. The process that is creating the surface is always allowed to open the shared resource.

Supported starting with Windows 8.

### `D3DWDDM1_3DDI_RESOURCE_MISC_CROSS_ADAPTER:0x00002000L`

The resource is a shared cross-adapter resource.

The user-mode display driver should record information about the cross-adapter resource in a private driver data structure. The display miniport driver can call the [**DxgkCbGetHandleData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_gethandledata) function to retrieve this private data.

The DirectX graphics kernel subsystem calls the [**DxgkDdiDescribeAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_describeallocation) function to get information on the cross-adapter resource when it needs to open the resource on another adapter. The display miniport must ensure that this information is correct.

Supported starting with Windows 8.1.

### `D3DWDDM1_3DDI_RESOURCE_MISC_TILED:0x00004000L`

The resource is tiled.

Supported starting with Windows 8.1.

### `D3DWDDM1_3DDI_RESOURCE_MISC_TILE_POOL:0x00008000L`

The resource is a tile pool. Must be a buffer with [**D3D10_DDI_RESOURCE_USAGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_resource_usage) usage type **D3D10_DDI_USAGE_DEFAULT**.

Supported starting with Windows 8.1.

### `D3DWDDM2_0DDI_RESOURCE_MISC_HW_PROTECTED:0x00010000L`

The resource should be created such that it will be protected by the hardware.

Supported starting with Windows 10.

### `D3DWDDM2_0DDI_RESOURCE_MISC_DISPLAYABLE_SURFACE:0x00020000L`

The resource contains a displayable surface.

Supported starting with Windows 10.

### `D3DWDDM2_0DDI_RESOURCE_MISC_CONTAINS_HW_PROTECTED:0x00040000L`

The decoder input buffer contains encrypted protected content. The hardware does not need to protect these buffers (as they are encrypted), but the driver may need to allocate these buffers differently so they can efficiently interact with their decryption hardware.

Supported starting with Windows 10.

### `D3DWDDM2_5DDI_RESOURCE_MISC_PHYSICALLY_CONTIGUOUS:0x01000000L`

The resource is physically contiguous. Supported starting in Windows 10 version 1809 (WDDM 2.5).

## See also

[**CreateResource(D3D10)**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createresource)

[**CreateShaderResourceView(D3D11)**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createshaderresourceview)

[**D3D10DDIARG_CREATERESOURCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createresource)

[**D3D10_DDI_RESOURCE_USAGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_resource_usage)

[**D3D11DDIARG_CREATESHADERRESOURCEVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_createshaderresourceview)

[**DispatchIndirect**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_dispatchindirect)

[**DrawIndexedInstancedIndirect**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_drawindexedinstancedindirect)

[**DrawInstancedIndirect**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_drawinstancedindirect)

[**DxgkCbGetHandleData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_gethandledata)

[**GenMips**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_genmips)

[**SetResourceMinLOD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_setresourceminlod)