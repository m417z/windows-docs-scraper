# WdfUsbTargetPipeConfigContinuousReader function

## Description

[Applies to KMDF and UMDF]

The **WdfUsbTargetPipeConfigContinuousReader** method configures the framework to continuously read from a specified USB pipe.

## Parameters

### `Pipe` [in]

A handle to a framework pipe object that was obtained by calling [WdfUsbInterfaceGetConfiguredPipe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfacegetconfiguredpipe).

### `Config` [in]

A pointer to a caller-allocated [WDF_USB_CONTINUOUS_READER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_continuous_reader_config) structure.

## Return value

**WdfUsbTargetPipeConfigContinuousReader** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method can return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INFO_LENGTH_MISMATCH** | The size of the [WDF_USB_CONTINUOUS_READER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_continuous_reader_config) structure that the *Config* parameter specified was incorrect. |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was detected. |
| **STATUS_INSUFFICIENT_RESOURCES** | Insufficient memory was available. |
| **STATUS_INVALID_DEVICE_REQUEST** | The pipe's type was not valid. |
| **STATUS_INTEGER_OVERFLOW** | The **HeaderLength**, **TransferLength**, or **TrailerLength** member of the [WDF_USB_CONTINUOUS_READER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_continuous_reader_config) structure that the *Config* parameter specified a size what was too large or otherwise invalid. |
| **STATUS_INVALID_BUFFER_SIZE** | The size of the read buffer was not a multiple of the pipe's maximum packet size. |

For a list of other return values that the **WdfUsbTargetPipeConfigContinuousReader** method might return, see [Framework Object Creation Errors](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-creation-errors).

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

You can configure a continuous reader for a bulk pipe or an interrupt pipe. The pipe must have an input endpoint.

After calling **WdfUsbTargetPipeConfigContinuousReader** to configure a continuous reader, your driver must call [WdfIoTargetStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetstart) to start the reader. To stop the reader, the driver must call [WdfIoTargetStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetstop).

Typically, a driver calls **WdfUsbTargetPipeConfigContinuousReader** from within its [EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware) callback function. The driver should call [WdfIoTargetStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetstart) from within its [EvtDeviceD0Entry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_entry) callback function and should call [WdfIoTargetStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetstop) from within its [EvtDeviceD0Exit](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_exit) callback function.

Each time the pipe's I/O target successfully completes a read request, the framework calls the driver's [EvtUsbTargetPipeReadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nc-wdfusb-evt_wdf_usb_reader_completion_routine) callback function. If the I/O target reports a failure while processing a request, the framework calls the driver's [EvtUsbTargetPipeReadersFailed](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nc-wdfusb-evt_wdf_usb_readers_failed) callback function after all read requests have been completed. (Therefore, the *EvtUsbTargetPipeReadComplete* callback function will not be called while the *EvtUsbTargetPipeReadersFailed* callback function is executing).

If you do not supply the optional [EvtUsbTargetPipeReadersFailed](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nc-wdfusb-evt_wdf_usb_readers_failed) callback, the framework responds to a failed read attempt by sending another read request. Therefore if the bus is in a state where it is not accepting reads, the framework continually sends new requests to recover from a failed read.

After a driver has called **WdfUsbTargetPipeConfigContinuousReader**, the driver cannot use [WdfUsbTargetPipeReadSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetpipereadsynchronously) or [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend) to send I/O requests to the pipe unless the continuous reader has been stopped. To stop the reader, the driver can call [WdfIoTargetStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetstop) or return **FALSE** from its [EvtUsbTargetPipeReadersFailed](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nc-wdfusb-evt_wdf_usb_readers_failed) callback function. If the driver calls **WdfUsbTargetPipeReadSynchronously** while the reader is stopped, it must set the WDF_REQUEST_SEND_OPTION_IGNORE_TARGET_STATE flag in the **Flags** member of the *RequestOptions* parameter. Otherwise the request will be pended until the target is restarted.

The framework sets the USBD_SHORT_TRANSFER_OK flag in its internal [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb). Setting this flag allows the last packet of a data transfer to be less than the maximum packet size.

For more information about the **WdfUsbTargetPipeConfigContinuousReader** method and USB I/O targets, see [Reading from a Pipe](https://learn.microsoft.com/windows-hardware/drivers/wdf/working-with-usb-pipes).

#### Examples

The following code example initializes a [WDF_USB_CONTINUOUS_READER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_continuous_reader_config) structure and calls **WdfUsbTargetPipeConfigContinuousReader**.

```cpp
WDF_USB_CONTINUOUS_READER_CONFIG  contReaderConfig;
NTSTATUS  status;

WDF_USB_CONTINUOUS_READER_CONFIG_INIT(
                                      &contReaderConfig,
                                      OsrFxEvtUsbInterruptPipeReadComplete,
                                      DeviceContext,
                                      sizeof(UCHAR)
                                      );
status = WdfUsbTargetPipeConfigContinuousReader(
                                      Pipe,
                                      &contReaderConfig
                                      );
```

## See also

[EvtDeviceD0Entry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_entry)

[EvtDeviceD0Exit](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_exit)

[EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware)

[EvtUsbTargetPipeReadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nc-wdfusb-evt_wdf_usb_reader_completion_routine)

[EvtUsbTargetPipeReadersFailed](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nc-wdfusb-evt_wdf_usb_readers_failed)

[URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb)

[WDF_USB_CONTINUOUS_READER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_continuous_reader_config)

[WDF_USB_CONTINUOUS_READER_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_continuous_reader_config_init)

[WdfIoTargetStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetstart)

[WdfIoTargetStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetstop)

[WdfUsbInterfaceGetConfiguredPipe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfacegetconfiguredpipe)