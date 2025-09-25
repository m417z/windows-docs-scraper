# D3D12DDI_CORELAYER_DEVICECALLBACKS_0050 structure

## Description

The D3D12DDI_CORELAYER_DEVICECALLBACKS_0050 structure contains Microsoft Direct3D 12 runtime callback functions that the user-mode display driver can use.

## Members

### `pfnSetErrorCb`

A pointer to the PFND3D12DDI_SETERROR_CB function.

### `pfnSetCommandListErrorCb`

A pointer to the PFND3D12DDI_SETCOMMANDLISTERROR_CB function.

### `pfnSetCommandListDDITableCb`

A pointer to the PFND3D12DDI_SETCOMMANDLISTDDITABLE_CB function.

### `pfnCreateContextCb`

A pointer to the PFND3D12DDI_CREATECONTEXT_CB function.

### `pfnCreateContextVirtualCb`

A pointer to the PFND3D12DDI_CREATECONTEXTVIRTUAL_CB function.

Supported starting in WDDM 2.0.

### `pfnReservedCreateContextVirtualCb`

A function pointer for WDDM versions less than 2.0.

### `pfnDestroyContextCb`

A pointer to the PFND3D12DDI_DESTROYCONTEXT_CB function.

### `pfnCreatePagingQueueCb`

A pointer to the PFND3D12DDI_CREATEPAGINGQUEUE_CB function.

Supported starting in WDDM 2.0.

### `pfnDestroyPagingQueueCb`

A pointer to the PFND3D12DDI_DESTROYPAGINGQUEUE_CB function.

Supported starting in WDDM 2.0.

### `pfnMakeResidentCb`

A pointer to the PFND3D12DDI_MAKERESIDENT_CB function.

Supported starting in WDDM 2.0.

### `pfnEvictCb`

A pointer to the PFND3D12DDI_EVICT_CB function.

Supported starting in WDDM 2.0.

### `pfnReclaimAllocations2Cb`

A pointer to the PFND3D12DDI_RECLAIMALLOCATIONS2_CB function.

Supported starting in WDDM 2.0.

### `pfnOfferAllocationsCb`

A pointer to the PFND3D12DDI_OFFERALLOCATIONS_CB function.

Supported starting in WDDM 2.0.

### `pfnReservedCreatePagingQueueCb`

A function pointer for WDDM versions less than 2.0.

### `pfnReservedDestroyPagingQueueCb`

A function pointer for WDDM versions less than 2.0.

### `pfnReservedMakeResidentCb`

A function pointer for WDDM versions less than 2.0.

### `pfnReservedEvictCb`

A function pointer for WDDM versions less than 2.0.

### `pfnReservedReclaimAllocations2Cb`

A function pointer for WDDM versions less than 2.0.

### `pfnReservedOfferAllocationsCb`

A function pointer for WDDM versions less than 2.0.

### `pfnAllocateCb`

A pointer to the PFND3D12DDI_ALLOCATE_CB_0022 function.

### `pfnDeallocateCb`

A pointer to the PFND3D12DDI_DEALLOCATE_CB_0022 function.

### `pfnCreateSchedulingGroupContextCb`

A pointer to a PFND3D12DDI_CREATESCHEDULINGGROUPCONTEXT_CB_0050 function.

Supported starting in WDDM 2.5.

### `pfnCreateSchedulingGroupContextVirtualCb`

A pointer to a PFND3D12DDI_CREATESCHEDULINGGROUPCONTEXTVIRTUAL_CB_0050 function.

Supported starting in WDDM 2.5.

### `pfnCreateHwQueueCb`

A pointer to a PFND3D12DDI_CREATEHWQUEUE_CB_0050 function.

Supported starting in WDDM 2.5.

### `pfnReservedCreateSchedulingGroupContextCb`

A function pointer for WDDM versions less than 2.5.

### `pfnReservedCreateSchedulingGroupContextVirtualCb`

A function pointer for WDDM versions less than 2.5.

### `pfnReservedCreateHwQueueCb`

A function pointer for WDDM versions less than 2.5.

## Remarks

## See also