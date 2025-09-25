## Description

The *CsqAcquireLock* routine is used by the system to acquire the lock for a driver-implemented, cancel-safe IRP queue.

## Parameters

### `Csq` [in]

Pointer to the [IO_CSQ](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure for the cancel-safe IRP queue.

### `Irql` [out]

Pointer to a variable that the *CsqAcquireLock* routine can use to store the current IRQL. The system passes the stored value [CsqReleaseLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_release_lock) when it releases the lock.

## Remarks

The driver specifies the *CsqAcquireLock* routine for a cancel-safe IRP queue when it initializes the queue's **IO_CSQ** structure. The driver specifies the routine as the *CsqAcquireLock* parameter of [IoCsqInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqinitialize) or [IoCsqInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqinitializeex) when it initializes **IO_CSQ**. For more information, see [Cancel-Safe IRP Queues](https://learn.microsoft.com/windows-hardware/drivers/kernel/cancel-safe-irp-queues).

The system calls this routine to acquire a lock on the driver's IRP queue before attempting to insert or remove an IRP from the queue. The system calls the [CsqReleaseLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_release_lock) routine to release the lock.

If the driver uses a spin lock to implement locking for the queue, it must store the current IRQL for when it releases the spin lock. The system passes a pointer to an IRQL variable that the driver can use to store the current IRQL. The system passes the stored value as the *Irql* parameter to *CsqReleaseLock* when it releases the lock. Otherwise the driver can ignore the *Irql* parameter. For information about spin locks, see [Spin Locks](https://learn.microsoft.com/windows-hardware/drivers/kernel/spin-locks).

Drivers can use any locking mechanism to lock the queue, such as mutexes. For more information about mutexes, see [Mutex Objects](https://learn.microsoft.com/windows-hardware/drivers/kernel/mutex-objects).

### Examples

To define a *CsqAcquireLock* callback routine, you must first provide a function declaration that identifies the type of callback routine you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *CsqAcquireLock* callback routine that is named `MyCsqAcquireLock`, use the IO_CSQ_ACQUIRE_LOCK type as shown in this code example:

```cpp
IO_CSQ_ACQUIRE_LOCK MyCsqAcquireLock;
```

Then, implement your callback routine as follows:

```cpp
_Use_decl_annotations_
VOID
 MyCsqAcquireLock(
    PIO_CSQ  Csq,
    PKIRQL  Irql
    )
  {
      // Function body
  }
```

The IO_CSQ_ACQUIRE_LOCK function type is defined in the Wdm.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the `_Use_decl_annotations_` annotation to your function definition. The `_Use_decl_annotations_` annotation ensures that the annotations that are applied to the IO_CSQ_ACQUIRE_LOCK function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for WDM Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-using-function-role-types-for-wdm-drivers). For information about `_Use_decl_annotations_`, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[CsqCompleteCanceledIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_complete_canceled_irp)

[CsqInsertIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_insert_irp)

[CsqInsertIrpEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_insert_irp_ex)

[CsqPeekNextIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_peek_next_irp)

[CsqReleaseLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_release_lock)

[CsqRemoveIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_remove_irp)

[IO_CSQ](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[IoCsqInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqinitialize)

[IoCsqInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqinitializeex)

[IoCsqInsertIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqinsertirp)

[IoCsqInsertIrpEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqinsertirpex)

[IoCsqRemoveIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqremoveirp)

[IoCsqRemoveNextIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqremovenextirp)