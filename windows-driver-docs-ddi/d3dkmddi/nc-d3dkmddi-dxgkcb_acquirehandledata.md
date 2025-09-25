# DXGKCB_ACQUIREHANDLEDATA callback function

## Description

**DxgkcbAcquirehandledata** acquires a reference to an allocation.

## Parameters

### `unnamedParam1` [in]

Pointer to a [**DXGKARGCB_GETHANDLEDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_gethandledata) structure that describes an allocation handle returned by [**DxgkcbCreatecontextallocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_createcontextallocation).

## `unnamedParam2` [out]

Pointer to a release handle for the kernel-mode driver (KMD) to manage the lifetime of the reference to acquired allocation. The KMD uses this handle when it calls [**DxgkcbReleasehandledata**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_releasehandledata) to release the allocation reference.

## Return value

**DxgkcbAcquirehandledata** returns a handle to the allocation that the KMD requested a reference to. The KMD uses this handle for subsequent operations on the allocation or resource.

## Remarks

An application or user-mode driver can call [**D3DKMTDestroyAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreateallocation) at any time to destroy an allocation handle. Allocation destruction involves a request to the KMD to delete the allocation object that *Dxgkrnl* returned to them during allocation creation, so the KMD could end up with a stale pointer to freed memory. **DxgkcbAcquirehandledata** and [**DxgkcbReleasehandledata**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_releasehandledata) allow the driver to hold a reference on the *Dxgkrnl* object and ensure that *Dxgkrnl* doesn't destroy the allocation and the KMD-associated objects until after the release call is made.

*DXGKCB_XXX* functions are implemented by *Dxgkrnl*. To use this callback function, set the members of [**DXGKARGCB_GETHANDLEDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_gethandledata) and then call **DxgkCbAcquireHandleData** via the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface).

## See also

[**DXGKARGCB_GETHANDLEDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_gethandledata)

[**DxgkcbCreatecontextallocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_createcontextallocation)

[**DxgkcbReleasehandledata**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_releasehandledata)

[**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface)