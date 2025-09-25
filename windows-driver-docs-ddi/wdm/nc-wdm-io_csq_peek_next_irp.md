## Description

The *CsqPeekNextIrp* routine is used by the system to find the next matching IRP in a driver-implemented, cancel-safe IRP queue.

## Parameters

### `Csq` [in]

Pointer to the [IO_CSQ](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure for the cancel-safe IRP queue.

### `Irp` [in, optional]

Pointer to an IRP in the driver's IRP queue, or **NULL** to specify the beginning of the queue.

### `PeekContext` [in, optional]

Pointer to driver-defined context information. The *CsqPeekNextIrp* routine returns the first IRP that follows *Irp* and matches *PeekContext*.

## Return value

*CsqPeekNextIrp* returns the first IRP that follows *Irp* in the queue and matches *PeekContext*, or **NULL** if there is no matching IRP. If *Irp* is **NULL**, *CsqPeekNextIrp* returns the first matching IRP in the queue, or **NULL** if there is no matching IRP.

## Remarks

The driver specifies the *CsqPeekNextIrp* routine for a cancel-safe IRP queue when it initializes the queue's **IO_CSQ** structure. The driver specifies the routine as the *CsqPeekNextIrp* parameter of [IoCsqInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqinitialize) or [IoCsqInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqinitializeex) when it initializes **IO_CSQ**. For more information, see [Cancel-Safe IRP Queues](https://learn.microsoft.com/windows-hardware/drivers/kernel/cancel-safe-irp-queues).

The system uses *CsqPeekNextIrp* to iterate through the IRPs in the driver's IRP queue. For example, the [IoCsqRemoveNextIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqremovenextirp) routine uses this routine to find the IRP to be removed.

### Examples

To define a *CsqPeekNextIrp* callback routine, you must first provide a function declaration that identifies the type of callback routine you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *CsqPeekNextIrp* callback routine that is named `MyCsqPeekNextIrp`, use the IO_CSQ_PEEK_NEXT_IRP type as shown in this code example:

```cpp
IO_CSQ_PEEK_NEXT_IRP MyCsqPeekNextIrp;
```

Then, implement your callback routine as follows:

```cpp
_Use_decl_annotations_
PIRP
 MyCsqPeekNextIrp(
    PIO_CSQ  Csq,
    PIRP  Irp,
    PVOID  PeekContext
    )
  {
      // Function body
  }
```

The IO_CSQ_PEEK_NEXT_IRP function type is defined in the Wdm.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the `_Use_decl_annotations_` annotation to your function definition. The `_Use_decl_annotations_` annotation ensures that the annotations that are applied to the IO_CSQ_PEEK_NEXT_IRP function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for WDM Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-using-function-role-types-for-wdm-drivers). For information about `_Use_decl_annotations_`, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[CsqAcquireLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_acquire_lock)

[CsqCompleteCanceledIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_complete_canceled_irp)

[CsqInsertIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_insert_irp)

[CsqInsertIrpEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_insert_irp_ex)

[CsqReleaseLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_release_lock)

[CsqRemoveIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_remove_irp)

[IO_CSQ](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[IoCsqInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqinitialize)

[IoCsqInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqinitializeex)

[IoCsqInsertIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqinsertirp)

[IoCsqInsertIrpEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqinsertirpex)

[IoCsqRemoveIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqremoveirp)

[IoCsqRemoveNextIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqremovenextirp)