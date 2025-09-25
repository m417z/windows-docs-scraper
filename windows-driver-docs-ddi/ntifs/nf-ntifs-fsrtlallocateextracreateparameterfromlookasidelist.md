# FsRtlAllocateExtraCreateParameterFromLookasideList function

## Description

The **FsRtlAllocateExtraCreateParameterFromLookasideList** routine allocates memory pool from a given lookaside list for an extra create parameter (ECP) context structure, and generates a pointer to that structure.

## Parameters

### `EcpType` [in]

Pointer to a GUID that indicates the type of ECP for whicha context structure should be allocated. For more information about ECPs, see [Using Extra Create Parameters with an IRP_MJ_CREATE Operation](https://learn.microsoft.com/windows-hardware/drivers/ifs/using-extra-create-parameters-with-an-irp-mj-create-operation).

### `SizeOfContext` [in]

The size, in bytes, of the ECP context structure.

### `Flags` [in]

Defines pool allocation options. If the value of the *SizeOfContext* parameter is larger than the size, in bytes, of the lookaside list that the *LookasideList* parameter points to, **FsRtlAllocateExtraCreateParameterFromLookasideList** allocates the ECP context structure from system pool instead of the lookaside list. In this case, if the *Flags* parameter contains the FSRTL_ALLOCATE_ECP_FLAG_CHARGE_QUOTA bit flag value, system pool allocated by **FsRtlAllocateExtraCreateParameterFromLookasideList** is charged against the current process' memory quota. For more information about bit flag values, see the *Flags* parameter of [FsRtlAllocateExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlallocateextracreateparameter). In the more typical case, when **FsRtlAllocateExtraCreateParameterFromLookasideList** allocates memory for the ECP context structure from the lookaside list, **FsRtlAllocateExtraCreateParameterFromLookasideList** ignores the FSRTL_ALLOCATE_ECP_FLAG_CHARGE_QUOTA bit flag.

### `CleanupCallback` [in, optional]

Optional pointer to a minifilter-defined cleanup callback routine of type [PFSRTL_EXTRA_CREATE_PARAMETER_CLEANUP_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nc-ntifs-pfsrtl_extra_create_parameter_cleanup_callback). The cleanup callback routine is called when the ECP context structure is deleted. Set this parameter to **NULL** if a cleanup callback routine is not applicable.

### `LookasideList` [in, out]

Pointer to an initialized lookaside list from which **FsRtlAllocateExtraCreateParameterFromLookasideList** attempts to allocate pool (for the ECP context structure). To initialize the lookaside list, use the [FsRtlInitExtraCreateParameterLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlinitextracreateparameterlookasidelist) routine.

### `EcpContext` [out]

Pointer to a location that receives a pointer to the allocated ECP context structure. If **FsRtlAllocateExtraCreateParameterFromLookasideList** failed to allocate sufficient pool for the ECP context structure, **FsRtlAllocateExtraCreateParameterFromLookasideList** sets *EcpContext* to **NULL** and returns status code STATUS_INSUFFICIENT_RESOURCES.

## Return value

The **FsRtlAllocateExtraCreateParameterFromLookasideList** routine can return one of the following values:

|Return code|Description|
|---|---|
|STATUS_INSUFFICIENT_RESOURCES|The **FsRtlAllocateExtraCreateParameterFromLookasideList** routine was unable to allocate sufficient memory for an ECP context structure. In this case, the *EcpContext* parameter is **NULL**.|
|STATUS_SUCCESS|The ECP context structure was successfully allocated. In this case, **FsRtlAllocateExtraCreateParameterFromLookasideList** returns a pointer to the allocated structure in the *EcpContext* parameter.|

## Remarks

Use the [FsRtlInitExtraCreateParameterLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlinitextracreateparameterlookasidelist) routine to initialize a paged or nonpaged pool lookaside list. Use the **FsRtlAllocateExtraCreateParameterFromLookasideList** routine to allocate an ECP context structure from the lookaside list, and the [FsRtlFreeExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlfreeextracreateparameter) routine to deallocate the ECP context structure.

Use the [FsRtlDeleteExtraCreateParameterLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtldeleteextracreateparameterlookasidelist) routine to free a lookaside list.

Drivers must free all ECP context structures and lookaside lists they create before unloading. However, if a file system or file system filter driver attaches an ECP to an existing or newly-created **ECP_LIST** while processing an **IRP_MJ_CREATE** request, this ECP is automatically cleaned up when the IRP completes. As a result, a filter driver does not have to clean up ECPs that are added dynamically. This allows a filter driver's ECP to be properly propagated across the re-parse points, a process that can require multiple **IRP_MJ_CREATE** requests to be generated.

For more information about using lookaside lists with drivers, see [Using Lookaside Lists](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-lookaside-lists).

## See also

[FsRtlDeleteExtraCreateParameterLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtldeleteextracreateparameterlookasidelist)

[FsRtlFreeExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlfreeextracreateparameter)

[FsRtlInitExtraCreateParameterLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlinitextracreateparameterlookasidelist)

[PFSRTL_EXTRA_CREATE_PARAMETER_CLEANUP_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nc-ntifs-pfsrtl_extra_create_parameter_cleanup_callback)