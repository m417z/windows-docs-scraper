# SpbControllerSetIoOtherCallback function

## Description

The **SpbControllerSetIoOtherCallback** method registers an SPB controller driver's [EvtSpbControllerIoOther](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_controller_other) callback function.

## Parameters

### `FxDevice` [in]

A WDFDEVICE handle to the device object that represents the SPB controller.

### `EvtSpbControllerIoOther` [in]

A pointer to an [EvtSpbControllerIoOther](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_controller_other) callback function. The SPB controller driver implements this function. The SPB framework extension (SpbCx) calls this function to pass an I/O control request to the controller driver. For more information about the type of I/O requests that are passed to this function, see the following Remarks section.

### `EvtIoInCallerContext` [in, optional]

A pointer to an [EvtIoInCallerContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_io_in_caller_context) callback function that is called when an I/O control request first arrives at the controller's I/O queue, and the request contains an IOCTL code that the SPB framework extension (SpbCx) does not recognize. This callback runs in the process context of the request originator, and can preprocess requests that will later be processed by the *EvtSpbControllerIoOther* callback. This parameter is optional and can be specified as NULL if no such preprocessing is required. For more information, see the following Remarks section.

## Remarks

This method provides a way for your SPB controller driver to declare its support for custom I/O control codes (IOCTLs) that are bus-specific or driver-specific. If the SPB controller driver does not call this method, SpbCx rejects all such I/O control requests, and the SPB controller driver never sees them.

SpbCx manages the I/O queue for the SPB controller. By default, if SpbCx receives an I/O control request that has an IOCTL that it does not support, SpbCx completes the request with error status code STATUS_INVALID_DEVICE_REQUEST.

However, by calling **SpbControllerSetIoOtherCallback**, the SPB controller driver declares its support for I/O control requests that the SPB framework extension (SpbCx) does not support. In this case, when SpbCx receives an I/O control request that has an IOCTL code that it does not support, SpbCx calls the *EvtSpbControllerIoOther* function to pass the request to the SPB controller driver for processing. The SPB controller driver is responsible for completing the request.

For a list of the IOCTLs that SpbCx supports, see [SpbCx I/O Control Codes](https://learn.microsoft.com/previous-versions/hh450915(v=vs.85)).

The optional [EvtIoInCallerContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_io_in_caller_context) callback function runs in the process context of the request originator, and can preprocess context-dependent request parameters, such as buffer pointers, before the request is passed to the [EvtSpbControllerIoOther](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_controller_other) callback function. When the *EvtIoInCallerContext* function is called, any per-request context that the SPB controller driver requested in a previous call to [SpbControllerSetRequestAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spbcontrollersetrequestattributes) will already be allocated and assigned to the request.

The SPB controller driver must call this method before it *commits* the device object—that is, before it returns from the *EvtDriverDeviceAdd* callback or adds the PDO to the controller's child list. The child list represents the devices that are attached to the bus. For more information, see [Enumerating the Devices on a Bus](https://learn.microsoft.com/windows-hardware/drivers/wdf/enumerating-the-devices-on-a-bus).

## See also

[EvtIoInCallerContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_io_in_caller_context)

[EvtSpbControllerIoOther](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_controller_other)

[SpbControllerSetRequestAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spbcontrollersetrequestattributes)