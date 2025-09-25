# RxInitializeContext function

## Description

**RxInitializeContext** initializes an existing RX_CONTEXT data structure.

## Parameters

### `Irp` [in, optional]

A pointer to the IRP to be encapsulated by this RX_CONTEXT structure.

### `RxDeviceObject` [in]

A pointer to the device object to which this RX_CONTEXT and IRP apply.

### `InitialContextFlags` [in]

The set of initial values for *Flags* member of the RX_CONTEXT data structure to be stored in the RX_CONTEXT structure. These initial values can be any combination of the following enumerations:

#### RX_CONTEXT_FLAG_WAIT

When this value is set, the IRP should be not be posted for later execution by the file system process, but should be waited on to complete.

#### RX_CONTEXT_FLAG_MUST_SUCCEED

When this value is set, the operation must succeed. This value is not currently used by RDBSS, but it may be used by network mini-redirector drivers.

#### RX_CONTEXT_FLAG_MUST_SUCCEED_NONBLOCKING

When this value is set, the operation must succeed for non-blocking operations. This value is not currently used by RDBSS, but it may be used by network mini-redirector drivers.

### `RxContext` [in, out]

Pointer to the RX_CONTEXT to be initialized.

## Remarks

**RxInitializeContext** is called internally by the **RxCreateRxContext** routine. So the **RxInitializeContext** routine would normally only be used by network min-redirector drivers that allocate RX_CONTEXT structures directly rather than calling the **RxCreateRxContext** routine to allocate and initialize an RX_CONTEXT structure.

If the *Irp* parameter is configured for asynchronous operation, then the **Flags** member of the RX_CONTEXT structure pointed to by *RxContext* also has the following value set:

RX_CONTEXT_FLAG_ASYNC_OPERATION is also set for the following conditions:

* The **MajorFunction** member of the *Irp* is IRP_MJ_READ, IRP_MJ_WRITE, or IRP_MJ_DEVICE_CONTROL.
* The **MajorFunction** member of the *Irp* is an IRP_MJ_DIRECTORY_CONTROL and the **MinorFunction** member of the *IRP* is an IRP_MN_NOTIFY_CHANGE_DIRECTORY.
* The **MajorFunction** member of the *Irp* is an IRP_MJ_FILE_SYSTEM_CONTROL and **NetRoot** member of the associated FCB is not **NULL** and the **Type** member of the NET_ROOT is NET_ROOT_PIPE.

If this is a recursive file system call (the TopLevelIrp member in the thread local storage is the current *Irp*) then the **Flags** member of *RxContext* also has the following value set:

If the *RxDeviceObject* parameter indicates that this is the top level RDBSS device object, then the **Flags** member of the RX_CONTEXT structure also has the following value set:

If the *Irp* FileObject Flags member has the FO_WRITE_THROUGH option set, then the **Flags** member of the RX_CONTEXT structure also has the following value set:

**RxInitializeContext** sets a number of other members in the RX_CONTEXT structure including the following:

* Sets the proper **NodeTypeCode**, **NodeByteSize**, **SerialNumber**, **RxDeviceObject**, and initializes the **ReferenceCount** to 1.
* Initializes the SyncEvent
* Initialize the associated ScavengerEntry
* Initializes the list entry of BlockedOperations
* Sets the RX_CONTEXT members based on the *Irp*. These include **CurrentIrp**, **OriginalThread**, **MajorFunction**, **MinorFunction**, **CurrentIrpSp**, **pFcb**, **NonPagedFcb**, **pFobx**, **pRelevantSrvOpen**, and **FobxSerialNumber** members.

## See also

[RX_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/ns-rxcontx-_rx_context)

[RxCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxcompleterequest)

[RxCompleteRequest_Real](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxcompleterequest_real)

[RxCreateRxContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxcreaterxcontext)

[RxDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxdereference)

[RxDereferenceAndDeleteRxContext_Real](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxdereferenceanddeleterxcontext_real)

[RxPrepareContextForReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxpreparecontextforreuse)

[RxResumeBlockedOperations_Serially](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxresumeblockedoperations_serially)

[__RxSynchronizeBlockingOperations](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-__rxsynchronizeblockingoperations)

[__RxSynchronizeBlockingOperationsMaybeDroppingFcbLock](https://learn.microsoft.com/windows-hardware/drivers/ifs/--rxsynchronizeblockingoperationsmaybedroppingfcblock)