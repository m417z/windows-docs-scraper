# FsRtlAllocateExtraCreateParameter function

## Description

The **FsRtlAllocateExtraCreateParameter** routine allocates memory for an extra create parameter (ECP) context structure and generates a pointer to that structure.

## Parameters

### `EcpType` [in]

A pointer to a GUID that indicates the type of the ECP context structure. See [Using GUIDs in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-guids-in-drivers) for more information.

### `SizeOfContext` [in]

The size, in bytes, of the context structure.

### `Flags` [in]

Defines pool allocation options. The following describes how pool will be allocated when one or more of the listed flag values are combined with the *Flags* parameter by using a bitwise OR operation:

* FSRTL_ALLOCATE_ECP_FLAG_NONPAGED_POOL - Non-paged pool will be allocated. If this flag value is not used, paged pool will be allocated.

* FSRTL_ALLOCATE_ECPLIST_FLAG_CHARGE_QUOTA - All pool allocated by **FsRtlAllocateExtraCreateParameter** will be charged against the current process' memory quota.

If more than one flag is used, all of the effects associated with the utilized flag values will occur.

### `CleanupCallback` [in, optional]

Optional pointer to a filter-defined cleanup callback routine of type [PFSRTL_EXTRA_CREATE_PARAMETER_CLEANUP_CALLBACK](https://learn.microsoft.com/previous-versions/ff551124(v=vs.85)). The cleanup callback routine is called when the ECP structure (created by the **FsRtlAllocateExtraCreateParameter** routine) is deleted. Set this parameter to **NULL** if a cleanup callback routine is not applicable.

### `PoolTag` [in]

Specifies the pool tag for the allocated memory. For more information, see the *Tag* parameter of [ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag).

### `EcpContext` [out]

Receives a pointer to the allocated ECP context structure. If the routine failed to allocate sufficient pool, the value pointed to by *EcpContext* will be **NULL** and **FsRtlAllocateExtraCreateParameter** will return status code STATUS_INSUFFICIENT_RESOURCES.

## Return value

**FltAllocateExtraCreateParameter** returns a status code such as one of the following:

|Return code|Description|
|----|----|
|**STATUS_INSUFFICIENT_RESOURCES**|**FsRtlAllocateExtraCreateParameter** was unable to allocate sufficient memory for an ECP structure. In this case, *EcpContext* is **NULL**.|
|**STATUS_SUCCESS**|The ECP structure was successfully allocated. In this case, a pointer to the allocated structure is returned in the *EcpContext* parameter.

## Remarks

By default, the **FsRtlAllocateExtraCreateParameter** routine allocates paged memory pool for a ECP context structure. If the FSRTL_ALLOCATE_ECP_FLAG_NONPAGED_POOL bitmask is used as described in the *Flags* parameter, a non-paged memory pool is allocated. After this pool has been allocated and the ECP context structure has been initialized, the [FltInsertExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinsertextracreateparameter) routine is used to insert the ECP context structure (ECP list element) into an ECP list structure ([ECP_LIST](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff540148(v=vs.85))).

If the caller allocates ECP_LIST and one or more ECPs are used in a call to [IoCreateFileEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iocreatefileex), the previous description is correct. In this case, the system does not free any of the ECPs, so the caller can make multiple calls to **IoCreateFileEx** with the same ECP set. However, if a file system or file system filter driver attaches an ECP to an existing or newly-created ECP_LIST while processing an IRP_MJ_CREATE request, this ECP is automatically cleaned up when the IRP completes. As a result, a filter driver does not have to clean up ECPs that are added dynamically. This allows a filter driver's ECP to be properly propagated across the reparse points--a process that can require multiple IRP_MJ_CREATE requests to be generated.

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