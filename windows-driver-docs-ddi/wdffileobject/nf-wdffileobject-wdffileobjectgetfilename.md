# WdfFileObjectGetFileName function

## Description

[Applies to KMDF and UMDF]

The **WdfFileObjectGetFileName** method returns the file name that a specified framework file object contains.

## Parameters

### `FileObject` [in]

A handle to a framework file object.

## Return value

**WdfFileObjectGetFileName** returns a pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains the file name. The method returns **NULL** if there is no WDM file object for the specified framework file object, or if it is called at an IRQL higher than PASSIVE_LEVEL.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

If a driver specified a reference string when it called [WdfDeviceCreateDeviceInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreatedeviceinterface), **WdfFileObjectGetFileName** returns the reference string prepended by a backslash. To determine the reference string, remove the backslash.

The returned string can contain a file name or a reference string. The string does not contain the device name. If an application or kernel-mode component has opened the device instead of a file, with no reference string, the **Length** member of the returned UNICODE_STRING structure is zero.

Your driver should only call **WdfFileObjectGetFileName** while it is processing a file creation request (**WdfRequestTypeCreate** request type). Your driver might process **WdfRequestTypeCreate**-typed I/O requests in an [EvtDeviceFileCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_file_create) callback function.

Or, instead of providing an [EvtDeviceFileCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_file_create) callback function, the driver can call [WdfDeviceConfigureRequestDispatching](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceconfigurerequestdispatching) to set an I/O queue to receive all file creation requests (**WdfRequestTypeCreate** request type). The driver will subsequently receive file creation requests in the queue's [EvtIoDefault](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_default) request handler.

 For more information about framework file objects, see [Framework File Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-file-objects).

For more information about file names, see [Controlling Device Namespace Access](https://learn.microsoft.com/windows-hardware/drivers/kernel/controlling-device-namespace-access).

For more information about reference strings, see [IoRegisterDeviceInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterdeviceinterface).

#### Examples

The following code example shows how an [EvtDeviceFileCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_file_create) callback function can obtain the name of the file that an application has opened.

```cpp
VOID
MyEvtDeviceFileCreate (
    IN WDFDEVICE  Device,
    IN WDFREQUEST  Request,
    IN WDFFILEOBJECT  FileObject
    )
{
    PUNICODE_STRING  fileName;

    fileName = WdfFileObjectGetFileName(FileObject);
...

}
```

## See also

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)

[WdfDeviceCreateDeviceInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreatedeviceinterface)