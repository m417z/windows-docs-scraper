# IOCTL\_VIDEO\_SET\_DISPLAY\_BRIGHTNESS control code

Sets the current AC and DC backlight levels.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```C++
BOOL DeviceIoControl(
  (HANDLE) hDevice,            // handle to device
  IOCTL_VIDEO_SET_DISPLAY_BRIGHTNESS, // dwIoControlCode
  (LPVOID) lpInBuffer,         // input buffer
  (DWORD) nInBufferSize,       // size of the input buffer
  NULL,                        // lpOutBuffer
  0,                           // nOutBufferSize
  (LPDWORD) lpBytesReturned,   // number of bytes returned
  (LPOVERLAPPED) lpOverlapped  // OVERLAPPED structure
);
```

## Parameters

*hDevice*

A handle to the \\\\.\\LCD device. To retrieve a device handle, call the [**CreateFile**](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function.

*dwIoControlCode*

The control code for the operation. This value identifies the specific operation to be performed and the type of device on which to perform it. Use **IOCTL\_VIDEO\_SET\_DISPLAY\_BRIGHTNESS** for this operation.

*lpInBuffer*

A pointer to a [**DISPLAY\_BRIGHTNESS**](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa372686(v=vs.85)) structure.

*nInBufferSize*

The size of the buffer pointed to by *lpOutBuffer*, in bytes.

*lpOutBuffer*

Not used with this operation; set to **NULL**.

*nOutBufferSize*

Not used with this operation; set to zero.

*lpBytesReturned*

A pointer to a variable that receives the actual count of bytes returned by the function in the output buffer.

If *lpOverlapped* is **NULL** (nonoverlapped I/O), *lpBytesReturned* is used internally and cannot be **NULL**.

If *lpOverlapped* is not **NULL** (overlapped I/O), *lpBytesReturned* can be **NULL**.

*lpOverlapped*

A pointer to an [**OVERLAPPED**](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure.

If *hDevice* was opened with the FILE\_FLAG\_OVERLAPPED flag, *lpOverlapped* must point to a valid [**OVERLAPPED**](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure. In this case, the operation is performed as an overlapped (asynchronous) operation. If the device was opened with the FILE\_FLAG\_OVERLAPPED flag and *lpOverlapped* is **NULL**, the function fails in unpredictable ways.

If *hDevice* was opened without specifying the FILE\_FLAG\_OVERLAPPED flag, *lpOverlapped* is ignored and [**DeviceIoControl**](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) does not return until the operation has been completed, or until an error occurs.

## Return value

If the operation completes successfully, [**DeviceIoControl**](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) returns a nonzero value.

If the operation fails or is pending, [**DeviceIoControl**](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) returns zero. To get extended error information, call [**GetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The values specified in the **ucACBrightness** and **ucDCBrightness** members of the [**DISPLAY\_BRIGHTNESS**](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa372686(v=vs.85)) structure must have been previously returned by [**IOCTL\_VIDEO\_QUERY\_SUPPORTED\_BRIGHTNESS**](https://learn.microsoft.com/windows/win32/power/ioctl-video-query-supported-brightness). For example, if the supported values are 10, 20, 30, 40, 50, 60, 70, 80, 90, and 100, then using a value of 33 would be an error.

The header file used to build applications that include this functionality, Ntddvdeo.h, is included in the Microsoft Windows Driver Development Kit (DDK). For information on obtaining the DDK, see [https://www.microsoft.com/whdc/devtools/ddk/default.mspx](https://msdn.microsoft.com/windows/hardware/gg454513).

Alternatively, you can define this control code as follows:

``` syntax
#define IOCTL_VIDEO_SET_DISPLAY_BRIGHTNESS \
  CTL_CODE(FILE_DEVICE_VIDEO, 0x127, METHOD_BUFFERED, FILE_ANY_ACCESS)
```

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista, Windows XP with SP1 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| Header<br> | Ntddvdeo.h |

## See also

[Backlight Control Interface](https://learn.microsoft.com/windows/win32/power/backlight-control-interface)

[**DeviceIoControl**](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol)

[**DISPLAY\_BRIGHTNESS**](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa372686(v=vs.85))

[**IOCTL\_VIDEO\_QUERY\_DISPLAY\_BRIGHTNESS**](https://learn.microsoft.com/windows/win32/power/ioctl-video-query-display-brightness)

[**IOCTL\_VIDEO\_QUERY\_SUPPORTED\_BRIGHTNESS**](https://learn.microsoft.com/windows/win32/power/ioctl-video-query-supported-brightness)

