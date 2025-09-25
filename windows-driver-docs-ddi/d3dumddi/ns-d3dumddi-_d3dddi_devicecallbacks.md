# D3DDDI_DEVICECALLBACKS structure

## Description

The **D3DDDI_DEVICECALLBACKS** structure contains Microsoft Direct3D runtime callback functions that the user-mode display driver can use.

## Members

### `pfnAllocateCb`

A pointer to the [pfnAllocateCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_allocatecb) function, which the user-mode display driver uses to request that the Direct3D runtime create a memory allocation for use by the driver.

### `pfnDeallocateCb`

A pointer to the [pfnDeallocateCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_deallocatecb) function, which the user-mode display driver uses to request that the Direct3D runtime free memory that was previously allocated.

### `pfnSetPriorityCb`

A pointer to the [pfnSetPriorityCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setprioritycb) function, which the user-mode display driver uses to set the priority of a resource or list of allocations.

### `pfnQueryResidencyCb`

A pointer to the [pfnQueryResidencyCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_queryresidencycb) function, which the user-mode display driver uses to query the residency status of a resource or list of allocations.

### `pfnSetDisplayModeCb`

A pointer to the [pfnSetDisplayModeCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setdisplaymodecb) function, which the user-mode display driver uses to set an allocation for displaying.

### `pfnPresentCb`

A pointer to the [pfnPresentCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_presentcb) function, which the user-mode display driver uses to submit a present command to the display miniport driver.

### `pfnRenderCb`

A pointer to the [pfnRenderCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_rendercb) function, which the user-mode display driver uses to submit a command buffer to the display miniport driver.

### `pfnLockCb`

A pointer to the [pfnLockCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lockcb) function, which the user-mode display driver uses to request a lock from the display miniport driver. This lock cannot be handled completely by the user-mode display driver.

### `pfnUnlockCb`

A pointer to the [pfnUnlockCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_unlockcb) function, which the user-mode display driver uses to call the display miniport driver for an unlock. This unlock cannot be handled completely by the user-mode display driver.

### `pfnEscapeCb`

A pointer to the [pfnEscapeCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_escapecb) function, which the user-mode display driver uses to share information with the display miniport driver.

### `pfnCreateOverlayCb`

A pointer to the [pfnCreateOverlayCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createoverlaycb) function, which the user-mode display driver uses to create and display a kernel-mode overlay object.

### `pfnUpdateOverlayCb`

A pointer to the [pfnUpdateOverlayCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_updateoverlaycb) function, which the user-mode display driver uses to modify a kernel-mode overlay object.

### `pfnFlipOverlayCb`

A pointer to the [pfnFlipOverlayCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_flipoverlaycb) function, which the user-mode display driver uses to change the allocation that the overlay displays.

### `pfnDestroyOverlayCb`

A pointer to the [pfnDestroyOverlayCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroyoverlaycb) function, which the user-mode display driver uses to destroy a kernel-mode overlay object and stop the overlay from being displayed.

### `pfnCreateContextCb`

A pointer to the [pfnCreateContextCb](https://learn.microsoft.com/previous-versions/ff568895(v=vs.85)) function, which the user-mode display driver uses to create a context to submit requests to.

### `pfnDestroyContextCb`

A pointer to the [pfnDestroyContextCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroycontextcb) function, which the user-mode display driver uses to destroy a context that [pfnCreateContextCb](https://learn.microsoft.com/previous-versions/ff568895(v=vs.85)) created.

### `pfnCreateSynchronizationObjectCb`

A pointer to the [pfnCreateSynchronizationObjectCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createsynchronizationobjectcb) function, which the user-mode display driver uses to create a synchronization object.

### `pfnDestroySynchronizationObjectCb`

A pointer to the [pfnDestroySynchronizationObjectCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroysynchronizationobjectcb) function, which the user-mode display driver uses to destroy a synchronization object that [pfnCreateSynchronizationObjectCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createsynchronizationobjectcb) created.

### `pfnWaitForSynchronizationObjectCb`

A pointer to the [pfnWaitForSynchronizationObjectCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_waitforsynchronizationobjectcb) function, which the user-mode display driver uses to wait for synchronization events to occur and then uses to return.

### `pfnSignalSynchronizationObjectCb`

A pointer to the [pfnSignalSynchronizationObjectCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_signalsynchronizationobjectcb) function, which the user-mode display driver uses to signal that synchronization events are no longer owned by a context.

### `pfnSetAsyncCallbacksCb`

A pointer to the [pfnSetAsyncCallbacksCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setasynccallbackscb) function that the user-mode display driver uses to notify the Direct3D runtime whether the runtime will start or stop receiving calls to the runtime's callback functions from a worker thread.

Only DirectX 9 and Direct 9L versions of the runtime support the [pfnSetAsyncCallbacksCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setasynccallbackscb) function. DirectX 10 and later versions of the runtime set the **pfnSetAsyncCallbacksCb** member to NULL when the runtime calls the user-mode display driver's [CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice) function to create a rendering device.

### `pfnSetDisplayPrivateDriverFormatCb`

A pointer to the [pfnSetDisplayPrivateDriverFormatCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setdisplayprivatedriverformatcb) function that the user-mode display driver uses to change the format of the shared primary surface.

### `pfnOfferAllocationsCb`

A pointer to the [pfnOfferAllocationsCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_offerallocationscb) function, which a WDDM 1.2 and later user-mode display driver calls to offer video memory allocations for reuse.

Supported starting with Windows 8.

### `pfnReclaimAllocationsCb`

A pointer to the [pfnReclaimAllocationsCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_reclaimallocationscb) function, which a WDDM 1.2 and later user-mode display driver calls to reclaim access to video memory allocations that were previously offered for reuse.

Supported starting with Windows 8.

### `pfnCreateSynchronizationObject2Cb`

A pointer to the [pfnCreateSynchronizationObject2Cb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createsynchronizationobject2cb) function, which a WDDM 1.2 and later user-mode display driver uses to create a GPU synchronization object.

Supported starting with Windows 8.

### `pfnWaitForSynchronizationObject2Cb`

A pointer to the [pfnWaitForSynchronizationObject2Cb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_waitforsynchronizationobject2cb) function, which a WDDM 1.2 and later user-mode display driver uses to wait for GPU synchronization events to occur and then uses to return.

Supported starting with Windows 8.

### `pfnSignalSynchronizationObject2Cb`

A pointer to the [pfnSignalSynchronizationObject2Cb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_signalsynchronizationobject2cb) function, which a WDDM 1.2 and later user-mode display driver uses to signal that GPU synchronization events are no longer owned by a context.

Supported starting with Windows 8.

### `pfnPresentMultiPlaneOverlayCb`

A pointer to the [pfnPresentMultiPlaneOverlayCb (D3D)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_presentmultiplaneoverlaycb) function, which a WDDM 1.3 and later user-mode display driver uses to copy content from a source multiplane overlay allocation to a destination allocation.

Supported starting with Windows 8.1.

### `pfnLogUMDMarkerCb`

A pointer to the [pfnLogUMDMarkerCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_logumdmarkercb) function, which a WDDM 1.3 and later user-mode display driver calls to log a custom Event Tracing for Windows (ETW) marker event.

Supported starting with Windows 8.1.

### `pfnMakeResidentCb`

A pointer to the [pfnMakeResidentCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_makeresidentcb) function.

### `pfnEvictCb`

A pointer to the [pfnEvictCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_evictcb) function.

### `pfnWaitForSynchronizationObjectFromCpuCb`

A pointer to the [pfnWaitForSynchronizationObjectFromCpuCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_waitforsynchronizationobjectfromcpucb) function.

### `pfnSignalSynchronizationObjectFromCpuCb`

A pointer to the [pfnSignalSynchronizationObjectFromCpuCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_signalsynchronizationobjectfromcpucb) function.

### `pfnWaitForSynchronizationObjectFromGpuCb`

A pointer to the [pfnWaitForSynchronizationObjectFromGpuCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_waitforsynchronizationobjectfromgpucb) function.

### `pfnSignalSynchronizationObjectFromGpuCb`

A pointer to the [pfnSignalSynchronizationObjectFromGpuCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_signalsynchronizationobjectfromgpucb) function.

### `pfnCreatePagingQueueCb`

A pointer to the [pfnCreatePagingQueueCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createpagingqueuecb) function.

### `pfnDestroyPagingQueueCb`

A pointer to the [pfnDestroyPagingQueueCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroypagingqueuecb) function.

### `pfnLock2Cb`

A pointer to the [pfnLock2Cb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lock2cb) function.

### `pfnUnlock2Cb`

A pointer to the [pfnUnlock2Cb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_unlock2cb) function.

### `pfnInvalidateCacheCb`

A pointer to the [pfnInvalidateCacheCb](https://learn.microsoft.com/previous-versions/visualstudio) function.

### `pfnReserveGpuVirtualAddressCb`

A pointer to the [pfnReserveGpuVirtualAddressCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_reservegpuvirtualaddresscb) function.

### `pfnMapGpuVirtualAddressCb`

A pointer to the [pfnMapGpuVirtualAddressCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_mapgpuvirtualaddresscb) function.

### `pfnFreeGpuVirtualAddressCb`

A pointer to the [pfnFreeGpuVirtualAddressCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_freegpuvirtualaddresscb) function.

### `pfnUpdateGpuVirtualAddressCb`

A pointer to the [pfnUpdateGpuVirtualAddressCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_updategpuvirtualaddresscb) function.

### `pfnCreateContextVirtualCb`

A pointer to the [pfnCreateContextVirtualCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createcontextvirtualcb) function.

### `pfnSubmitCommandCb`

A pointer to the [pfnSubmitCommandCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_submitcommandcb) function.

### `pfnDeallocate2Cb`

A pointer to the [pfnDeallocate2Cb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_deallocate2cb) function.

### `pfnSignalSynchronizationObjectFromGpu2Cb`

A pointer to the [pfnSignalSynchronizationObjectFromGpu2Cb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_signalsynchronizationobjectfromgpu2cb) function.

### `pfnReclaimAllocations2Cb`

A pointer to the [pfnReclaimAllocations2Cb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_reclaimallocations2cb) function.

### `pfnGetResourcePresentPrivateDriverDataCb`

A pointer to the [pfnGetResourcePresentPrivateDriverDataCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getresourcepresentprivatedriverdatacb) function.

### `pfnUpdateAllocationPropertyCb`

A pointer to the [pfnUpdateAllocationPropertyCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_updateallocationpropertycb) function.

### `pfnOfferAllocations2Cb`

A pointer to the [pfnOfferAllocations2Cb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_offerallocations2cb) function.

### `pfnReclaimAllocations3Cb`

A pointer to the [pfnReclaimAllocations3Cb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_reclaimallocations3cb) function.

### `pfnAcquireResourceCb`

### `pfnReleaseResourceCb`

### `pfnCreateHwContextCb`

A pointer to a [PFND3DDDI_CREATEHWCONTEXTCB](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createhwcontextcb) callback function.

### `pfnDestroyHwContextCb`

A pointer to a [PFND3DDDI_DESTROYHWCONTEXTCB](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroyhwcontextcb) callback function.

### `pfnCreateHwQueueCb`

A pointer to a [PFND3DDDI_CREATEHWQUEUECB](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createhwqueuecb) callback function.

### `pfnDestroyHwQueueCb`

A pointer to a [PFND3DDDI_DESTROYHWQUEUECB](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroyhwqueuecb) callback function.

### `pfnSubmitCommandToHwQueueCb`

A pointer to a [PFND3DDDI_SUBMITCOMMANDTOHWQUEUECB](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_submitcommandtohwqueuecb) callback function.

### `pfnSubmitWaitForSyncObjectsToHwQueueCb`

A pointer to a [PFND3DDDI_SUBMITWAITFORSYNCOBJECTSTOHWQUEUECB](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_submitwaitforsyncobjectstohwqueuecb) callback function.

### `pfnSubmitSignalSyncObjectsToHwQueueCb`

A pointer to a [PFND3DDDI_SUBMITSIGNALSYNCOBJECTSTOHWQUEUECB](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_submitsignalsyncobjectstohwqueuecb) callback function.

### `pfnSubmitPresentBltToHwQueueCb`

A pointer to a [PFND3DDDI_SUBMITPRESENTBLTTOHWQUEUECB](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_submitpresentblttohwqueuecb) callback function.

### `pfnSubmitPresentToHwQueueCb`

Pointer to a [PFND3DDDI_SUBMITPRESENTTOHWQUEUECB](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_submitpresenttohwqueuecb) callback function.

### `pfnSubmitHistorySequenceCb`

Pointer to a [PFND3DDDI_SUBMITHISTORYSEQUENCECB](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_submithistorysequencecb) callback function.

## Remarks

Declarations for the callback functions that **D3DDDI_DEVICECALLBACKS** members point to can be found in *d3dumddi.h*.