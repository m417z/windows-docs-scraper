## Description

The *CsqInsertIrp* routine is used by the system to insert an IRP into a driver-implemented, cancel-safe IRP queue.

## Parameters

### `Csq` [in]

Pointer to the [IO_CSQ](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure for the cancel-safe IRP queue.

### `Irp` [in]

Pointer to the IRP to insert into the IRP queue.

## Remarks

The driver specifies the *CsqInsertIrp* routine for a cancel-safe IRP queue when it initializes the queue's **IO_CSQ** structure. The driver specifies the routine as the *CsqInsertIrp* parameter of [IoCsqInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqinitialize) when it initializes **IO_CSQ**. For more information, see [Cancel-Safe IRP Queues](https://learn.microsoft.com/windows-hardware/drivers/kernel/cancel-safe-irp-queues).

The [IoCsqInsertIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqinsertirp) and [IoCsqInsertIrpEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqinsertirpex) routines call *CsqInsertIrp* to insert the IRP into the queue.

### Examples

To define a *CsqInsertIrp* callback routine, you must first provide a function declaration that identifies the type of callback routine you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *CsqInsertIrp* callback routine that is named `MyCsqInsertIrp`, use the IO_CSQ_INSERT_IRP type as shown in this code example:

```cpp
IO_CSQ_INSERT_IRP MyCsqInsertIrp;
```

Then, implement your callback routine as follows:

```cpp
_Use_decl_annotations_
NTSTATUS
 MyCsqInsertIrp(
    struct _IO_CSQ  *Csq,
    PIRP  Irp
    )
  {
      // Function body
  }
```

The IO_CSQ_INSERT_IRP function type is defined in the Wdm.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the `_Use_decl_annotations_` annotation to your function definition. The `_Use_decl_annotations_` annotation ensures that the annotations that are applied to the IO_CSQ_INSERT_IRP function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for WDM Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-using-function-role-types-for-wdm-drivers). For information about `_Use_decl_annotations_`, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[CsqAcquireLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_acquire_lock)

[CsqCompleteCanceledIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_complete_canceled_irp)

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