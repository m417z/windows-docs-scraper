# IoGetDriverDirectory function

## Description

Returns a handle to a directory on disk from which the driver can read and write files. The files in that directory apply to a specific driver object.

## Parameters

### `DriverObject` [_In_]

A pointer to the driver object ([**DRIVER_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object) structure) of the calling driver.

### `DirectoryType` [_In_]

A [**_DRIVER_DIRECTORY_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_driver_directory_type)-type value that indicates the type of requested directory.

### `Flags` [_In_]

Must be 0.

### `DriverDirectoryHandle` [_Out_]

A pointer to a variable that receives a HANDLE to the requested driver directory. The caller must not pass NULL.

## Return value

Returns an appropriate [NTSTATUS value](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values). Possible values include:

| Error code | Description |
| ------------------------ | -------------------------------------------------------------------------------------------------- |
| STATUS_SUCCESS | The call successfully opened a handle to the requested driver directory. |
| STATUS_INVALID_PARAMETER | An input value to this function is invalid. For example, _DriverObject_ or _DriverDirectoryHandle_ is NULL; _Flags_ is not 0. |

## Remarks

If **IoGetDriverDirectory** is called before the required disks and volumes have been started, the function does not open a handle and returns an error.

Drivers typically use [**ZwOpenFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwopenfile) and [**ZwCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatefile) to access/create files. One of the parameters for those functions is an [**OBJECT_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block) structure, which contains the object name and a root directory. If the root directory is NULL, then the object name must be a fully qualified path. However, if you provide a handle for the root directory, then the object name must be relative to the object (in the case of files, the directory), that the handle represents.

After the **IoGetDriverDirectory** call succeeds, use the received HANDLE as a root directory in the [**OBJECT_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block) that you are passing to a [**ZwOpenFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwopenfile) and [**ZwCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatefile).

The driver must call [**ZwClose**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwclose) to close the received handle when access is no longer required.

Callers of **IoGetDriverDirectory** must be running at IRQL = PASSIVE_LEVEL in the context of a system thread.

## See also

[**DRIVER_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object)

[**_DRIVER_DIRECTORY_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_driver_directory_type)

[**ZwOpenFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwopenfile)

[**ZwCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatefile)

[**ZwClose**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwclose)

[**OBJECT_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block)

[**InitializeObjectAttributes**](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes)