# \_\_RxSynchronizeBlockingOperationsMaybeDroppingFcbLock function

**\_\_RxSynchronizeBlockingOperationsMaybeDroppingFcbLock** synchronizes blocking I/O requests to the same work queue.

## Parameters

*RxContext* \[in, out\]
A pointer to the RX\_CONTEXT of the operation being synchronized.

*BlockingIoQ* \[in, out\]
A pointer to the LIST\_ENTRY for the queue.

*DropFcbLock* \[in\]
A Boolean value that indicates if the FCB resource should be released. If this parameter is **TRUE**, then the FCB resource will be released.

## Return value

**\_\_RxSynchronizeBlockingOperationsMaybeDroppingFcbLock** returns STATUS\_SUCCESS on success or an appropriate NTSTATUS value such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_CANCELLED** | The I/O request and the associated RX_CONTEXT was canceled. |
| **STATUS_PENDING** | The *RxContext* was for an asynchronous operation and the *RxContext* has been added to the queue. |

## Remarks

The **\_\_RxSynchronizeBlockingOperationsMaybeDroppingFcbLock** routine synchronizes blocking I/O requests to the same work queue. RDBSS uses **\_\_RxSynchronizeBlockingOperationsMaybeDroppingFcbLock** internally to synchronize named pipe operations. The work queue is the queue referenced by the file object extension (FOBX) associated with the **pFcb** member of the RX\_CONTEXT structure pointed to by *RxContext*.

A network mini-redirector may use **\_\_RxSynchronizeBlockingOperationsMaybeDroppingFcbLock** to synchronize operations on a separate queue that is maintained by the network mini-redirector.

If *RxContext* is marked for an asynchronous operation, **\_\_RxSynchronizeBlockingOperationsMaybeDroppingFcbLock** will add the *RxContext* to the queue and return STATUS\_PENDING. If *RxContext* is marked for a synchronous operation, **\_\_RxSynchronizeBlockingOperationsMaybeDroppingFcbLock** will block and *RxContext* is resumed when a call is made to [**RxResumeBlockedOperations\_Serially**](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxresumeblockedoperations_serially).

If the blocking I/O request was canceled, **\_\_RxSynchronizeBlockingOperationsMaybeDroppingFcbLock** returns STATUS\_CANCELLED to indicate the error.

The **SyncEvent** member of the RX\_CONTEXT structure pointed to by *RxContext* must have been reset before calling **\_\_RxSynchronizeBlockingOperationsMaybeDroppingFcbLock**. The FCB resource must be locked before calling **\_\_RxSynchronizeBlockingOperationsMaybeDroppingFcbLock** if the *DropFcbLock* parameter is set to **TRUE**.

The following two macros are defined on Windows XP and Windows 2000 for calling **\_\_RxSynchronizeBlockingOperationsMaybeDroppingFcbLock** :

**RxSynchronizeBlockingOperations** - calls with the *DropFcbLock* parameter set to **FALSE**.

**RxSynchronizeBlockingOperationsAndDropFcbLock** - calls with the *DropFcbLock* parameter set to **TRUE**.

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Version | The __RxSynchronizeBlockingOperationsMaybeDroppingFcbLock routine is only available on Windows XP and Windows 2000. |
| Header | Rxcontx.h (include Rxcontx.h) |

## See also

[**RxCompleteRequest\_Real**](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxcompleterequest_real)

[**RxCreateRxContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxcreaterxcontext)

[**RxDereference**](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxdereference)

[**RxDereferenceAndDeleteRxContext\_Real**](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxdereferenceanddeleterxcontext_real)

[**RxInitializeContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxinitializecontext)

[**RxPrepareContextForReuse**](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxpreparecontextforreuse)

[**RxResumeBlockedOperations\_Serially**](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxresumeblockedoperations_serially)

[**\_\_RxSynchronizeBlockingOperations**](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-__rxsynchronizeblockingoperations)

