# WDF_IO_QUEUE_CONFIG_INIT function

## Description

[Applies to KMDF and UMDF]

The **WDF_IO_QUEUE_CONFIG_INIT** function initializes a driver's [WDF_IO_QUEUE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ns-wdfio-_wdf_io_queue_config) structure.

## Parameters

### `Config` [out]

A pointer to the driver's [WDF_IO_QUEUE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ns-wdfio-_wdf_io_queue_config) structure.

### `DispatchType` [in]

A [WDF_IO_QUEUE_DISPATCH_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ne-wdfio-_wdf_io_queue_dispatch_type) enumerator that identifies the request dispatching type for the queue.

## Remarks

Drivers should call **WDF_IO_QUEUE_CONFIG_INIT** when creating a power-managed I/O queue that is not a device's default queue. The **WDF_IO_QUEUE_CONFIG_INIT** function zeros the specified [WDF_IO_QUEUE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ns-wdfio-_wdf_io_queue_config) structure and sets its **Size** member. It also sets the **PowerManaged** member to **WdfUseDefault** and stores the specified dispatching type in the **DispatchType** member.

Starting in KMDF version 1.9, if *DispatchType* is set to **WdfIoQueueDispatchParallel**, **WDF_IO_QUEUE_CONFIG_INIT** sets the structure's **NumberOfPresentedRequests** member to -1. This value indicates that the framework can deliver an unlimited number of I/O requests to the driver.

#### Examples

The following code example initializes [WDF_IO_QUEUE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ns-wdfio-_wdf_io_queue_config) structure and then calls [WdfIoQueueCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuecreate).

```cpp
WDF_IO_QUEUE_CONFIG  queueConfig;
NTSTATUS  status = STATUS_SUCCESS;
WDFQUEUE  readQueue;

WDF_IO_QUEUE_CONFIG_INIT(
                         &queueConfig,
                         WdfIoQueueDispatchManual
                         );
status = WdfIoQueueCreate(
                          hDevice,
                          &queueConfig,
                          WDF_NO_OBJECT_ATTRIBUTES,
                          &readQueue
                          );
```

## See also

[WDF_IO_QUEUE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ns-wdfio-_wdf_io_queue_config)

[WDF_IO_QUEUE_CONFIG_INIT_DEFAULT_QUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdf_io_queue_config_init_default_queue)

[WDF_IO_QUEUE_DISPATCH_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ne-wdfio-_wdf_io_queue_dispatch_type)

[WdfIoQueueCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuecreate)