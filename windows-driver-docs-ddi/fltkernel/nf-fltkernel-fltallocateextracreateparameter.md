# FltAllocateExtraCreateParameter function

## Description

The **FltAllocateExtraCreateParameter** routine allocates paged memory pool for a user-defined extra create parameter (ECP) context structure and generates a pointer to that structure.

## Parameters

### `Filter` [in]

Opaque filter pointer for the minifilter driver. This pointer uniquely identifies the minifilter driver and remains constant as long as the minifilter driver is loaded.

### `EcpType` [in]

Pointer to a user-defined GUID indicating the type of the ECP context structure. See [Using GUIDs in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-guids-in-drivers) for more information.

### `SizeOfContext` [in]

The size, in bytes, of the user-defined context structure.

### `Flags` [in]

Defines pool allocation options. The following describes how pool will be allocated when one or more of the listed flag values are combined with the *Flags* parameter by using a bitwise OR operation:

- FSRTL_ALLOCATE_ECP_FLAG_NONPAGED_POOL - Non-paged pool will be allocated. If this flag value is not used, paged pool will be allocated.

- FSRTL_ALLOCATE_ECPLIST_FLAG_CHARGE_QUOTA - All pool allocated by this routine will be charged against the current process' memory quota.

If more than one flag is used, all of the effects associated with the utilized flag values will occur.

### `CleanupCallback` [in, optional]

Optional pointer to a minifilter-defined cleanup callback routine of type [PFSRTL_EXTRA_CREATE_PARAMETER_CLEANUP_CALLBACK](https://learn.microsoft.com/previous-versions/ff551124(v=vs.85)). The cleanup callback routine is called when the ECP structure (created by the **FltAllocateExtraCreateParameter** routine) is deleted. Set this parameter to **NULL** if a cleanup callback routine is not applicable.

### `PoolTag` [in]

Specifies the pool tag for the allocated memory. For more information, see the *Tag* parameter of [ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag).

### `EcpContext` [out]

Receives a pointer to the allocated ECP context structure. If the routine failed to allocate sufficient pool, *\*EcpContext* will be **NULL** and the routine will return status code STATUS_INSUFFICIENT_RESOURCES.

## Return value

**FltAllocateExtraCreateParameter** can return one of the following values:

|Return code|Description|
|----|----|
|STATUS_INSUFFICIENT_RESOURCES|**FltAllocateExtraCreateParameter** was unable to allocate sufficient memory for an ECP structure. In this case, *EcpContext* will be **NULL**.|
|STATUS_SUCCESS|The ECP structure was successfully allocated. In this case, a pointer to the allocated structure is returned in the *EcpContext* parameter.|

## Remarks

By default, the **FltAllocateExtraCreateParameter** routine allocates paged memory pool for a user-defined ECP context structure. If the FSRTL_ALLOCATE_ECP_FLAG_NONPAGED_POOL bitmask is used as described above, a non-paged memory pool is allocated. Once this pool has been allocated and the ECP context structure has been initialized, the [FltInsertExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinsertextracreateparameter) routine is used to insert the ECP context structure (ECP list element) into an ECP list structure (ECP list).

Memory pool that is allocated by the **FltAllocateExtraCreateParameter** routine is not automatically freed by the operating system. This memory pool must eventually be released by using one of the following methods:

- Call the [FltRemoveExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltremoveextracreateparameter) routine to remove the ECP context structure from the ECP list and then call the [FltFreeExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreeextracreateparameter) routine to free the ECP context structure itself. The ECP list remains in existence.

- Call the [FltFreeExtraCreateParameterList](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreeextracreateparameterlist) routine - this frees the ECP list including any list elements (ECP context structures). The ECP list is destroyed.

 However, if a file system or file system filter driver attaches an ECP to an existing or newly-created ECP_LIST while processing an IRP_MJ_CREATE request, this ECP is automatically cleaned up when the IRP completes. As a result, a filter driver does not have to clean up ECPs that are added dynamically. This allows a filter driver's ECP to be properly propagated across the reparse points--a process that can require multiple IRP_MJ_CREATE requests to be generated.

## See also

[ECP_LIST](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff540148(v=vs.85))

[FltAllocateExtraCreateParameterFromLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocateextracreateparameterfromlookasidelist)

[FltAllocateExtraCreateParameterList](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocateextracreateparameterlist)

[FltCreateFileEx2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefileex2)

[FltFreeExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreeextracreateparameter)

[FltFreeExtraCreateParameterList](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreeextracreateparameterlist)

[FltGetEcpListFromCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetecplistfromcallbackdata)

[FltInsertExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinsertextracreateparameter)

[FltRemoveExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltremoveextracreateparameter)

[FltSetEcpListIntoCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetecplistintocallbackdata)

[IoCreateFileEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iocreatefileex)

[PFSRTL_EXTRA_CREATE_PARAMETER_CLEANUP_CALLBACK](https://learn.microsoft.com/previous-versions/ff551124(v=vs.85))