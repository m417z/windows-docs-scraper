# WdfDeviceGetFileObject function

## Description

[Applies to KMDF only]

The **WdfDeviceGetFileObject** method returns a handle to the framework file object that is associated with a specified WDM file object.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `FileObject` [in]

A pointer to a WDM [FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) structure.

## Return value

**WdfDeviceGetFileObject** returns a handle to the framework file object that is associated with the specified WDM file object. If a framework file object was not created for the file, or if the *FileObject* pointer is invalid, the method returns **NULL**.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

For more information about framework file objects, see [Framework File Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-file-objects).

#### Examples

The following code example obtains a pointer to a named WDM device object and its corresponding WDM file object, if the requested access to the objects can be granted. Then, the example obtains a handle to the framework file object that is associated with the WDM file object.

```cpp
PFILE_OBJECT  pWdmFileObject = NULL;
PDEVICE_OBJECT  pWdmDeviceObject = NULL;
WDFFILEOBJECT  fileObject = NULL;
NTSTATUS  status = STATUS_SUCCESS;
BOOLEAN  success = TRUE;

status = IoGetDeviceObjectPointer(
                                  &inputFileName,    // File name
                                  FILE_ALL_ACCESS,   // Access mask
                                  &pWdmFileObject,   // Output pointer of WDM file object
                                  &pWdmDeviceObject  // Output pointer of WDM device object
                                  );

if(!NT_SUCCESS(status)){
    success = FALSE;
    break;
}

fileObject = WdfDeviceGetFileObject(
                                    gDeviceObject,  // Handle to device object
                                    pWdmFileObject  // Handle to WDM file object
                                    );
if(fileObject == NULL){
    success = FALSE;
}
```

## See also

[IoGetDeviceObjectPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdeviceobjectpointer)