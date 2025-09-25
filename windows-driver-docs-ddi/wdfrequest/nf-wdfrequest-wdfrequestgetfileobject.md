# WdfRequestGetFileObject function

## Description

[Applies to KMDF and UMDF]

The **WdfRequestGetFileObject** method retrieves the framework file object that is associated with a specified I/O request.

## Parameters

### `Request` [in]

A handle to a framework request object.

## Return value

**WdfRequestGetFileObject** returns a handle to the framework file object, if the framework has created a file object for the specified request. Otherwise, this method returns **NULL**. (A driver typically tests for a **NULL** return value only if it sets the [WdfFileObjectCanBeOptional](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_fileobject_class) bit flag in the [WDF_FILEOBJECT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_fileobject_config) structure.)

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

The **WdfRequestGetFileObject** method returns **NULL** if either:

* Your driver has not called [WdfDeviceInitSetFileObjectConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetfileobjectconfig) and specified a [WDF_FILEOBJECT_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_fileobject_class) value that causes the framework to create file objects.
* Another driver sent a read, write, or I/O control request to your driver without first sending a request type of [WdfRequestTypeCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ne-wdfrequest-_wdf_request_type).

For more information about **WdfRequestGetFileObject** and framework file objects, see [Framework File Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-file-objects).

#### Examples

The following code example obtains an I/O request's file object and then calls a driver-defined routine that obtains a pointer to the file object's context space.

```cpp
VOID
MyEvtIoWrite(
    IN WDFQUEUE  Queue,
    IN WDFREQUEST  Request,
    IN size_t  Length
    )
{
    WDFFILEOBJECT  fileObject;
    PFILE_OPEN_CONTEXT  pOpenContext;

    fileObject = WdfRequestGetFileObject(Request);
    pOpenContext = GetFileObjectContext(fileObject)->OpenContext;
}
```

## See also

[WDF_FILEOBJECT_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_fileobject_class)

[WdfDeviceInitSetFileObjectConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetfileobjectconfig)