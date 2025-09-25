# DXGKCB_ENUMHANDLECHILDREN callback function

## Description

**DXGKCB_ENUMHANDLECHILDREN** enumerates the allocations associated with a given resource, one allocation at a time.

## Parameters

### `unnamedParam1` [in]

Pointer to a [**DXGKARGCB_ENUMHANDLECHILDREN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_enumhandlechildren) structure that describes the parent resource and the index of the child allocation to retrieve.

## Return value

**DXGKCB_ENUMHANDLECHILDREN** returns the *Dxgkrnl*-specific handle to the child allocation that **pData** describes. To retrieve the device-specific *data* for the handle, the display miniport driver must call the [**DXGKCB_GETHANDLEDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_gethandledata) function.

**DXGKCB_ENUMHANDLECHILDREN** returns a NULL handle if the child-allocation index value supplied in the **Index** member of the [**DXGKARGCB_ENUMHANDLECHILDREN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_enumhandlechildren) structure exceeds the number of allocations that are associated with the parent resource. If **DXGKCB_ENUMHANDLECHILDREN** unexpectedly returns a NULL handle, the DirectX graphics kernel subsystem was unable to resolve the handle to the parent resource, for a reason such as the following possibilities:

* An invalid handle was received from the user-mode display driver because of a malicious attack or some other bug.
* Allocations had lifetime issues.

If a **NULL** handle is returned unexpectedly, the display miniport driver should fail its currently running DDI function with STATUS_INVALID_HANDLE.

## Remarks

A display miniport driver can call **DXGKCB_ENUMHANDLECHILDREN** in a loop to enumerate all of the allocations that are associated with a resource.

The allocation handle indices are zero-based. If the display miniport driver sets [**pData->Index**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_enumhandlechildren) to 0, **DXGKCB_ENUMHANDLECHILDREN** returns the first allocation handle; if **Index** is set to 1, **DXGKCB_ENUMHANDLECHILDREN** returns the second allocation handle; and so on. If **Index** is greater than the number of allocations that are associated with the resource, **DXGKCB_ENUMHANDLECHILDREN** returns **NULL**.

*DXGKCB_XXX* functions are implemented by *Dxgkrnl*. To use this callback function, set the appropriate members of [**DXGKARGCB_ENUMHANDLECHILDREN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_enumhandlechildren) and then call **DxgkCbEnumHandleChildren** via the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface).

## See also

[**DXGKARGCB_ENUMHANDLECHILDREN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_enumhandlechildren)

[**DXGKCB_GETHANDLEDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_gethandledata)

[**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface)