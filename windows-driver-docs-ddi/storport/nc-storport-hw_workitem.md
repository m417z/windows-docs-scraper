# HW_WORKITEM callback function

## Description

A miniport-provided callback function for processing a Storport work item request.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the miniport driver's per-HBA storage area.

### `Context` [in, optional]

Optional context provided by the miniport in the **Callback** parameter of [**StorPortQueueWorkItem**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportqueueworkitem).

### `Worker` [in]

A pointer to an opaque buffer that holds context information for the work item returned by [**StorPortInitializeWorker**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializeworker).

## Remarks

If needed, a work item can be queued within **HwStorWorkItem**. Call [**StorPortQueueWorkItem**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportqueueworkitem) with the current work item to reuse it. Otherwise, call [**StorPortFreeWorker**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportfreeworker) to release the work item.

No locks are acquired by Storport when the callback is invoked. The miniport is responsible for any synchronization required in the callback routine.

The name **HwStorWorkItem** is just a placeholder for the miniport function that is pointed to by the **Callback** parameter of [**StorPortQueueWorkItem**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportqueueworkitem). The actual prototype of this routine is defined in *Storport.h* as follows:

``` c
typedef
VOID
HW_WORKITEM (
    _In_     PVOID HwDeviceExtension,
    _In_Opt_ PVOID Context,
    _In_     PVOID Worker,
    );
```

## See also

[**StorPortFreeWorker**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportfreeworker)

[**StorPortInitializeWorker**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializeworker)

[**StorPortQueueWorkItem**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportqueueworkitem)