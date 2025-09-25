# FltCbdqInitialize function

## Description

FltCbdqInitialize initializes a minifilter driver's callback data queue dispatch table.

## Parameters

### `Instance` [in]

Opaque instance pointer for the instance whose callback data queue is to be initialized.

### `Cbdq` [in, out]

Pointer to a callback data queue allocated by the minifilter driver.

### `CbdqInsertIo` [in]

Pointer to a caller-supplied insert callback routine. The Filter Manager calls this routine to insert the specified callback data structure into the queue. This routine is declared as follows:

```
typedef NTSTATUS
(*PFLT_CALLBACK_DATA_QUEUE_INSERT_IO)(
      _Inout_ PFLT_CALLBACK_DATA_QUEUE Cbdq,
      _In_ PFLT_CALLBACK_DATA Cbd,
      _In_opt_ PVOID InsertContext
      );
```

#### Cbdq

Pointer to the minifilter driver's cancel-safe callback data queue. This queue must have been initialized by calling *FltCbdqInitialize*.

#### Cbd

Pointer to the callback data structure to be inserted into the queue.

#### InsertContext

Context information pointer that was passed as the *InsertContext* parameter to [FltCbdqInsertIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqinsertio).

### `CbdqRemoveIo` [in]

Pointer to a caller-supplied remove callback routine. The Filter Manager calls this routine to remove the specified callback data structure from the queue. This routine is declared as follows:

```
typedef VOID
(*PFLT_CALLBACK_DATA_QUEUE_REMOVE_IO)(
      _Inout_ PFLT_CALLBACK_DATA_QUEUE Cbdq,
      _In_ PFLT_CALLBACK_DATA Cbd
      );
```

#### Cbdq

Pointer to the minifilter driver's cancel-safe callback data queue. This queue must have been initialized by calling *FltCbdqInitialize*.

#### Cbd

Pointer to the callback data structure to be removed from the queue.

### `CbdqPeekNextIo` [in]

Pointer to a caller-supplied peek callback routine. The Filter Manager calls this function to get a pointer to the next I/O operation matching *PeekContext* in the queue; or, if *Cbd* is **NULL**, to get a pointer to the first matching I/O operation in the queue. The minifilter driver entirely defines the meaning of *PeekContext* and defines when an I/O operation matches a given *PeekContext*. This routine is declared as follows:

```
typedef PFLT_CALLBACK_DATA
(*PFLT_CALLBACK_DATA_QUEUE_PEEK_NEXT_IO)(
      _In_ PFLT_CALLBACK_DATA_QUEUE Cbdq,
      _In_opt_ PFLT_CALLBACK_DATA Cbd,
      _In_opt_ PVOID PeekContext
      );
```

#### Cbdq

Pointer to the minifilter driver's cancel-safe callback data queue. This queue must have been initialized by calling *FltCbdqInitialize*.

#### Cbd

Pointer to the callback data structure marking the position in the queue to begin searching for a match to *PeekContext*. If *Cbd* is **NULL**, the search begins at the head of the queue.

#### PeekContext

Context information pointer that was passed as the *PeekContext* parameter to [FltCbdqRemoveNextIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqremovenextio).

### `CbdqAcquire` [in]

Pointer to a caller-supplied acquire queue lock callback routine. The Filter Manager calls this routine to acquire the lock on the queue before attempting to insert or remove an item from the queue. This routine is declared as follows:

```
typedef VOID
(*PFLT_CALLBACK_DATA_QUEUE_ACQUIRE)(
      _Inout_ PFLT_CALLBACK_DATA_QUEUE Cbdq,
      _Out_opt_ PKIRQL Irql
      );
```

#### Cbdq

Pointer to the minifilter driver's cancel-safe callback data queue. This queue must have been initialized by calling *FltCbdqInitialize*.

#### Irql

Pointer to a system-supplied variable that receives the current IRQL. The same variable is passed to the corresponding *CbdqRelease* routine.

### `CbdqRelease` [in]

Pointer to a caller-supplied release queue lock callback routine. The Filter Manager calls this routine to release the lock that it obtained by calling the corresponding *CbdqAcquire* routine. This routine is declared as follows:

```
typedef VOID
(*PFLT_CALLBACK_DATA_QUEUE_RELEASE)(
      _Inout_ PFLT_CALLBACK_DATA_QUEUE Cbdq,
      _In_opt_ KIRQL Irql
      );
```

#### Cbdq

Pointer to the minifilter driver's cancel-safe callback data queue. This queue must have been initialized by calling *FltCbdqInitialize*.

#### Irql

The same system-supplied variable that received the current IRQL as the *Irql* parameter to the corresponding *CbdqAcquire* routine.

### `CbdqCompleteCanceledIo` [in]

Pointer to a caller-supplied cancel routine. The Filter Manager calls this routine to signal to the minifilter driver to complete a canceled I/O operation. This routine is declared as follows:

```
typedef VOID
(*PFLT_CALLBACK_DATA_QUEUE_COMPLETE_CANCELED_IO)(
      _Inout_ PFLT_CALLBACK_DATA_QUEUE Cbdq,
      _Inout_ PFLT_CALLBACK_DATA Cbd
      );
```

#### Cbdq

Pointer to the minifilter driver's cancel-safe callback data queue. This queue must have been initialized by calling *FltCbdqInitialize*.

#### Cbd

Pointer to the callback data structure for the canceled I/O operation.

## Return value

*FltCbdqInitialize* returns STATUS_SUCCESS or an appropriate NTSTATUS value.

## Remarks

The newly initialized callback data queue is in the enabled state, which means that callback data structure items can be inserted into the queue. The queue can be disabled by calling [FltCbdqDisable](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqdisable) and reenabled by calling [FltCbdqEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqenable).

Minifilter drivers can use the **FltCbdq***Xxx* routines to implement a callback data queue for IRP-based I/O operations. By using these routines, minifilter drivers can make their queues cancel-safe; the system transparently handles I/O cancellation for the minifilter drivers.

The **FltCbdq***Xxx* routines can only be used for IRP-based I/O operations. To determine whether a given callback data structure represents an IRP-based I/O operation, use the [FLT_IS_IRP_OPERATION](https://learn.microsoft.com/previous-versions/ff544654(v=vs.85)) macro.

Minifilter drivers can use any internal implementation for the queue. The Filter Manager interacts with the minifilter driver's queue implementation solely through the set of dispatch routines provided by *FltCbdqInitialize*.

The system automatically locks and unlocks the queue as necessary. Minifilter drivers do not implement any locking inside their *CbdqInsertIo*, *CbdqRemoveIo*, and *CbdqPeekNextIo* routines.

Minifilter drivers can use any of the operating system's synchronization primitives as the locking mechanism in their *CbdqAcquire* and *CbdqRelease* routines, such as a [spin lock](https://learn.microsoft.com/windows-hardware/drivers/kernel/spin-locks), [mutex object](https://learn.microsoft.com/windows-hardware/drivers/kernel/mutex-objects), or [resource variable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializeresourcelite). Note that if a minifilter driver uses a spin lock rather than a mutex or resource to protect the queue, it can call the **FltCbdq***Xxx* routines at IRQL <= DISPATCH_LEVEL. If a mutex or resource is used, the minifilter driver must be running at IRQL <= APC_LEVEL when it calls any of these routines except *FltCbdqInitialize*.

The minifilter driver does not manipulate the queue directly. Instead, it calls [FltCbdqInsertIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqinsertio), [FltCbdqRemoveIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqremoveio), and [FltCbdqRemoveNextIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqremovenextio) to add or remove a callback data structure. These routines in turn call the callback functions that the minifilter driver provided to *FltCbdqInitialize*.

Minifilter drivers should implement the queue routines as follows.

| Cbdq Routine | Implementation |
| --- | --- |
| *CbdqInsertIo* | Insert the specified callback data structure into the queue. |
| *CbdqRemoveIo* | Remove the specified callback data structure from the queue. |
| *CbdqPeekNextIo* | This routine should allow the system to loop through the callback data structures with matching *PeekContext* in the queue. *Cbd* = *CbdqPeekNextIo*(*Cbdq*, **NULL**, *PeekContext*) should return the first matching entry in the queue, and *CbdqPeekNextIo*(*Cbdq*, *Cbd*, *PeekContext*) should return the next matching entry after the given callback data structure in the queue. The minifilter driver entirely defines the meaning of *PeekContext* and defines when a callback data structure matches a *PeekContext* value. |
| *CbdqAcquire* | This routine should lock the queue so that no other thread can access it. Minifilter drivers can use any locking mechanism to lock the queue. If the minifilter driver uses the [KeAcquireSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquirespinlock) routine, the minifilter driver can use the memory location pointed to by the routine's *Irql* parameter to store the IRQL. Otherwise, minifilter drivers can ignore that parameter. |
| *CbdqRelease* | This routine should unlock the queue created by *CbdqAcquire*. If the minifilter driver used a spin lock and returned the IRQL value in the *Irql* parameter of *CbdqAcquire*, the system passes that value in the *Irql* parameter of *CbdqRelease*. The minifilter driver can use the IRQL to unlock the spin lock by calling [KeReleaseSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleasespinlock). Otherwise, minifilter drivers can ignore the *Irql* parameter. |
| *CbdqCompleteCanceledIo* | This routine should complete a canceled I/O operation. Normally, minifilter drivers can just call [FltCompletePendedPreOperation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcompletependedpreoperation)(Data, FLT_PREOP_COMPLETE, **NULL**). Minifilter drivers do not need to dequeue the callback data structure -- the Filter Manager automatically calls the queue's *CbdqRemoveIo* before calling *CbdqCompleteCanceledIo*. |

## See also

[FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[FLT_CALLBACK_DATA_QUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data_queue)

[FLT_IS_IRP_OPERATION](https://learn.microsoft.com/previous-versions/ff544654(v=vs.85))

[FltCbdqDisable](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqdisable)

[FltCbdqEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqenable)

[FltCbdqInsertIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqinsertio)

[FltCbdqRemoveIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqremoveio)

[FltCbdqRemoveNextIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqremovenextio)

[FltCompletePendedPreOperation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcompletependedpreoperation)

[KeAcquireSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquirespinlock)

[KeReleaseSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleasespinlock)