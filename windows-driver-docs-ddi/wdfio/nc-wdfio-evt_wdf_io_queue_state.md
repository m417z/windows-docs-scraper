# EVT_WDF_IO_QUEUE_STATE callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtIoQueueState* event callback function delivers queue state information to the driver.

## Parameters

### `Queue` [in]

A handle to an I/O queue object.

### `Context` [in]

Driver-defined context information that the driver specified when it registered the *EvtIoQueueState* callback function.

## Remarks

Drivers can register an *EvtIoQueueState* callback function by specifying its address as input to [WdfIoQueueStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuestop), [WdfIoQueueDrain](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuedrain), [WdfIoQueuePurge](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuepurge), or [WdfIoQueueReadyNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuereadynotify). The framework calls the *EvtIoQueueState* callback function after the specified operation completes.

The *EvtIoQueueState* callback function can be called at IRQL <= DISPATCH_LEVEL, unless the **ExecutionLevel** member of the queue's [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) is set to **WdfExecutionLevelPassive**, in which case it is called at IRQL = PASSIVE_LEVEL. If the queue specifies **WdfExecutionLevelInheritFromParent**, the property can be inherited from the WDFDEVICE or WDFDRIVER's [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes).

If the IRQL is PASSIVE_LEVEL, the framework calls the callback function within a [critical region](https://learn.microsoft.com/windows-hardware/drivers/kernel/critical-regions-and-guarded-regions).

## See also

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WdfIoQueueDrain](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuedrain)

[WdfIoQueuePurge](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuepurge)

[WdfIoQueueReadyNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuereadynotify)

[WdfIoQueueStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuestop)