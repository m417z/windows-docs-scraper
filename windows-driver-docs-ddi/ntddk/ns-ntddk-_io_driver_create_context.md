## Description

The IO_DRIVER_CREATE_CONTEXT structure is used to pass additional parameters to the [IoCreateFileEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iocreatefileex) and [FltCreateFileEx2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefileex2) routines. This structure is optional.

The [IoCreateFileEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iocreatefileex) routine is used by legacy filter drivers and the [FltCreateFileEx2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefileex2) routine is used by minifilter drivers.

## Members

### `Size`

A read-only member initialized by the [IoInitializeDriverCreateContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioinitializedrivercreatecontext) routine.

### `ExtraCreateParameter`

A pointer to an [ECP_LIST](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff540148(v=vs.85)) structure, which contains a list of extra create parameter (ECP) entries. See the following **Remarks** section for important information.

### `DeviceObjectHint`

If IO_DRIVER_CREATE_CONTEXT is being used to pass additional create parameters to the [FltCreateFileEx2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefileex2) routine, this member must be **NULL**.

If IO_DRIVER_CREATE_CONTEXT is being used to pass additional create parameters to the [IoCreateFileEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iocreatefileex) routine, this member is a pointer to the device object to which the create request will be sent. The device object must be a legacy filter or file system device object in the file system driver stack for the volume on which the file or directory resides. In the **IoCreateFileEx** case, this parameter is optional and can be **NULL**. If this parameter is **NULL**, the request will be sent to the device object at the top of the driver stack.

### `TxnParameters`

A pointer to a transaction that you want to associate with the create operation. The create operation will be part of the transaction if the value of this member is a valid pointer to the transaction. If the value of this member is **NULL**, the create operation will not be part of a transaction.

### `SiloContext`

The container that the file resides on. This member was introduced in Windows 10, version 1607.

## Remarks

The IO_DRIVER_CREATE_CONTEXT structure can be allocated from paged or nonpaged pool. The [IoInitializeDriverCreateContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioinitializedrivercreatecontext) routine must initialize the IO_DRIVER_CREATE_CONTEXT structure before the structure can be used.

The members of the IO_DRIVER_CREATE_CONTEXT structure (excluding the **Size** member) function as additional parameters to the [IoCreateFileEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iocreatefileex) and [FltCreateFileEx2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefileex2) routines. Relative to the **IoCreateFileEx** and **FltCreateFileEx2** routine's interface, the following information may be helpful:

- An ECP_LIST structure contains a list of extra create parameter (ECP) entries. Each ECP entry (ECP context structure) in the ECP list (ECP_LIST structure) functions as an additional create parameter to [IoCreateFileEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iocreatefileex) and [FltCreateFileEx2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefileex2).

 To specify an ECP as part of a create operation, initialize the **ExtraCreateParameter** member of the IO_DRIVER_CREATE_CONTEXT structure with the correct routine:

  - For legacy filter drivers, the [FsRtlAllocateExtraCreateParameterList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlallocateextracreateparameterlist) routine must be used to allocate memory pool for the ECP_LIST structure. The operating system does not automatically free ECP_LIST structures. Instead, once the ECP_LIST structure is allocated, it must eventually be freed by using the [FsRtlFreeExtraCreateParameterList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlfreeextracreateparameterlist) routine.

  - For minifilter drivers, the [FltAllocateExtraCreateParameterList](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocateextracreateparameterlist) routine must be used to allocate memory pool for the ECP_LIST structure. The operating system does not automatically free ECP_LIST structures. Instead, once the ECP_LIST structure is allocated, it must eventually be freed by using the [FltFreeExtraCreateParameterList](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreeextracreateparameterlist) routine.

 If ECPs are used, they must be created, manipulated, and freed by using the appropriate routines. For example, minifilter drivers use the [FltInsertExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinsertextracreateparameter) routine to insert an ECP entry into an ECP list. The following **See Also** section lists many of these required routines.

 Upon return from a call to [IoCreateFileEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iocreatefileex) or [FltCreateFileEx2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefileex2), the ECP list is unchanged and can be passed to additional **IoCreateFileEx** or **FltCreateFileEx2** calls for new create operations.

- To create or open a file in the context of a transaction, set the **TxnParameters** member of the IO_DRIVER_CREATE_CONTEXT structure to the value returned by the [IoGetTransactionParameterBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iogettransactionparameterblock) routine.

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

[FsRtlAllocateExtraCreateParameterList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlallocateextracreateparameterlist)

[FsRtlFreeExtraCreateParameterList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlfreeextracreateparameterlist)

[IoCreateFileEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iocreatefileex)

[IoCreateFileSpecifyDeviceObjectHint](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iocreatefilespecifydeviceobjecthint)

[IoGetTransactionParameterBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iogettransactionparameterblock)

[IoInitializeDriverCreateContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioinitializedrivercreatecontext)