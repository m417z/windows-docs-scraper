# _SPB_REQUEST_TYPE enumeration

## Description

The **SPB_REQUEST_TYPE** enumeration specifies the type of SPB operation that a client is requesting.

## Constants

### `SpbRequestTypeUndefined`

For internal use only.

### `SpbRequestTypeRead`

 A read operation. The transfer direction for read data is from the target device to the client (peripheral driver). Your SPB controller driver will see requests of this type only if it registers an [EvtSpbControllerIoRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_controller_read) callback function.

### `SpbRequestTypeWrite`

A write operation. The transfer direction for write data is from the client to the target device. Your SPB controller driver receives requests of this type only if it registers an [EvtSpbControllerIoWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_controller_write) callback function.

### `SpbRequestTypeSequence`

A sequence of transfer (read and write) operations combined into a single request. Your SPB controller driver receives requests of this type only if it registers an [EvtSpbControllerIoSequence](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_controller_sequence) callback function. Otherwise, the SPB framework extension (SpbCx) will convert an I/O transfer sequence into a series of I/O requests of type **SpbRequestTypeRead** and **SpbRequestTypeWrite**, and send these requests to the SPB controller driver's *EvtSpbControllerIoRead* and *EvtSpbControllerIoWrite* callback functions.

### `SpbRequestTypeLockController`

A request to lock the controller exclusively for bus transfers to or from the specified target device. Your SPB controller driver receives requests of this type only if it registers an [EvtSpbControllerLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_controller_lock) callback function.

### `SpbRequestTypeUnlockController`

A request to unlock the controller for the specified target device. Your SPB controller driver receives requests of this type through its [EvtSpbControllerUnlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_controller_unlock) callback function.

### `SpbRequestTypeLockConnection`

A request to lock the specified target device for exclusive use by a client. This request is handled entirely by SpbCx. Your SPB controller driver performs no processing for requests of this type. For more information, see [IOCTL_SPB_LOCK_CONNECTION](https://learn.microsoft.com/windows-hardware/drivers/spb/spb-ioctls#ioctl_spb_lock_connection-control-code).

### `SpbRequestTypeUnlockConnection`

A request to unlock the specified target device. This request is handled entirely by SpbCx. Your SPB controller driver performs no processing for requests of this type. For more information, see [IOCTL_SPB_UNLOCK_CONNECTION](https://learn.microsoft.com/windows-hardware/drivers/spb/spb-ioctls#ioctl_spb_unlock_connection-control-code).

### `SpbRequestTypeOther`

An unknown I/O control (IOCTL) request sent by a client (peripheral driver) to a target device on the bus. Call the [WdfRequestGetParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetparameters) method to retrieve the parameters for this request; for this call, use the SPBREQUEST handle for the *Request* parameter. Your SPB controller driver receives requests of this type only if it registers an [EvtSpbControllerIoOther](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_controller_other) callback function. Otherwise, SpbCx rejects unknown IOCTL requests.

### `SpbRequestTypeMax`

For internal use only.

## Remarks

The [SPB_REQUEST_PARAMETERS](https://learn.microsoft.com/previous-versions/hh406209(v=vs.85)) structure contains an **SPB_REQUEST_TYPE** enumeration value.

## See also

* [EvtSpbControllerIoOther](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_controller_other)
* [EvtSpbControllerIoRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_controller_read)
* [EvtSpbControllerIoSequence](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_controller_sequence)
* [EvtSpbControllerIoWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_controller_write)
* [EvtSpbControllerLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_controller_lock)
* [EvtSpbControllerUnlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_controller_unlock)
* [IOCTL_SPB_LOCK_CONNECTION](https://learn.microsoft.com/windows-hardware/drivers/spb/spb-ioctls#ioctl_spb_lock_connection-control-code)
* [IOCTL_SPB_UNLOCK_CONNECTION](https://learn.microsoft.com/windows-hardware/drivers/spb/spb-ioctls#ioctl_spb_unlock_connection-control-code)
* [SPB_REQUEST_PARAMETERS](https://learn.microsoft.com/previous-versions/hh406209(v=vs.85))
* [WdfRequestGetParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetparameters)