# WdfFileObjectWdmGetFileObject function

## Description

[Applies to KMDF only]

The **WdfFileObjectWdmGetFileObject** method returns the Windows Driver Model (WDM) file object that is associated with a specified framework file object.

## Parameters

### `FileObject` [in]

A handle to a framework file object.

## Return value

**WdfFileObjectWdmGetFileObject** returns a pointer to the [FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) structure that is associated with the specified framework file object, or **NULL** if there is no WDM file object for the specified framework file object.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

The pointer that the **WdfFileObjectWdmGetFileObject** method returns is valid until the framework file object is deleted. If the driver provides an [EvtCleanupCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_cleanup) function for the framework file object, the pointer is valid until the callback function returns.

For more information about framework file objects, see [Framework File Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-file-objects).

#### Examples

The following code example obtains a handle to the WDM file object that is associated with a specified framework file object.

```cpp
PFILE_OBJECT  pReturnedFileObject;

pReturnedFileObject = WdfFileObjectWdmGetFileObject(fileObject);
```

## See also

[FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object)