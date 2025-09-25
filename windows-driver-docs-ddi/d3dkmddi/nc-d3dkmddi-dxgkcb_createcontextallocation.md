# DXGKCB_CREATECONTEXTALLOCATION callback function

## Description

**DXGKCB_CREATECONTEXTALLOCATION** allocates a GPU context or device-specific context.

## Parameters

### `unnamedParam1` [in/out]

A pointer to a [**DXGKARGCB_CREATECONTEXTALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_createcontextallocation) structure that specifies the attributes of the context to be allocated.

## Return value

**DXGKCB_CREATECONTEXTALLOCATION** returns **STATUS_SUCCESS** if it succeeds. Otherwise, it returns one of the error codes defined in *Ntstatus.h*.

## Remarks

Starting with WDDM 1.2, display miniport drivers can allocate a GPU-specific context (**GPU context allocation**) or a device-specific context (**device context allocation**).

A GPU context allocation allows GPUs to store context state from DMA buffers that are preempted in the middle of their execution. Drivers create allocations associated with a GPU context to save its state when it is necessary. The operating system ensures that the context allocation is resident before a command from this context is placed in the GPU's hardware execution queue. The context will stay resident until a command from another context is placed in the hardware execution queue.

In addition, the operating system supports lazy GPU context switching by assuming that hardware context state is retained on the GPU after completing a command that belongs to the context. In this way, contexts are only switched on the GPU when a command from a different context is submitted to the hardware queue.

*DXGKCB_XXX* functions are implemented by *Dxgkrnl*. To use this callback function, set the members of [**DXGKARGCB_ALLOCATEPAGESFORMDL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_allocatepagesformdl) and then call **DxgkCbCreateContextAllocation** via the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface).

### GPU context allocations

GPU context allocations can only be made for non-system contexts. The display miniport driver creates these contexts by calling [**DxgkDdiCreateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createcontext). To create a non-system context, the driver sets the **SystemContext** member of a [**DXGK_CREATECONTEXTFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_createcontextflags) structure to zero, and passes a pointer to this structure in the **pCreateContext** parameter.

A device context allocation follows a similar model, except that it will remain resident for any context that belongs to the device that it’s associated with. This model allows drivers to use GPU context allocations for storing GPU context save area (CSA) data and to use device context allocations for storing page table data.

### Device context allocations

Device context allocations can only be made for non-system devices. The display miniport driver creates these devices by calling [**DxgkDdiCreateDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdevice). To create a non-system device, the driver sets the **Flags.SystemDevice** member of a [**DXGK_CREATEDEVICEFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_createdeviceflags) structure to zero, and passes a pointer to this structure in the **pCreateDevice** parameter.

The display miniport driver calls [**DXGKCB_DESTROYCONTEXTALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_destroycontextallocation) to free the context resources that were allocated through **DxgkCbCreateContextAllocation**.

### Virtual addresses for destination context allocations

To ensure that the operating system sets a valid (non-NULL) virtual address for the destination context allocation (**InitContextResource->Destination->VirtualAddress** member of the [**DXGKARG_BUILDPAGINGBUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_buildpagingbuffer) structure), when the display miniport driver calls **DxgkCbCreateContextAllocation** it must:

* Set the **CpuVisible** and **Protected** members of the [**DXGK_ALLOCATIONINFOFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfoflags) structure.
* Page in the allocation only to aperture segments by setting the **SupportedSegmentSet** member of the [**DXGKARGCB_CREATECONTEXTALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_createcontextallocation) structure.

## See also

[**DXGK_ALLOCATIONINFOFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfoflags)

[**DXGK_CREATECONTEXTFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_createcontextflags)

[**DXGK_CREATEDEVICEFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_createdeviceflags)

[**DXGKARG_BUILDPAGINGBUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_buildpagingbuffer)

[**DXGKARGCB_CREATECONTEXTALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_createcontextallocation)

[**DXGKCB_DESTROYCONTEXTALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_destroycontextallocation)

[**DxgkDdiCreateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createcontext)

[**DxgkDdiCreateDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdevice)

[**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface)