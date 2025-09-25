# _SPB_CONTROLLER_CONFIG structure

## Description

The *SPB_CONTROLLER_CONFIG* structure contains the configuration settings for an SPB controller driver.

## Members

### `Size`

The size, in bytes, of this structure. The [SpbDeviceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spbdeviceinitialize) method uses this parameter value to determine which version of the structure is being used.

### `ControllerDispatchType`

The dispatch type of the I/O queue for the controller driver. Set this member to either *WdfIoQueueDispatchSequential* or *WdfIoQueueDispatchParallel*, but not to *WdfIoQueueDispatchManual*. The *SPB_CONTROLLER_CONFIG_INIT* function initializes this member to its default value, *WdfIoQueueDispatchSequential*. For more information about these dispatch types, see [Example Uses of I/O Queues](https://learn.microsoft.com/windows-hardware/drivers/wdf/example-uses-of-i-o-queues).

A controller driver that operates in subordinate mode should set this member to *WdfIoQueueDispatchParallel*. For example, an I2C controller might be attached as a peripheral device to an SPI bus. This device acts as a master on the I2C bus, but is a subordinate on the SPI bus.

### `PowerManaged`

Whether the I/O queue for the controller driver should be power-managed. Set this member to *WdfTrue* to indicate that the queue should be power-managed. Set this member to *WdfFalse* to indicate that the queue should not be power-managed. If this member is set to *WdfDefault*, the queue will be power-managed unless the driver calls the [WdfFdoInitSetFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitsetfilter) method, which identifies the caller as an upper-level or lower-level filter driver. The *SPB_CONTROLLER_CONFIG_INIT* function initializes this member to *WdfDefault*.

When I/O requests are available in a power-managed queue, the framework delivers the requests to the driver only if the device is in its working (D0) state. For more information, see [Power Management for I/O Queues](https://learn.microsoft.com/windows-hardware/drivers/wdf/power-management-for-i-o-queues).

### `EvtSpbTargetConnect`

A pointer to the [EvtSpbTargetConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_target_connect) callback function. This function is implemented by the SPB controller driver. The *EvtSpbTargetConnect* member is optional and can be NULL.

### `EvtSpbTargetDisconnect`

A pointer to the [EvtSpbTargetDisconnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_target_disconnect) callback function. This function is implemented by the SPB controller driver. The *EvtSpbTargetDisconnect* member is optional and can be NULL.

### `EvtSpbControllerLock`

The pointer to the [EvtSpbControllerLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_controller_lock) callback function. This function is implemented by the SPB controller driver. The *EvtSpbControllerLock* member is optional and can be NULL. For more information about the *EvtSpbControllerLock* function, see [Handling Client-Implemented Sequences](https://learn.microsoft.com/windows-hardware/drivers/spb/handling-client-implemented-sequences).

### `EvtSpbControllerUnlock`

A pointer to the [EvtSpbControllerUnlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_controller_unlock) callback function. This function is implemented by the SPB controller driver. This member is optional and can be NULL. For more information about the *EvtSpbControllerUnlock* function, see [Handling Client-Implemented Sequences](https://learn.microsoft.com/windows-hardware/drivers/spb/handling-client-implemented-sequences).

### `EvtSpbIoRead`

A pointer to the [EvtSpbControllerIoRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_controller_read) callback function. This function is implemented by the SPB controller driver. This member is not optional and must not be NULL.

### `EvtSpbIoWrite`

A pointer to the [EvtSpbControllerIoWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_controller_write) callback function. This function is implemented by the SPB controller driver. This member is not optional and must not be NULL.

### `EvtSpbIoSequence`

A pointer to the [EvtSpbControllerIoSequence](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_controller_sequence) callback function. This function is implemented by the SPB controller driver. This member is not optional and must not be NULL.

## Remarks

The [SpbDeviceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spbdeviceinitialize) method uses the information in this structure to complete the initialization of the SPB controller. Before passing this structure to *SpbDeviceInitialize*, call the [SPB_CONTROLLER_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spb_controller_config_init) function to initialize the members of this structure to their default values, and, as needed, overwrite these default values with information that is specific to your SPB controller driver.

## See also

* [EvtSpbControllerIoRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_controller_read)
* [EvtSpbControllerIoSequence](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_controller_sequence)
* [EvtSpbControllerIoWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_controller_write)
* [EvtSpbControllerLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_controller_lock)
* [EvtSpbControllerUnlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_controller_unlock)
* [EvtSpbTargetConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_target_connect)
* [EvtSpbTargetDisconnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_target_disconnect)
* [IOCTL_SPB_EXECUTE_SEQUENCE](https://learn.microsoft.com/windows-hardware/drivers/spb/spb-ioctls#ioctl_spb_execute_sequence)
* [IOCTL_SPB_LOCK_CONTROLLER](https://learn.microsoft.com/windows-hardware/drivers/spb/spb-ioctls#ioctl_spb_lock_controller-control-code)
* [IOCTL_SPB_UNLOCK_CONTROLLER](https://learn.microsoft.com/windows-hardware/drivers/spb/spb-ioctls#ioctl_spb_unlock_controller-control-code)
* [IRP_MN_READ](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-read-config)
* [IRP_MN_WRITE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-write-config)
* [SPB_CONTROLLER_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spb_controller_config_init)
* [SpbDeviceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spbdeviceinitialize)
* [SpbRequestGetParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spbrequestgetparameters)
* [WdfFdoInitSetFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitsetfilter)