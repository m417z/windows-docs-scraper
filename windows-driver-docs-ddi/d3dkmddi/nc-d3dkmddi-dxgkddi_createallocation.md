# DXGKDDI_CREATEALLOCATION callback function

## Description

The kernel-mode display driver's (KMD) **DxgkDdiCreateAllocation** function creates allocations of system or video memory.

## Parameters

### `hAdapter` [in]

A handle to a context block that is associated with a display adapter. The KMD previously provided this handle to *Dxgkrnl* in the **MiniportDeviceContext** output parameter of the [**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pCreateAllocation` [in/out]

A pointer to a [**DXGKARG_CREATEALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createallocation) structure that contains information for creating allocations.

## Return value

**DxgkDdiCreateAllocation** returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **STATUS_SUCCESS** | **DxgkDdiCreateAllocation** successfully created the allocation. |
| **STATUS_INVALID_PARAMETER** | The passed parameters contained errors that prevented **DxgkDdiCreateAllocation** from completing. |
| **STATUS_NO_MEMORY** | **DxgkDdiCreateAllocation** could not allocate memory that was required for it to complete. |
| **STATUS_GRAPHICS_DRIVER_MISMATCH** | The KMD isn't compatible with the user-mode display driver (UMD) that initiated the call to **DxgkDdiCreateAllocation**. |

## Remarks

After the UMD calls [**pfnAllocateCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_allocatecb), *Dxgkrnl* calls KMD's **DxgkDdiCreateAllocation** function to create the allocations. The KMD must interpret the private data (in the **pPrivateDriverData** member of the [**DXGK_ALLOCATIONINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfo) structure for each allocation) that is passed from the UMD and must determine the list of parameters that are required to create each allocation through the video memory manager. For more information about how the KMD supplies these parameters to the video memory manager, see [Specifying Segments When Creating Allocations](https://learn.microsoft.com/windows-hardware/drivers/display/specifying-segments-when-creating-allocations).

The KMD must return an allocation handle, which is typically a pointer to a private driver data structure that contains information about the allocation. The UMD can call the [**DxgkCbGetHandleData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_gethandledata) function anytime to retrieve the private data for an allocation handle. Therefore, the KMD isn't required to maintain a private allocation handle table. In fact, we strongly discourage private handle tables because they could become stale or out of sync with the DirectX graphics kernel subsystem in display-mode-switch scenarios such as fast user switch, hot unplug, and so on.

The user-mode display driver assigns an allocation to either a resource or a device. To determine whether the allocation belongs to a resource, the display miniport driver can check whether the **Resource** bit-field flag is set in the **Flags** member of the [**DXGKARG_CREATEALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createallocation) structure that the **pCreateAllocation** parameter of **DxgkDdiCreateAllocation** points to. If the allocation belongs to a resource, the display miniport driver can (but is not required to) return a resource handle, which is typically a pointer to a private driver data structure that describes the resource. If the DirectX graphics kernel subsystem calls **DxgkDdiCreateAllocation** to create an additional allocation for an existing resource, the **hResource** member of DXGKARG_CREATEALLOCATION contains the handle that was returned by the previous **DxgkDdiCreateAllocation** call for that resource. If necessary, the display miniport driver can change the resource handle during a call to **DxgkDdiCreateAllocation**.

If the user-mode display driver places a resource handle in a command buffer, the display miniport driver can retrieve the private data by calling [**DxgkCbGetHandleData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_gethandledata). The display miniport driver can also enumerate all of the resource's child allocations by calling the [**DxgkCbEnumHandleChildren**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_enumhandlechildren) function.

Beginning with Windows 7, if a display miniport driver processes a call to the **DxgkDdiCreateAllocation** function to create allocations for GDI hardware acceleration, the driver should set the size of the allocation (including the pitch value for CPU visible allocations), **pCreateAllocation**->**pAllocationInfo**->**Size**.

The resources that are created in the **DxgkDdiCreateAllocation** call belong to the adapter and not to the device. The display miniport driver should not reference the device data anywhere within the private allocation and resource data structures. Because of surface sharing, a resource might be in use after the destruction of the device that the user-mode display driver created the resource from.

**DxgkDdiCreateAllocation** should be made pageable.

### Allocating history buffers

Starting in Windows 8.1, when **DxgkDdiCreateAllocation** is called, the KMD can set the [**DXGK_ALLOCATIONINFOFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfoflags).**HistoryBuffer** member to indicate that the user-mode driver can manage the creation and destruction of history buffers.

## See also

[**DXGKARG_CREATEALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createallocation)

[**DXGK_ALLOCATIONINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfo)

[**DXGK_ALLOCATIONINFOFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfoflags)

[**DxgkCbEnumHandleChildren**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_enumhandlechildren)

[**DxgkCbGetHandleData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_gethandledata)

[**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)

[**pfnAllocateCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_allocatecb)