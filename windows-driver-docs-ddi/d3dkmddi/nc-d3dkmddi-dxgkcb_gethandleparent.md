# DXGKCB_GETHANDLEPARENT callback function

## Description

**DXGKCB_GETHANDLEPARENT** retrieves the parent resource from the specified allocation.

## Parameters

### `hAllocation` [in]

A handle to an allocation. This handle must be the kernel-mode handle that the DirectX graphics kernel subsystem (*Dxgkrnl.sys*) assigned for the allocation.

## Return value

**DXGKCB_GETHANDLEPARENT** returns a graphics subsystem-specific handle to the parent resource for the allocation that is associated with the handle that the **hAllocation** parameter specifies.

If **DXGKCB_GETHANDLEPARENT** returns a NULL handle, *Dxgkrnl.sys* was unable to resolve the handle to the parent resource for a reason such as the following possibilities:

* An invalid handle was received from the user-mode display driver because of a malicious attack or some other bug.
* Allocations had lifetime issues.

If a NULL handle is returned, the display miniport driver should fail its currently running DDI function with STATUS_INVALID_HANDLE.

## Remarks

For **DXGKCB_GETHANDLEPARENT** to return a resource handle, the handle in **hAllocation** must be an allocation handle that is associated with a resource; otherwise, **DXGKCB_GETHANDLEPARENT** returns NULL.

*DXGKCB_XXX* functions are implemented by *Dxgkrnl*. To use this callback function, call **DxgkCbGetHandleParent** via the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface).

## See also

[**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface)