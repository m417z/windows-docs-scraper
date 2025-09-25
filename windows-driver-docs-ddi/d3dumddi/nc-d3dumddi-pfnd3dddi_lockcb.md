# PFND3DDDI_LOCKCB callback function

## Description

The *pfnLockCb* function locks an allocation and obtains a pointer to the allocation from the display miniport driver or video memory manager.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in, out]

A pointer to a [D3DDDICB_LOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_lock) structure that describes the allocation to lock.

## Return value

*pfnLockCb* returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **S_OK** | The allocation was successfully locked. |
| **D3DERR_NOTAVAILABLE** | An aperture was not available. |
| **D3DERR_WASSTILLDRAWING** | The allocation was still being used for rendering. |
| **D3DDDIERR_CANTEVICTPINNEDALLOCATION** | The allocation could not be locked because of the unavailability of a deswizzling aperture and the inability to evict the allocation because it was pinned. |
| **E_OUTOFMEMORY** | [pfnLockCb]() could not complete because of insufficient memory (this situation occurs when the system is in an extreme low memory situation and there is not enough space to allocate the array of pages). |
| **E_INVALIDARG** | Parameters were validated and determined to be incorrect.
|
| **D3DDDIERR_DEVICEREMOVED** | [pfnLockCb]() could not cause the video memory manager and display miniport driver to perform the appropriate actions because a Plug and Play (PnP) stop or a Timeout Detection and Recovery (TDR) event occurred. The user-mode display driver function that called pfnLockCb(typically, the [Lock](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lock) or [ResourceMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourcemap) function) must return this error code back to the Direct3D runtime.<br>**Direct3D Version 9** Note: For more information about returning error codes, see [Returning Error Codes Received from Runtime Functions](https://learn.microsoft.com/windows-hardware/drivers/display/returning-error-codes-received-from-runtime-functions).<br>**Direct3D Versions 10 and 11** Note: If the driver function does not return a value (that is, has VOID for a return parameter type), the driver function calls the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) function to send an error code back to the runtime. For more information about handling error codes, see [Handling Errors](https://learn.microsoft.com/windows-hardware/drivers/display/handling-errors). |

This function might also return other HRESULT values.

## Remarks

The user-mode display driver can call the Microsoft Direct3D runtime's *pfnLockCb* function to lock an allocation and obtain a pointer to the allocation from the display miniport driver or video memory manager. The user-mode display driver typically calls *pfnLockCb* in response to a call to its [Lock](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lock) or [ResourceMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourcemap) function (or other variations of **ResourceMap** such as *DynamicIABufferMapDiscard*) to lock a resource or a surface within the resource. Before returning from the **Lock** or **ResourceMap** call, the user-mode display driver must first map the resource or surface to the appropriate allocation and then call *pfnLockCb* to lock the allocation. The allocation must be locked before it can be read from or written to because locking:

* Guarantees that the virtual address range for the allocation remains unchanged, valid, readable, and writable for the duration of the lock. The video memory manager provides this guarantee.
* Provides a way to synchronize the read and write operations of the allocation with graphics hardware accesses of the allocation. The video memory manager and display miniport driver perform the synchronization.

**Direct3D Version 9 Note:**

The user-mode display driver usually calls the *pfnLockCb* and [pfnUnlockCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_unlockcb) functions that correspond to every call to its [Lock](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lock) and [Unlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_unlock) functions, respectively, except when the driver handles resources in which the **Dynamic** bit-field flag was set in the **Flags** member of the [D3DDDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddiarg_createresource) structure when the resources were created. The runtime frequently requests that the driver lock these types of resources, often with the **NoOverwrite** bit-field flag set in the **Flags** member of the [D3DDDIARG_LOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_lock) structure. Because data in such resources should not be modified (as indicated by **NoOverwrite**), calling *pfnLockCb* for each lock request consumes excessive processing time. To prevent calling *pfnLockCb* for each lock request, the driver can cache the virtual memory pointer that it returns in the **pSurfData** member of D3DDDIARG_LOCK when its **Lock** function is called with the **NoOverwrite** bit-field flag set. However, the driver can continue to call *pfnLockCb* whenever its **Lock** function is called with either the **Discard** bit-field flag set or no flags set.

**Direct3D Versions 10 and 11 Note:**

The user-mode display driver usually calls the *pfnLockCb* and [pfnUnlockCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_unlockcb) functions that correspond to every call to its [ResourceMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourcemap) and [ResourceUnmap](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourceunmap) functions (or other variations of these functions). This does not happen when the driver handles resources in which the D3D10_DDI_USAGE_DYNAMIC value was set in the **Usage** member of the [D3D10DDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createresource) or [D3D11DDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_createresource) structure when the resources were created. The runtime frequently requests that the driver lock these types of resources, often by passing the D3D10_DDI_MAP_WRITE_NOOVERWRITE value to the *DDIMap* parameter in the call to **ResourceMap**. Because data in such resources should not be modified (as indicated by D3D10_DDI_MAP_WRITE_NOOVERWRITE), calling *pfnLockCb* for each lock request consumes excessive processing time. To prevent calling *pfnLockCb* for each lock request, the driver can cache the virtual memory pointer that it returns in the *pMappedSubResource* parameter when its *ResourceMap* function is called with D3D10_DDI_MAP_WRITE_NOOVERWRITE. However, the driver can continue to call *pfnLockCb* whenever its *ResourceMap* function is called with either the D3D10_DDI_MAP_WRITE_DISCARD value or 0 passed to the *DDIMap* parameter.

While the application does not hold an outstanding lock to the resource that is associated with the virtual memory pointer, the driver typically uncaches the virtual memory pointer by calling the [pfnUnlockCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_unlockcb) function before the driver calls the [pfnRenderCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_rendercb) function. If the lock is not uncached or if the lock cannot be uncached because the application still has the resource locked, the hardware might render from a locked allocation. The video memory manager cannot support this mode of operation if the allocation is in local video memory; therefore, the memory manager evicts the allocation to system or AGP memory when the memory manager detects this situation. If the allocation is not supported in the system or AGP memory segment, the memory manager fails the call to *pfnRenderCb* with D3DDDIERR_CANTRENDERLOCKEDALLOCATION. Therefore, vertex and index buffer allocations that are allocated in response to creating resources in which the **Dynamic** bit-field flag is set in the **Flags** member of D3DDDIARG_CREATERESOURCE (or the D3D10_DDI_USAGE_DYNAMIC value is set in the **Usage** member of D3D10DDIARG_CREATERESOURCE or D3D11DDIARG_CREATERESOURCE) should be supported in system or AGP segments.

Setting the **Discard** bit-field flag in the **Flags** member of [D3DDDICB_LOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_lock) in a call to *pfnLockCb* causes the video memory manager to create a new instance of the allocation that is being locked. The video memory manager represents the new instance by returning a new handle to the user-mode display driver in the **hAllocation** member of D3DDDICB_LOCK.

**Note** The display miniport driver's [DxgkDdiCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation) function is not called when a new instance of an allocation is created. Instances appear to the display miniport driver as allocations that are simultaneously paged in to multiple different locations.

The video memory manager might fail a lock in which the **Discard** bit-field flag is set because the video memory manager cannot create a new instance or reuse an existing instance of an allocation. When this failure occurs, the user-mode display driver should call the [pfnRenderCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_rendercb) function to flush its current command buffer to the kernel. This flush of the command buffer might retire some instances of the allocation that could not be locked by using the **Discard** bit-field flag.

After flushing its command buffer, the user-mode display driver must try locking the surface again by using both the **Discard** and **NoExistingReference** bit-field flags. The **NoExistingReference** bit-field flag indicates to the video memory manager that the driver does not currently have a reference to any instance of the allocation that is being locked queued in its command buffer. The video memory manager can then reuse any instance of the allocation to handle the lock, including the current instance.

After a call to *pfnLockCb* in which the **Discard** bit-field flag is set, the user-mode display driver should always check for an updated handle value in the **hAllocation** member of [D3DDDICB_LOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_lock). If a new allocation handle is provided, the user-mode display driver should update its internal data structure to reference the new allocation handle. The user-mode display driver should also add a re-programmed version of the locked allocation base address to the current command buffer (because allocation instances contain different base addresses). The video memory manager validates the use of allocation instances that are used by the driver and rejects DMA buffers that use the allocation instances incorrectly (that is, calls to [pfnPresentCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_presentcb) and [pfnRenderCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_rendercb) fail if they incorrectly use allocation instances). After the driver references a particular instance of an allocation, the driver can no longer reference a previous instance of the same allocation. For example, if a command buffer uses allocation A and currently uses instances A0 and A1, then as soon as A1 is used (that is, appears in the patch-location list) A0 becomes invalid. The display miniport driver can generate a patch-location list that references both A0 and A1. However, the references must be ordered (that is, A0 can be used first; A0 becomes invalid once A2 is used; A1 becomes invalid when A2 is used, and so on).

The user-mode display driver might call *pfnLockCb* for system memory allocations, even if the memory has not been preallocated, because the display miniport driver might actually be in the process of sending, through DMA, or asynchronously transferring those allocations to graphics hardware. Therefore, before an application is allowed to write to the surface, the display miniport driver and video memory manager must be notified so that they can block the lock if necessary.

The user-mode display driver can also lock subregions of an allocation. This type of lock is typically not necessary when an unswizzling or linearizing hardware aperture is available because, in this situation, the user-mode display driver can translate a lock on the entire allocation to the subregion by offsetting the pointer. However, when *pfnLockCb* fails by using D3DERR_NOTAVAILABLE to indicate that an aperture is not available, the memory manager requests the user-mode display driver to copy video memory contents. The user-mode display driver unswizzles or linearizes the video memory contents while copying them into another area of memory. In this situation, the user-mode display driver can supply a list of pages to copy to save large amounts of copying when locking small subregions in a large allocation. Note that the memory manager fails a call to *pfnLockCb* with D3DERR_NOTAVAILABLE if the user-mode display driver did not set the **LockEntire** bit-field flag in the **Flags** member of the [D3DDDICB_LOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_lock) structure and did not specify a page list in the **pPages** member of D3DDDICB_LOCK. If the user-mode display driver sets the **LockEntire** bit-field flag, it must also set the **NumPages** and **pPages** members of D3DDDICB_LOCK to 0 and **NULL**, respectively. The user-mode display driver should always supply a page list in **pPages** when locking an allocation that was created with a permanent backing store. In this situation, the memory manager uses the page list to mark as dirty only specific pages and is not required to copy the entire allocation from the backing store when it is used for rendering.

The user-mode display driver can call *pfnLockCb* to acquire multiple swizzling ranges for a single allocation (for example, one swizzling range for each MIP level). If the driver cannot acquire any one of the ranges, the Direct3D runtime evicts the entire allocation to handle the lock (all of the MIP levels) and reclaims all of the swizzling ranges.

When the user-mode display driver requests that a swizzling range be assigned to the allocation, the driver effectively requests access to the unswizzled bits of the allocation. For such requests, the video memory manager either pages in the allocation into a memory segment and sets up a swizzling range to access the allocation or pages in the allocation into a memory segment and then evicts the allocation to system memory while requesting that the driver unswizzle the allocation on the way to system memory. An allocation that was unswizzled to system memory is reswizzled (by being paged into video memory) before the GPU uses the allocation again. As a result, the driver cannot request a no-overwrite-type lock (by setting the **DonotWait** bit-field flag) when it acquires a swizzling range. Similarly, the driver cannot reference an allocation lock in such a way in a DMA buffer that is submitted to the GPU (because the DMA buffer will be rejected).

The user-mode display driver might lock a swizzled allocation without acquiring a swizzling range if the driver must access the bits of the allocation in a swizzled format. In this situation, the video memory manager provides the driver with a pointer to the swizzled bits of the allocation. However, the driver cannot request a pointer to the swizzled bits of the allocation while a request for the unswizzled bits is outstanding, and vice versa (that is, a lock is currently pending on the allocation with a swizzling range acquired).

The user-mode display driver should pass the **Discard** bit-field flag in the **Flags** member of D3DDDICB_LOCK in the *pfnLockCb* call in the following situations:

* When the Direct3D runtime passes the **Discard** bit-field flag in the **Flags** member of the [D3DDDIARG_LOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_lock) structure in the call to the user-mode display driver's [Lock](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lock) function
* When the runtime passes the D3D10_DDI_MAP_WRITE_DISCARD value to the *DDIMap* parameter in the call to the driver's [ResourceMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourcemap) function

Setting the **Discard** bit-field flag causes the memory manager to determine if it should rename the allocation or should cause the application thread to stall until the allocation is idle. For more information about renaming an allocation, see [Requesting to Rename an Allocation](https://learn.microsoft.com/windows-hardware/drivers/display/requesting-to-rename-an-allocation). The driver can use its own renaming support or the memory manager's renaming support. To use its own renaming support, the driver sets the **DonotWait** bit-field flag, in response to a [Lock](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lock) call with the **Discard** bit-field flag set, or in response to a [ResourceMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourcemap) call with the D3D10_DDI_MAP_WRITE_DISCARD value set. Setting the **DonotWait** bit-field flag causes the memory manager to fail the call to *pfnLockCb* with D3DERR_WASSTILLDRAWING if the graphics hardware is still using the allocation. Such a failure indicates to the user-mode display driver to rename or multiple-buffer the allocation.

**Note** The **DonotWait** bit-field flag has no effect on the memory manager if the **Discard** bit-field flag is also set.

The user-mode display driver should set the **IgnoreSync** bit-field flag in the **Flags** member of D3DDDICB_LOCK when it does not require the memory manager to check whether the graphics hardware is using the allocation. The user-mode display driver must then properly synchronize access to the allocation. If the **DonotWait** bit-field flag is not specified with the **IgnoreSync** bit-field flag, the memory manager ignores the **IgnoreSync** bit-field flag.

**Note** The **IgnoreSync** bit-field flag has no effect on the memory manager if the **Discard** bit-field flag is also set.

**Example**

The following code example shows how the **Discard** bit-field flag is used in a call to *pfnLockCb*.

```cpp
HRESULT hr;
D3DDDICB_LOCK LockData;
LockData.hAllocation = AllocationToLock;
LockData.Flags.Discard = TRUE;
hr = pfnLockCb(&LockData)
if (FAILED(hr)) {
    FlushAccumulatedCommandBufferToKernel();
    LockData.Flags.Discard = TRUE;
    LockData.Flags.NoExistingReference = TRUE;
    hr = pfnLockCb(&LockData);
    if (FAILED(hr)) {
        // Fails the lock to the application
    }
}
UpdateAllocationHandleInUMDDataStructure(LockData.hAllocation);
ProgramSurfaceBaseAddressInCurrentCommandBuffer(LockData.hAllocation);
```

## See also

[D3D10DDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createresource)

[D3D11DDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_createresource)

[D3DDDIARG_LOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_lock)

[D3DDDICB_LOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_lock)

[D3DDDI_DEVICECALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicecallbacks)

[Lock](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lock)

[ResourceMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourcemap)

[ResourceUnmap](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourceunmap)