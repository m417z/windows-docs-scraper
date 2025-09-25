# FsRtlAllocateExtraCreateParameterList function

## Description

The **FsRtlAllocateExtraCreateParameterList** routine allocates paged pool memory for an [**ECP_LIST**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff540148(v=vs.85)) structure and generates a pointer to that structure.

## Parameters

### `Flags` [in]

Defines pool allocation options. If the FSRTL_ALLOCATE_ECPLIST_FLAG_CHARGE_QUOTA flag is combined with the **Flags** parameter by using a bitwise OR operation, any pool allocated by **FsRtlAllocateExtraCreateParameterList** will be charged against the current process' memory quota.

### `EcpList` [out]

Receives a pointer to an initialized ECP list structure. If **FsRtlAllocateExtraCreateParameterList** failed to allocate sufficient pool, ***EcpList** will be NULL and **FsRtlAllocateExtraCreateParameterList** will return status code STATUS_INSUFFICIENT_RESOURCES.

## Return value

**FsRtlAllocateExtraCreateParameterList** can return one of the following values:

| Return code | Description |
| ----------- | ----------- |
| STATUS_INSUFFICIENT_RESOURCES | **FsRtlAllocateExtraCreateParameterList** was unable to allocate sufficient memory for an ECP list structure. In this case, ***EcpList** will be NULL. |
| STATUS_SUCCESS | The memory for the [**ECP_LIST**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff540148(v=vs.85)) structure was successfully allocated and initialized. In this case, a pointer to the initialized list structure is returned in the **EcpList** parameter. |

## Remarks

Whether the operating system automatically frees memory that **FsRtlAllocateExtraCreateParameterList** allocates depends on when **FsRtlAllocateExtraCreateParameterList** is called, as shown in the following situations:

* A caller can invoke **FsRtlAllocateExtraCreateParameterList** to allocate the ECP_LIST and add one or more ECP context structures before the caller invokes the [**IoCreateFileEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iocreatefileex) routine. In this situation, the operating system does not free any of the ECP context structures. Therefore, the caller can make multiple calls to **IoCreateFileEx** with the same ECP set. When the caller is done with the ECP_LIST, the caller must call the [**FltFreeExtraCreateParameter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreeextracreateparameter) routine to free the ECP_LIST.

* While a file system or file system filter driver processes an [**IRP_MJ_CREATE**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create) request, the file system or file system filter driver can call [**FltInsertExtraCreateParameter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinsertextracreateparameter) to attach an ECP to an existing ECP_LIST. If the ECP_LIST does not exist, the caller must call **FsRtlAllocateExtraCreateParameterList** to create the ECP_LIST. In this situation, the ECP_LIST and the ECP context structure are automatically cleaned up by the I/O manager when the create operation completes. This allows a file system's or filter driver's ECP to be properly propagated across the processing of reparse points. This process might require multiple IRP_MJ_CREATE requests to be generated.

If the FSRTL_ALLOCATE_ECPLIST_FLAG_CHARGE_QUOTA flag is used with the **Flags** parameter, a pageable pool is allocated. Otherwise, a pageable pool is allocated by using an internal lookaside list.

## See also

[**ECP_LIST**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff540148(v=vs.85))

[**FltAllocateExtraCreateParameter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocateextracreateparameter)

[**FltAllocateExtraCreateParameterFromLookasideList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocateextracreateparameterfromlookasidelist)

[**FltCreateFileEx2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefileex2)

[**FltFreeExtraCreateParameter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreeextracreateparameter)

[**FltFreeExtraCreateParameterList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreeextracreateparameterlist)

[**FltGetEcpListFromCallbackData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetecplistfromcallbackdata)

[**FltInsertExtraCreateParameter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinsertextracreateparameter)

[**FltRemoveExtraCreateParameter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltremoveextracreateparameter)

[**FltSetEcpListIntoCallbackData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetecplistintocallbackdata)

[**IoCreateFileEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iocreatefileex)