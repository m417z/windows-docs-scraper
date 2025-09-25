# IOCTL_PWM_PIN_START IOCTL

## Description

Starts generation of Pulse Width Modulation (PWM) signal on a pin or channel. To check whether a pin is started, use [IOCTL_PWM_PIN_IS_STARTED](https://learn.microsoft.com/windows/desktop/api/pwm/ni-pwm-ioctl_pwm_pin_is_started).

## Parameters

### Input buffer

Not used with this operation; set to NULL.

### Input buffer length

Not used with this operation; set to zero.

### Output buffer

Not used with this operation; set to NULL.

### Output buffer length

Not used with this operation; set to zero.

### Input/output buffer

### Input/output buffer length

### Status block

If the operation completes successfully,
[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) returns a nonzero
value.

If the operation fails or is pending,
[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) returns zero. To get extended error
information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To perform this operation, call the [DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol)
function with the following parameters.

```
BOOL
   WINAPI
   DeviceIoControl( (HANDLE)       hDevice,         // handle to device
                    (DWORD)        IOCTL_PWM_PIN_START, // dwIoControlCode(LPDWORD)      NULL,      // input buffer
                    (DWORD)        0,   // size of input buffer
                    (LPDWORD)      NULL,      // output buffer
                    (DWORD)        0,  // size of output buffer
                    (LPDWORD)      lpBytesReturned, // number of bytes returned
                    (LPOVERLAPPED) lpOverlapped );  // OVERLAPPED structure
```

| Parameters | Description |
| --- | --- |
| *hDevice* [in] | A handle to the device. To obtain a device handle, call the [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function. |
| *dwIoControlCode* [in] | The control code for the operation. Use **IOCTL_PWM_PIN_START** for this operation. |
| *lpInBuffer* | Not used with this operation; set to NULL. |
| *nInBufferSize* [in] | Not used with this operation; set to zero |
| *lpOutBuffer* [out] | Not used with this operation; set to NULL. |
| *nOutBufferSize* [in] | Not used with this operation; set to zero. |
| *lpBytesReturned* [out] | **LPDWORD**<br><br>A pointer to a variable that receives the size of the data stored in the output buffer, in bytes.<br><br>If the output buffer is too small, the call fails, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_INSUFFICIENT_BUFFER**, and *lpBytesReturned* is zero.<br><br>If *lpOverlapped* is **NULL**, *lpBytesReturned* cannot be **NULL**. Even when an operation returns no output data and *lpOutBuffer* is **NULL**, [DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) makes use of *lpBytesReturned*. After such an operation, the value of *lpBytesReturned* is meaningless.<br><br>If *lpOverlapped* is not **NULL**, *lpBytesReturned* can be **NULL**. If this parameter is not **NULL** and the operation returns data, *lpBytesReturned* is meaningless until the overlapped operation has completed. To retrieve the number of bytes returned, call [GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult). If the *hDevice* parameter is associated with an I/O completion port, you can retrieve the number of bytes returned by calling [GetQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus). |
| *lpOverlapped* [in] | **LPOVERLAPPED**<br><br>A pointer to an [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure.<br><br>If *hDevice* was opened without specifying **FILE_FLAG_OVERLAPPED**, *lpOverlapped* is ignored.<br><br>If *hDevice* was opened with the **FILE_FLAG_OVERLAPPED** flag, the operation is performed as an overlapped (asynchronous) operation. In this case, *lpOverlapped* must point to a valid [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure that contains a handle to an event object. Otherwise, the function fails in unpredictable ways.<br><br>For overlapped operations, [DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) returns immediately, and the event object is signaled when the operation has been completed. Otherwise, the function does not return until the operation has been completed or an error occurs. |

Issuing this IOCTL on a pin or channel that is already started has no effect, but does succeed.

## See also

[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol)