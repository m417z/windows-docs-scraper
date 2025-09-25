## Description

Sends a control code directly to a specified device driver, causing the corresponding device to perform the corresponding operation.

See the [Assign drive letter sample](https://github.com/microsoft/Windows-classic-samples/tree/master/Samples/Win7Samples/winbase/io/dledit).

## Parameters

### `hDevice` [in]

A handle to the device on which the operation is to be performed. The device is typically a volume,
directory, file, or stream. To retrieve a device handle, use the
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function. For more information, see
Remarks.

### `dwIoControlCode` [in]

The control code for the operation. This value identifies the specific operation to be performed and the
type of device on which to perform it.

For a list of the control codes, see Remarks. The documentation for each control code provides usage details
for the *lpInBuffer*, *nInBufferSize*,
*lpOutBuffer*, and *nOutBufferSize* parameters.

### `lpInBuffer` [in, optional]

A pointer to the input buffer that contains the data required to perform the operation. The format of this
data depends on the value of the *dwIoControlCode* parameter.

This parameter can be **NULL** if *dwIoControlCode* specifies
an operation that does not require input data.

### `nInBufferSize` [in]

The size of the input buffer, in bytes.

### `lpOutBuffer` [out, optional]

A pointer to the output buffer that is to receive the data returned by the operation. The format of this
data depends on the value of the *dwIoControlCode* parameter.

This parameter can be **NULL** if *dwIoControlCode* specifies
an operation that does not return data.

### `nOutBufferSize` [in]

The size of the output buffer, in bytes.

### `lpBytesReturned` [out, optional]

A pointer to a variable that receives the size of the data stored in the output buffer, in bytes.

If the output buffer is too small to receive any data, the call fails,
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns
**ERROR_INSUFFICIENT_BUFFER**, and *lpBytesReturned* is zero.

If the output buffer is too small to hold all of the data but can hold some entries, some drivers will return
as much data as fits. In this case, the call fails,
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns
**ERROR_MORE_DATA**, and *lpBytesReturned* indicates the amount
of data received. Your application should call
**DeviceIoControl** again with the same operation,
specifying a new starting point.

If *lpOverlapped* is **NULL**,
*lpBytesReturned* cannot be **NULL**. Even when an operation
returns no output data and *lpOutBuffer* is **NULL**,
**DeviceIoControl** makes use of
*lpBytesReturned*. After such an operation, the value of
*lpBytesReturned* is meaningless.

If *lpOverlapped* is not **NULL**,
*lpBytesReturned* can be **NULL**. If this parameter is not
**NULL** and the operation returns data, *lpBytesReturned* is
meaningless until the overlapped operation has completed. To retrieve the number of bytes returned, call
[GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult). If
*hDevice* is associated with an I/O completion port, you can retrieve the number of
bytes returned by calling
[GetQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus).

### `lpOverlapped` [in, out, optional]

A pointer to an [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure.

If *hDevice* was opened without specifying
**FILE_FLAG_OVERLAPPED**, *lpOverlapped* is ignored.

If *hDevice* was opened with the **FILE_FLAG_OVERLAPPED** flag,
the operation is performed as an overlapped (asynchronous) operation. In this case,
*lpOverlapped* must point to a valid
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure that contains a handle to an
event object. Otherwise, the function fails in unpredictable ways.

For overlapped operations,
**DeviceIoControl** returns immediately, and the event
object is signaled when the operation has been completed. Otherwise, the function does not return until the
operation has been completed or an error occurs.

## Return value

If the operation completes successfully, the return value is nonzero (TRUE).

If the operation fails or is pending, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To retrieve a handle to the device, you must call the
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function with either the name of a device or
the name of the driver associated with a device. To specify a device name, use the following format:

\\\\.\*DeviceName*

**DeviceIoControl** can accept a handle to a specific
device. For example, to open a handle to the logical drive A: with
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea), specify \\\\.\a:. Alternatively, you can use the
names \\\\.\PhysicalDrive0, \\\\.\PhysicalDrive1, and so on, to open handles to the physical drives on a system.

You should specify the **FILE_SHARE_READ** and
**FILE_SHARE_WRITE** access flags when calling
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) to open a handle to a device driver. However,
when you open a communications resource, such as a serial port, you must specify exclusive access. Use the other
**CreateFile** parameters as follows when opening a device
handle:

* The *fdwCreate* parameter must specify
  **OPEN_EXISTING**.
* The *hTemplateFile* parameter must be **NULL**.
* The *fdwAttrsAndFlags* parameter can specify
  **FILE_FLAG_OVERLAPPED** to indicate that the returned handle can be used in overlapped
  (asynchronous) I/O operations.

For lists of supported control codes, see the following topics:

* [CD-ROM Control Codes](https://learn.microsoft.com/windows-hardware/drivers/storage/cd-rom-io-control-codes)
* [Communications Control Codes](https://learn.microsoft.com/windows/desktop/DevIO/communications-control-codes)
* [Device Management Control Codes](https://learn.microsoft.com/windows/desktop/DevIO/device-management-control-codes)
* [Directory Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/directory-management-control-codes)
* [Disk Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-control-codes)
* [File Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/file-management-control-codes)
* [Power Management Control Codes](https://learn.microsoft.com/windows/desktop/Power/power-management-control-codes)
* [Volume Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-control-codes)

#### Examples

For an example that uses **DeviceIoControl**, see [Calling DeviceIoControl](https://learn.microsoft.com/windows/desktop/DevIO/calling-deviceiocontrol).

## See also

[CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa)

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[Device Input and Output Control (IOCTL)](https://learn.microsoft.com/windows/desktop/DevIO/device-input-and-output-control-ioctl-)

[GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult)

[GetQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus)

[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)

[Assign drive letter sample](https://github.com/microsoft/Windows-classic-samples/tree/master/Samples/Win7Samples/winbase/io/dledit)