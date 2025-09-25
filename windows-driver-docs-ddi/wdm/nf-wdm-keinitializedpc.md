# KeInitializeDpc function

## Description

The **KeInitializeDpc** routine initializes a DPC object, and registers a [CustomDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kdeferred_routine) routine for that object.

## Parameters

### `Dpc` [out]

Pointer to a [KDPC](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure that represents the DPC object to initialize. The caller must allocate storage for the structure from resident memory.

### `DeferredRoutine` [in]

Pointer to the [CustomDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kdeferred_routine) routine to associate with the DPC.

### `DeferredContext` [in, optional]

Specifies the value to pass as the *DeferredContext* parameter to [CustomDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kdeferred_routine).

## Remarks

The caller can queue an initialized DPC with [KeInsertQueueDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinsertqueuedpc). The caller also can set up a timer object associated with the initialized DPC object and queue the DPC with [KeSetTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesettimer).

Storage for the DPC object must be resident: in the device extension of a driver-created device object, in the controller extension of a driver-created controller object, or in nonpaged pool allocated by the caller.

## See also

[CustomDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kdeferred_routine)

[KeInsertQueueDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinsertqueuedpc)

[KeRemoveQueueDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keremovequeuedpc)

[KeSetTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesettimer)