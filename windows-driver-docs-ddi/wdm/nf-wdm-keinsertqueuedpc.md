# KeInsertQueueDpc function

## Description

The **KeInsertQueueDpc** routine queues a DPC for execution.

## Parameters

### `Dpc` [in, out]

Pointer to the [KDPC](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure for the DPC object. This structure must have been initialized by either [KeInitializeDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializedpc) or [KeInitializeThreadedDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializethreadeddpc).

### `SystemArgument1` [in, optional]

Specifies driver-determined context data. This value is passed as the *SystemArgument1* parameter to the DPC object's [CustomDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kdeferred_routine) or [CustomThreadedDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kdeferred_routine) routine.

### `SystemArgument2` [in, optional]

Specifies driver-determined context data. This value is passed as the *SystemArgument2* parameter to the DPC object's [CustomDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kdeferred_routine) or *CustomThreadedDpc* routine.

## Return value

If the specified DPC object is not currently in a DPC queue, **KeInsertQueueDpc** queues the DPC and returns **TRUE**.

## Remarks

If the specified DPC object has already been queued, no operation is performed except to return **FALSE**. Otherwise, the DPC object is inserted in a DPC queue. For more information about DPC queues, see [Organization of DPC Queues](https://learn.microsoft.com/windows-hardware/drivers/kernel/organization-of-dpc-queues).

Note that a particular DPC object and the function that it represents can each be queued for execution only once at any particular time.

## See also

[CustomDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kdeferred_routine)

[CustomThreadedDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kdeferred_routine)

[KeInitializeDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializedpc)

[KeRemoveQueueDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keremovequeuedpc)