# IOCTL\_BATTERY\_QUERY\_STATUS control code

Retrieves the current status of the battery.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```C++
BOOL DeviceIoControl(
  (HANDLE) hDevice,           // handle to battery
  IOCTL_BATTERY_QUERY_STATUS, // dwIoControlCode
  (LPVOID) lpInBuffer,        // input buffer
  (DWORD) nInBufferSize,      // size of input buffer
  (LPVOID) lpOutBuffer,       // output buffer
  (DWORD) nOutBufferSize,     // size of output buffer
  (LPDWORD) lpBytesReturned,  // number of bytes returned
  (LPOVERLAPPED) lpOverlapped // OVERLAPPED structure
);
```

## Parameters

*hDevice*

A handle to the battery from which information is to be returned. To retrieve a device handle, call the [**CreateFile**](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function.

*dwIoControlCode*

The control code for the operation. This value identifies the specific operation to be performed and the type of device on which to perform it. Use **IOCTL\_BATTERY\_QUERY\_STATUS** for this operation.

*lpInBuffer*

A pointer to a [**BATTERY\_WAIT\_STATUS**](https://learn.microsoft.com/windows/win32/power/battery-wait-status-str) structure.

*nInBufferSize*

The size of the input buffer, in bytes.

*lpOutBuffer*

A pointer to a [**BATTERY\_STATUS**](https://learn.microsoft.com/windows/win32/power/battery-status-str) structure.

*nOutBufferSize*

The size of the output buffer, in bytes.

*lpBytesReturned*

A pointer to a variable that receives the size of the data returned in the *lpOutBuffer* buffer, in bytes.

If the output buffer is too small to return any data then the call fails, [**GetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns the error code **ERROR\_INSUFFICIENT\_BUFFER**, and the returned byte count is zero.

If *lpOverlapped* is **NULL** (nonoverlapped I/O), *lpBytesReturned* cannot be **NULL**.

If *lpOverlapped* is not **NULL** (overlapped I/O), *lpBytesReturned* can be **NULL**. If this is an overlapped operation, you can retrieve the number of bytes returned by calling the [**GetOverlappedResult**](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult) function. If *hDevice* is associated with an I/O completion port, you can get the number of bytes returned by calling the [**GetQueuedCompletionStatus**](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus) function.

*lpOverlapped*

A pointer to an [**OVERLAPPED**](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure.

If *hDevice* was opened with the **FILE\_FLAG\_OVERLAPPED** flag, *lpOverlapped* must point to a valid [**OVERLAPPED**](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure. In this case, [**DeviceIoControl**](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) is performed as an overlapped (asynchronous) operation. If the device was opened with the **FILE\_FLAG\_OVERLAPPED** flag and *lpOverlapped* is **NULL**, the function fails in unpredictable ways.

If *hDevice* was opened without specifying the **FILE\_FLAG\_OVERLAPPED** flag, *lpOverlapped* is ignored and the [**DeviceIoControl**](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) function does not return until the operation has been completed, or until an error occurs.

## Return value

If the operation completes successfully, [**DeviceIoControl**](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) returns a nonzero value.

If the operation fails or is pending, [**DeviceIoControl**](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) returns zero. To get extended error information, call [**GetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

All requests for battery information will complete with the status of ERROR_NO_SUCH_DEVICE (or ERROR_FILE_NOT_FOUND in **Windows 10 version 1809 and earlier**) whenever the BatteryTag element of the request does not match that of the current battery tag. This ensures that the returned battery information matches that of the requested battery (see [Battery Tags](https://learn.microsoft.com/windows/win32/power/battery-information) for more information).

## Remarks

This battery IOCTL retrieves the status of the battery at the time the operation returns. The input parameter structure, [**BATTERY\_WAIT\_STATUS**](https://learn.microsoft.com/windows/win32/power/battery-wait-status-str), indicates when the battery status is to be processed and returned.

Requests for battery status can be for immediate return or can be set to wait for a particular condition before completing. For example, a request for battery information can be made that waits until the battery capacity reaches a specified point or the battery state changes.

All requests for battery information will complete with the status of **ERROR\_FILE\_NOT\_FOUND** whenever the **BatteryTag** element of the request does not match that of the current battery tag. (See [Battery Tags](https://learn.microsoft.com/windows/win32/power/battery-information) for more information.) This is used to ensure that the returned battery information matches that of the requested battery.

For the implications of overlapped I/O on this operation, see the Remarks section of the [**DeviceIoControl**](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) topic.

## Examples

For an example, see [Enumerating Battery Devices](https://learn.microsoft.com/windows/win32/power/enumerating-battery-devices).

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| Header<br> | Poclass.h;

BatClass.h on Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP | ## See also [Battery Information](https://learn.microsoft.com/windows/win32/power/battery-information) [Power Management Control Codes](https://learn.microsoft.com/windows/win32/power/power-management-control-codes) [**DeviceIoControl**](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) [**BATTERY\_STATUS**](https://learn.microsoft.com/windows/win32/power/battery-status-str) [**BATTERY\_WAIT\_STATUS**](https://learn.microsoft.com/windows/win32/power/battery-wait-status-str) [**IOCTL\_BATTERY\_QUERY\_INFORMATION**](https://learn.microsoft.com/windows/win32/power/ioctl-battery-query-information) [**IOCTL\_BATTERY\_QUERY\_TAG**](https://learn.microsoft.com/windows/win32/power/ioctl-battery-query-tag) [**IOCTL\_BATTERY\_SET\_INFORMATION**](https://learn.microsoft.com/windows/win32/power/ioctl-battery-set-information)