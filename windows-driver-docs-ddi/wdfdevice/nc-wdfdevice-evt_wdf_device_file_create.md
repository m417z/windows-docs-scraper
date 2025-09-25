# EVT_WDF_DEVICE_FILE_CREATE callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtDeviceFileCreate* callback function handles operations that must be performed when an application requests access to a device.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `Request` [in]

A handle to a framework request object that represents a file creation request.

### `FileObject` [in]

A handle to a framework file object that describes a file that is being opened for the specified request. This parameter is **NULL** if the driver has specified [WdfFileObjectNotRequired](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_fileobject_class) for the **FileObjectClass** member of the [WDF_FILEOBJECT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_fileobject_config) structure.

## Remarks

The framework calls a driver's *EvtDeviceFileCreate* callback function when a user application or another driver opens the device to perform an I/O operation, such as reading or writing a file.

The driver can pass the *Request* handle to [WdfRequestGetParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetparameters) to retrieve parameters that are associated with the file creation request. The parameters are stored in the **Parameters.Create** member of the [WDF_REQUEST_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_parameters) structure.

This callback function is called synchronously, in the context of the thread that opens the device.

To register an *EvtDeviceFileCreate* callback function, the driver must call the [WdfDeviceInitSetFileObjectConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetfileobjectconfig) method.

The driver must either complete the request or send it with [**WDF_REQUEST_SEND_OPTION_SEND_AND_FORGET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ne-wdfrequest-_wdf_request_send_options_flags).

Alternatively, the driver can receive create requests in a queue. For more info, see [**WdfDeviceConfigureRequestDispatching**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceconfigurerequestdispatching).

For more information about framework file objects and the *EvtDeviceFileCreate* callback function, see [Framework File Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-file-objects).

## See also

[WDF_FILEOBJECT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_fileobject_config)