# DXGKCB_GETHANDLEDATA callback function

## Description

**DXGKCB_GETHANDLEDATA** retrieves the private data associated with an allocation.

## Parameters

## `unnamedParam1`

[in] A pointer to a [**DXGKARGCB_GETHANDLEDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_gethandledata) structure that describes the allocation data to retrieve.

## Return value

**DXGKCB_GETHANDLEDATA** returns a buffer that contains the private data for the allocation.

If **DXGKCB_GETHANDLEDATA** returns a NULL pointer, the DirectX graphics kernel subsystem was unable to resolve the handle that is supplied in the **hObject** member of the [**DXGKARGCB_GETHANDLEDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_gethandledata) structure to private data for a reason such as the following possibilities:

* An invalid handle was received from the user-mode display driver because of a malicious attack or some other bug.
* Allocations had lifetime issues.

If a NULL pointer is returned, the display miniport driver should fail its currently running DDI function with STATUS_INVALID_HANDLE.

## Remarks

When the DirectX graphics kernel subsystem calls the display miniport driver's [**DxgkDdiCreateAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation) function to create handles to allocations, the display miniport driver can create private data for each allocation handle. The display miniport driver can subsequently call the **DXGKCB_GETHANDLEDATA** function to retrieve private data for each graphics subsystem-specific handle. Therefore, the display miniport driver is not required to maintain a private allocation handle table.

If the **DeviceSpecific** bit-field flag is set in the **Flags** member of the [**DXGKARGCB_GETHANDLEDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_gethandledata) structure that **pData** points to, **DXGKCB_GETHANDLEDATA** returns the device-specific data that is associated with the device-specific handle that the driver returned from the call to its [**DxgkDdiOpenAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_openallocationinfo) function. Note that the **DeviceSpecific** bit-field flag is valid only if the display miniport driver also sets the **Type** member of **DXGKARGCB_GETHANDLEDATA** to the **DXGK_HANDLE_ALLOCATION** enumeration value for the handle in the **hObject** member of **DXGKARGCB_GETHANDLEDATA**.

*DXGKCB_XXX* functions are implemented by *Dxgkrnl*. To use this callback function, set the members of [**DXGKARGCB_GETHANDLEDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_gethandledata) and then call **DxgkCbGetHandleData** via the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface).

### Example

The following code example shows an implementation of [**DxgkDdiOpenAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_openallocationinfo) in which **DXGKCB_GETHANDLEDATA** is called.

```cpp
NTSTATUS
DxgkDdiOpenAllocation(
    VOID    *InterfaceContext,
    CONST DXGKARG_OPENALLOCATION    *pDDIDAData)
{
    DWORD dwIdx;
    DXGKRNL_INTERFACE              *pCallback;
    PR2D3DDevice                    pR2D3DDev;
    PHW_DEVICE_EXTENSION            pAdapter;

    pR2D3DDev = (PR2D3DDevice)InterfaceContext;
    pAdapter  = (PHW_DEVICE_EXTENSION)pR2D3DDev->pAdapter;
    pCallback = &(pAdapter->ddiCallback);

    for (dwIdx=0; dwIdx < pDDIDAData->NumAllocations; dwIdx++) {
        DXGKARGCB_GETHANDLEDATA  getHandleData = {0};
        R2AllocationInfo*  pAllocInfo;

        getHandleData.hObject = pDDIDAData->pOpenAllocation[dwIdx].hAllocation;
        getHandleData.Type    = DXGK_HANDLE_ALLOCATION;
        pAllocInfo = (PR2AllocationInfo)pCallback->DxgkCbGetHandleData(&getHandleData);
        pDDIDAData->pOpenAllocation[dwIdx].hDeviceSpecificAllocation = (HANDLE)pAllocInfo;
        pAllocInfo->vidMemData.hAllocation = pDDIDAData->pOpenAllocation[dwIdx].hAllocation;
    }
    return STATUS_SUCCESS;
}
```

## See also

[**DXGKARGCB_GETHANDLEDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_gethandledata)

[**DxgkDdiCreateAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation)

[**DxgkDdiOpenAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_openallocationinfo)

[**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface)