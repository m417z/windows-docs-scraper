# _WDF_IO_QUEUE_CONFIG structure

## Description

[Applies to KMDF and UMDF]

The **WDF_IO_QUEUE_CONFIG** structure contains configuration information for a framework queue object.

## Members

### `Size`

The length, in bytes, of this structure.

### `DispatchType`

A [WDF_IO_QUEUE_DISPATCH_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ne-wdfio-_wdf_io_queue_dispatch_type) enumerator that identifies the request dispatching type for the queue.

### `PowerManaged`

A [WDF_TRI_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftypes/ne-wdftypes-_wdf_tri_state)-typed value that, if set to **WdfTrue**, indicates that the framework handles power management of the queue.

If set to **WdfFalse**, the driver must handle power management of the queue.

If set to **WdfUseDefault**, the framework handles power management for the queue unless the driver calls [WdfFdoInitSetFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitsetfilter).

Drivers above the [power policy owner](https://learn.microsoft.com/windows-hardware/drivers/wdf/power-policy-ownership) in the driver stack must not set the **PowerManaged** member to **WdfTrue**.

For more information about power-managed I/O queues, see [Power Management for I/O Queues](https://learn.microsoft.com/windows-hardware/drivers/wdf/power-management-for-i-o-queues).

### `AllowZeroLengthRequests`

A Boolean value that, if **TRUE**, indicates that the driver expects to receive read or write requests that have a buffer length of zero, so the framework delivers these requests to the driver. If **FALSE**, the framework does not deliver these requests to the driver; instead, it completes them with a completion status of STATUS_SUCCESS.

### `DefaultQueue`

A Boolean value that, if **TRUE**, indicates that the queue will be the device's [default I/O queue](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-i-o-queues). If **FALSE**, the queue will not be the device's default queue.

### `EvtIoDefault`

A pointer to the driver's queue-specific [EvtIoDefault](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_default) callback function, or **NULL**.

### `EvtIoRead`

A pointer to the driver's queue-specific [EvtIoRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_read) callback function, or **NULL**.

### `EvtIoWrite`

A pointer to the driver's queue-specific [EvtIoWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_write) callback function, or **NULL**.

### `EvtIoDeviceControl`

A pointer to the driver's queue-specific [EvtIoDeviceControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_device_control) callback function, or **NULL**.

### `EvtIoInternalDeviceControl`

A pointer to the driver's queue-specific [EvtIoInternalDeviceControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_internal_device_control) callback function, or **NULL**.

### `EvtIoStop`

A pointer to the driver's queue-specific [EvtIoStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_stop) callback function, or **NULL**.

### `EvtIoResume`

A pointer to the driver's queue-specific [EvtIoResume](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_resume) callback function, or **NULL**.

### `EvtIoCanceledOnQueue`

A pointer to the driver's queue-specific [EvtIoCanceledOnQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_canceled_on_queue) callback function, or **NULL**.

### `Settings`

### `Settings.Parallel`

### `Settings.Parallel.NumberOfPresentedRequests`

For the parallel [dispatching method](https://learn.microsoft.com/windows-hardware/drivers/wdf/dispatching-methods-for-i-o-requests), the maximum number of I/O requests that the framework asynchronously delivers to the I/O queue's request handlers. For more information, see the following Remarks section. For the sequential and manual dispatching methods, this member must be zero. This member is available in version 1.9 and later versions of KMDF.

### `Driver`

For internal use only. Set to NULL. This member is available in version 1.11 and later versions of KMDF.

## Remarks

The driver must initialize the **WDF_IO_QUEUE_CONFIG** structure by calling [WDF_IO_QUEUE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdf_io_queue_config_init) or [WDF_IO_QUEUE_CONFIG_INIT_DEFAULT_QUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdf_io_queue_config_init_default_queue).

The WDF_IO_QUEUE_CONFIG structure is used as an input parameter to [WdfIoQueueCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuecreate).

Beginning with version 1.9 of KMDF, drivers can use the **NumberOfPresentedRequests** member to specify the maximum number of I/O requests that the framework asynchronously delivers to a parallel I/O queue's request handlers. After the framework has delivered the specified number of I/O requests to the driver, it does not deliver more requests from the queue until the driver [completes](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests), [cancels](https://learn.microsoft.com/windows-hardware/drivers/wdf/canceling-i-o-requests), or [requeues](https://learn.microsoft.com/windows-hardware/drivers/wdf/requeuing-i-o-requests) at least one of the requests.

For parallel queues,
[WDF_IO_QUEUE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdf_io_queue_config_init) and [WDF_IO_QUEUE_CONFIG_INIT_DEFAULT_QUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdf_io_queue_config_init_default_queue) set the **NumberOfPresentedRequests** member to its default value (-1), which indicates that the framework can deliver an unlimited number of I/O requests to the driver.

## See also

[WDF_IO_QUEUE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdf_io_queue_config_init)

[WDF_IO_QUEUE_CONFIG_INIT_DEFAULT_QUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdf_io_queue_config_init_default_queue)

[WDF_IO_QUEUE_DISPATCH_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ne-wdfio-_wdf_io_queue_dispatch_type)

[WdfIoQueueCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuecreate)

[WdfIoQueueReadyNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuereadynotify)