# FltAllocateExtraCreateParameterFromLookasideList function

## Description

The **FltAllocateExtraCreateParameterFromLookasideList** routine allocates memory pool from a given lookaside list for an extra create parameter (ECP) context structure and generates a pointer to that structure.

## Parameters

### `Filter` [in]

Opaque filter pointer to the minifilter driver. This pointer uniquely identifies the minifilter driver and remains constant as long as the minifilter driver is loaded.

### `EcpType` [in]

Pointer to a GUID that indicates the type of the ECP context structure. See [Using GUIDs in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-guids-in-drivers) for more information.

### `SizeOfContext` [in]

The size, in bytes, of the ECP context structure.

### `Flags` [in]

Defines pool allocation options. If the value of the *SizeOfContext* parameter is larger than the size, in bytes, of the given lookaside list, the ECP context structure will be allocated from system pool instead of the lookaside list. In this case, if the *Flags* parameter contains the FSRTL_ALLOCATE_ECP_FLAG_CHARGE_QUOTA bit flag value, system pool allocated by the routine will be charged against the current process' memory quota. See the *Flags* parameter of [FltAllocateExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocateextracreateparameter) for more information. In the more typical case when memory for the ECP context structure is allocated from the lookaside list, the FSRTL_ALLOCATE_ECP_FLAG_CHARGE_QUOTA bit flag is not used by the routine.

### `CleanupCallback` [in, optional]

Optional pointer to a minifilter-defined cleanup callback routine of type [PFSRTL_EXTRA_CREATE_PARAMETER_CLEANUP_CALLBACK](https://learn.microsoft.com/previous-versions/ff551124(v=vs.85)). The cleanup callback routine is called when the ECP context structure is deleted. Set this parameter to **NULL** if a cleanup callback routine is not applicable.

### `LookasideList` [in, out]

Pointer to an initialized lookaside list in which to attempt to allocate pool from (for the ECP context structure). To initialize the lookaside list, use the [FltInitExtraCreateParameterLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitextracreateparameterlookasidelist) routine.

### `EcpContext` [out]

Receives a pointer to the allocated ECP context structure. If the routine failed to allocate sufficient pool for the ECP context structure, *EcpContext* will be **NULL** and the routine will return status code STATUS_INSUFFICIENT_RESOURCES.

## Return value

The **FltAllocateExtraCreateParameterFromLookasideList** routine can return one of the following values:

|Return code|Description|
|----|----|
|**STATUS_INSUFFICIENT_RESOURCES**|The **FltAllocateExtraCreateParameterFromLookasideList** routine was unable to allocate sufficient memory for an ECP context structure. In this case, *EcpContext* will be **NULL**.|
|**STATUS_SUCCESS**|The ECP context structure was successfully allocated. In this case, a pointer to the allocated structure is returned by the *EcpContext* parameter.

## Remarks

This routine is available starting with Windows Vista.

The **FltAllocateExtraCreateParameterFromLookasideList** routine allocates memory pool for an ECP context structure from the given initialized paged or non-paged lookaside list. However, if the size of the ECP context structure (as defined by the *SizeOfContext* parameter) is larger than the lookaside list, the routine analogously allocates memory from paged or non-paged system pool.

Use the [FltInitExtraCreateParameterLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitextracreateparameterlookasidelist) routine to initialize a paged or non-paged pool lookaside list. Use the **FltAllocateExtraCreateParameterFromLookasideList** routine to allocate an ECP context structure from the lookaside list, and the [FltFreeExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreeextracreateparameter) routine to deallocate the ECP context structure.

Use the [FltDeleteExtraCreateParameterLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeleteextracreateparameterlookasidelist) routine to free a lookaside list.

Drivers must free all ECP context structures and lookaside lists they create before unloading. However, if a file system or file system filter driver attaches an ECP to an existing or newly-created ECP_LIST while processing an IRP_MJ_CREATE request, this ECP is automatically cleaned up when the IRP completes. As a result, a filter driver does not have to clean up ECPs that are added dynamically. This allows a filter driver's ECP to be properly propagated across the reparse points--a process that can require multiple IRP_MJ_CREATE requests to be generated.

For more information about using lookaside lists with drivers, see [Using Lookaside Lists](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-lookaside-lists).

## See also

[ECP_LIST](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff540148(v=vs.85))

[FltAllocateExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocateextracreateparameter)

[FltAllocateExtraCreateParameterList](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocateextracreateparameterlist)

[FltCreateFileEx2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefileex2)

[FltDeleteExtraCreateParameterLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeleteextracreateparameterlookasidelist)

[FltFreeExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreeextracreateparameter)

[FltFreeExtraCreateParameterList](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreeextracreateparameterlist)

[FltGetEcpListFromCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetecplistfromcallbackdata)

[FltInitExtraCreateParameterLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitextracreateparameterlookasidelist)

[FltInsertExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinsertextracreateparameter)

[FltRemoveExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltremoveextracreateparameter)

[FltSetEcpListIntoCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetecplistintocallbackdata)

[IoCreateFileEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iocreatefileex)

[PFSRTL_EXTRA_CREATE_PARAMETER_CLEANUP_CALLBACK](https://learn.microsoft.com/previous-versions/ff551124(v=vs.85))