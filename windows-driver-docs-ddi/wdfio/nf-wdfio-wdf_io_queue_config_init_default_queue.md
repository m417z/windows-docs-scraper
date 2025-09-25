# WDF_IO_QUEUE_CONFIG_INIT_DEFAULT_QUEUE function

## Description

[Applies to KMDF and UMDF]

The **WDF_IO_QUEUE_CONFIG_INIT_DEFAULT_QUEUE** function initializes a driver's [WDF_IO_QUEUE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ns-wdfio-_wdf_io_queue_config) structure.

## Parameters

### `Config` [out]

A pointer to the driver's [WDF_IO_QUEUE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ns-wdfio-_wdf_io_queue_config) structure.

### `DispatchType` [in]

A [WDF_IO_QUEUE_DISPATCH_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ne-wdfio-_wdf_io_queue_dispatch_type) enumerator that identifies the request dispatching type for the queue.

## Remarks

Drivers should call **WDF_IO_QUEUE_CONFIG_INIT_DEFAULT_QUEUE** when creating a power-managed I/O queue that is a device's default queue. The **WDF_IO_QUEUE_CONFIG_INIT_DEFAULT_QUEUE** function zeros the specified [WDF_IO_QUEUE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ns-wdfio-_wdf_io_queue_config) structure and sets its **Size** member. It also sets the **PowerManaged** member to **WdfUseDefault**, sets the **DefaultQueue** member to **TRUE**, and stores the specified dispatching type in the **DispatchType** member.

Starting in KMDF version 1.9, if *DispatchType* is set to **WdfIoQueueDispatchParallel**, **WDF_IO_QUEUE_CONFIG_INIT_DEFAULT_QUEUE** sets the structure's **NumberOfPresentedRequests** member to -1. This value indicates that the framework can deliver an unlimited number of I/O requests to the driver.

For a code example that uses **WDF_IO_QUEUE_CONFIG_INIT_DEFAULT_QUEUE**, see [WdfIoQueueCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuecreate).

## See also

[WDF_IO_QUEUE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ns-wdfio-_wdf_io_queue_config)

[WDF_IO_QUEUE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdf_io_queue_config_init)

[WDF_IO_QUEUE_DISPATCH_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ne-wdfio-_wdf_io_queue_dispatch_type)

[WdfIoQueueCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuecreate)