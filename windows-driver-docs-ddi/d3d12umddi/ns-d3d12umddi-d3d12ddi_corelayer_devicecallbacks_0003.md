# D3D12DDI_CORELAYER_DEVICECALLBACKS_0003 structure

## Description

Contains Microsoft Direct3D 12 runtime callback functions that the user-mode display driver can use.

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

## Remarks

## See also