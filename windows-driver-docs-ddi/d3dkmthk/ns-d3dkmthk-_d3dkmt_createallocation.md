# D3DKMT_CREATEALLOCATION structure

## Description

The **D3DKMT_CREATEALLOCATION** structure describes parameters for [creating allocations](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreateallocation).

## Members

### `hDevice` [in]

A handle to the device that the resource or allocation is associated with.

### `hResource` [in/out]

A D3DKMT_HANDLE data type that represents a kernel-mode handle to the resource that is associated with the allocations. The value in **hResource** should always be zero unless an allocation will be added to an existing resource, in which case **hResource** contains the resource handle.

When the **CreateResource** bit-field flag is set in the **Flags** member, the OpenGL runtime generates a unique handle and passes it back to the driver. On output from the [**D3DKMTCreateAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreateallocation) function, **hResource** specifies the handle that the driver should use in subsequent OpenGL runtime calls to identify the resource. The resource handle that is returned is device-specific and is valid only when used with the device that it was created on.

### `hGlobalShare` [out]

A user-mode client driver should not share resources using global handles. The driver should set **NtSecuritySharing** in **Flags** and call [**D3DKMTShareObjects**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtshareobjects) to get an NT handle. Using global handles is not secure. Any process can guess a global handle and open a shared object. Global handles are supported only for compatibility reasons with old D3D runtimes. (When **NtSecuritySharing** isn't set, the global handle is returned in **hGlobalShare**. Nothing prevents a UMD from sharing a resource using a global handle, but drivers shouldn't do that.)

### `pPrivateRuntimeData` [in]

A pointer to optional private data that can be attached to a resource for debugging purposes. This data is per resource and not per allocation.

### `PrivateRuntimeDataSize` [in]

The size, in bytes, of the private data that **pPrivateRuntimeData** points to.

### `pStandardAllocation` [in]

Pointer to a [**D3DKMT_CREATESTANDARDALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createstandardallocation) structure that describes the standard allocation to be created.

### `pPrivateDriverData` [in]

A pointer to a buffer that contains optional private data that the display miniport driver might require to create the resource or allocation. The contents of the buffer typically come from the ICD and must be in a format that the display miniport driver can process.

### `PrivateDriverDataSize` [in/out]

The size, in bytes, of the private data that **pPrivateDriverData** points to.

### `NumAllocations` [in]

The number of elements in the array that **pAllocationInfo** specifies, which represents the number of allocations to create. Note that creating a resource without any allocations initially associated with it is valid; therefore, **NumAllocations** can be set to 0.

### `pAllocationInfo` [in]

An array of [**D3DDDI_ALLOCATIONINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_allocationinfo) structures that describe specific properties for each allocation to create.

### `pAllocationInfo2` [in]

This member is reserved and should be set to zero.

This member is available beginning with Windows 7.

### `Flags` [in]

A [**D3DKMT_CREATEALLOCATIONFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createallocationflags) structure that identifies attributes for creating the allocation, in bit-field flags.

If you set the **CreateShared** bit-field flag in **Flags**, you must also set the **CreateResource** bit-field flag.

### `hPrivateRuntimeResourceHandle` [in]

An opaque handle that you can use in event tracing. This handle can be used to associate kernel-mode allocations with user-mode surface pointers when you analyze Event Tracing for Windows (ETW) event logs.

## See also

[**D3DDDI_ALLOCATIONINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_allocationinfo)

[**D3DKMTCreateAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreateallocation)

[**D3DKMT_CREATEALLOCATIONFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createallocationflags)