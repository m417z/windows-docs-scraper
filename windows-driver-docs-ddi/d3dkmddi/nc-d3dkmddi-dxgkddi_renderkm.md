# DXGKDDI_RENDERKM callback function

## Description

For display adapters that support GDI hardware acceleration, the **DxgkDdiRenderKm** function generates a direct memory access (DMA) buffer from the command buffer that the kernel-mode Canonical Display Driver (CDD) passed.

## Parameters

### `hContext` [in]

A handle to the device context for the DMA and command buffers. The display miniport driver's [**DxgkDdiCreateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createcontext) function previously returned this handle in the **hContext** member of the [**DXGKARG_CREATECONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createcontext) structure that the **pCreateContext** parameter of **DxgkDdiCreateContext** points to.

If the driver does not support context creation, the Microsoft DirectX graphics kernel subsystem replaces the handle to the context with a handle to the device. The display miniport driver's [**DxgkDdiCreateDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdevice) function previously returned the device handle in the **hDevice** member of the [**DXGKARG_CREATEDEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createdevice) structure that the **pCreateDevice** parameter of **DxgkDdiCreateDevice** points to.

### `pRenderKmArgs` [in/out]

A pointer to a [**DXGKARG_RENDER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_render) structure that contains information about the DMA buffer and a formatted command buffer.

If the display miniport driver supports GDI hardware acceleration, **pRenderKmArgs**->**pCommand** points to the [**DXGK_RENDERKM_COMMAND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_renderkm_command) command buffer.

The driver must translate the input command buffer into DMA buffer commands and build the patch location list.

## Return value

**DxgkDdiRenderKm** returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **STATUS_SUCCESS** | The entire command buffer was translated. |
| **STATUS_NO_MEMORY** | **DxgkDdiRenderKm** could not allocate memory that was required for it to complete. |
| **STATUS_GRAPHICS_INSUFFICIENT_DMA_BUFFER** | The current DMA buffer is depleted. |
| **STATUS_INVALID_PARAMETER** | **DxgkDdiRenderKm** detected instruction parameters that graphics hardware could not support; however, the graphics hardware can support the instructions themselves. The driver is not required to return this error code. Instead, it can return STATUS_ILLEGAL_INSTRUCTION when it detects unsupported instruction parameters. |
| **STATUS_INVALID_USER_BUFFER** | **DxgkDdiRenderKm** detected data or instruction underrun or overrun. That is, the driver received less or more instructions or data than expected. The driver is not required to return this error code. Instead, it can return STATUS_ILLEGAL_INSTRUCTION when it detects data or instruction underrun or overrun. |
| **STATUS_INVALID_HANDLE** | **DxgkDdiRenderKm** detected an invalid handle in the command buffer. |
| **STATUS_GRAPHICS_GPU_EXCEPTION_ON_DEVICE** | The display miniport driver detected an error in the DMA stream. The graphics context device is placed in a lost state if the driver returns this error code. |

## Remarks

The DirectX graphics kernel subsystem calls the display miniport driver's **DxgkDdiRenderKm** function to generate a DMA buffer from the command buffer that is passed by the kernel-mode Canonical Display Driver (CDD) provided by the operating system. In addition to the output DMA buffer, the display miniport driver should also generate a list of output patch locations. The video memory manager uses this list to split and patch DMA buffers appropriately.

Access to the kernel buffers does not require protection from ```try/except``` code.

The display miniport driver is not required to use information that the CDD provides if it can re-create the information more optimally. For example, if the **pRender**->**pPatchLocationListIn** member is empty because the user-mode display driver did not provide an input patch-location list, the display miniport driver can generate the content of the **pRender**->**pPatchLocationListOut** member based on the content of the command buffer instead.

In addition to the device-specific handle, the DirectX graphics kernel subsystem provides the display miniport driver with the last known GPU segment address for each allocation. If allocation index **N** is currently paged out, the DirectX graphics kernel subsystem sets the **SegmentId** member of the **N**th element of the **pAllocationList** member of [**DXGKARG_RENDER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_render) to zero. If the **SegmentId** member of the **N**th element of the allocation list is not set to zero, the display miniport driver must patch the generated DMA buffer with the provided segment address information before the DirectX graphics kernel subsystem calls the [**DxgkDdiPatch**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_patch) function to repatch the DMA buffer. The driver must perform this initial patching when requested because the DirectX graphics kernel subsystem might not call the **DxgkDdiPatch** function on a DMA buffer that the driver should have properly patched.

Even though the driver's **DxgkDdiRenderKm** function performs the initial DMA buffer patching as described earlier, the driver must still insert all the references to allocations into the output patch-location list that the **pPatchLocationListOut** member of [**DXGKARG_RENDER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_render) specifies. This list must contain all of the references because the addresses of the allocations might change before the DMA buffer is submitted to the GPU; therefore, the DirectX graphics kernel subsystem will call the [**DxgkDdiPatch**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_patch) function to repatch the DMA buffer.

To unbind an allocation, the display miniport driver can specify an element in the allocation list that references a **NULL** handle and then can use a patch-location element that references that **NULL** allocation. Typically, the driver should use the first element of the allocation list (element 0) as the **NULL** element.

In guaranteed contract DMA mode, when the display miniport driver translates a command buffer to a DMA buffer, the CDD must guarantee enough resources for the translation command. If enough resources do not exist for the translation, the display miniport driver must reject the DMA buffer. For more information, see [Using the Guaranteed Contract DMA Buffer Model](https://learn.microsoft.com/windows-hardware/drivers/display/using-the-guaranteed-contract-dma-buffer-model).

**DxgkDdiRenderKm** should be made pageable.

## See also

[**D3DDDI_ALLOCATIONLIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_allocationlist)

[**DXGKARG_CREATECONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createcontext)

[**DXGKARG_CREATEDEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createdevice)

[**DXGK_ALLOCATIONLIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationlist)

[**DXGK_RENDERKM_COMMAND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_renderkm_command)

[**DxgkDdiCreateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createcontext)

[**DxgkDdiCreateDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdevice)

[**DxgkDdiOpenAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_openallocationinfo)

[**DxgkDdiPatch**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_patch)

[**DxgkDdiRender**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_render)