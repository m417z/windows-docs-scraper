# KeInitializeThreadedDpc function

## Description

The **KeInitializeThreadedDpc** routine initializes a threaded DPC object, and registers a [CustomThreadedDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kdeferred_routine) routine for that object.

## Parameters

### `Dpc` [out]

Pointer to a [KDPC](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure that represents the DPC object to initialize. The caller must allocate storage for the structure from resident memory.

### `DeferredRoutine` [in]

Pointer to the *CustomThreadedDpc* routine to associate with the DPC.

### `DeferredContext` [in, optional]

Specifies the value to pass as the *DeferredContext* parameter to *CustomThreadedDpc*.

## Remarks

For more information about threaded DPCs, see [Introduction to Threaded DPCs](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-threaded-dpcs).

## See also

[CustomThreadedDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kdeferred_routine)

[KeInsertQueueDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinsertqueuedpc)

[KeRemoveQueueDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keremovequeuedpc)