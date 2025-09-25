# WdfFileObjectGetDevice function

## Description

[Applies to KMDF and UMDF]

The **WdfFileObjectGetDevice** method returns the framework device object that is associated with a specified framework file object.

## Parameters

### `FileObject` [in]

A handle to a framework file object.

## Return value

**WdfFileObjectGetDevice** returns a handle to the framework device object that is associated with the specified framework file object.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

For more information about framework file objects, see [Framework File Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-file-objects).

#### Examples

The following code example shows how an [EvtFileClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_file_close) callback function can obtain the framework device object that is associated with a specified framework file object.

```cpp
VOID
MyEvtFileClose(
    IN WDFFILEOBJECT  FileObject
    )
{
    WDFDEVICE device;

    device = WdfFileObjectGetDevice(FileObject);
...
}
```