# WdfIoQueueCreate function

## Description

[Applies to KMDF and UMDF]

The **WdfIoQueueCreate** method creates and configures an I/O queue for a specified device.

## Parameters

### `Device` [in]

A handle to the framework device object that the queue will be associated with.

### `Config` [in]

A pointer to a caller-allocated [WDF_IO_QUEUE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ns-wdfio-_wdf_io_queue_config) structure.

### `QueueAttributes` [in, optional]

A pointer to a caller-allocated [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that specifies object attributes for the new object. This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `Queue` [out, optional]

A pointer to a location that receives a handle to a framework queue object.

## Return value

**WdfIoQueueCreate** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An input parameter is invalid. |
| **STATUS_INFO_LENGTH_MISMATCH** | The size of the [WDF_IO_QUEUE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ns-wdfio-_wdf_io_queue_config) structure is incorrect. |
| **STATUS_POWER_STATE_INVALID** | The framework is performing a power management operation. |
| **STATUS_INSUFFICIENT_RESOURCES** | The amount of available memory is too low. |
| **STATUS_WDF_NO_CALLBACK** | The [WDF_IO_QUEUE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ns-wdfio-_wdf_io_queue_config) structure does not specify any [request handlers](https://learn.microsoft.com/windows-hardware/drivers/wdf/request-handlers), and the dispatching method is not **WdfIoQueueDispatchManual**. |
| **STATUS_UNSUCCESSFUL** | The driver is attempting to create a default queue while a default queue already exists for the device, or an internal error occurred. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Each call to **WdfIoQueueCreate** creates an I/O queue for a device. Your driver can create multiple I/O queues for each device.

The *Config* and *QueueAttributes* parameters specify the queue's configuration and object attributes.

By default, the framework device object that the *Device* parameter specifies becomes the parent object for the new framework queue object. If the driver specifies a parent object in the [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure's **ParentObject** member, the parent object can be a framework device object or any object whose chain of parents leads to a framework device object. The framework will delete the queue object when it deletes the parent object.

If your driver provides [EvtCleanupCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_cleanup) or [EvtDestroyCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_destroy) callback functions for the framework queue object, the framework calls these callback functions at IRQL = PASSIVE_LEVEL.

For more information about **WdfIoQueueCreate**, see [Creating I/O Queues](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-i-o-queues).

#### Examples

The following code example is the section of an [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function that creates a device's default I/O queue. The example initializes a [WDF_IO_QUEUE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ns-wdfio-_wdf_io_queue_config) structure and then calls **WdfIoQueueCreate**.

```cpp
NTSTATUS
MyEvtDriverDeviceAdd(
    IN WDFDRIVER  Driver,
    IN PWDFDEVICE_INIT  DeviceInit
    )
{
    WDF_IO_QUEUE_CONFIG  ioQueueConfig;
    WDFQUEUE  hQueue;
...
    WDF_IO_QUEUE_CONFIG_INIT_DEFAULT_QUEUE(
                                           &ioQueueConfig,
                                           WdfIoQueueDispatchSequential
                                           );

    ioQueueConfig.EvtIoDefault = MyEvtIoDefault;

    status = WdfIoQueueCreate(
                              device,
                              &ioQueueConfig,
                              WDF_NO_OBJECT_ATTRIBUTES,
                              &hQueue
                              );
    if (!NT_SUCCESS (status)) {
        return status;
    }
...
}
```

## See also

[WDF_IO_QUEUE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ns-wdfio-_wdf_io_queue_config)

[WDF_IO_QUEUE_CONFIG_INIT_DEFAULT_QUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdf_io_queue_config_init_default_queue)

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WdfDeviceConfigureRequestDispatching](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceconfigurerequestdispatching)

[WdfRequestForwardToIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestforwardtoioqueue)