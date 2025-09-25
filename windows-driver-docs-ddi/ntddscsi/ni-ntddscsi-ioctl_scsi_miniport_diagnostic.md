# IOCTL_SCSI_MINIPORT_DIAGNOSTIC IOCTL

## Description

The **IOCTL_SCSI_MINIPORT_DIAGNOSTIC**
control code is use to perform a diagnostic request to the Miniport.

## Parameters

### Major code

### Input buffer

### Input buffer length

### Output buffer

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

Irp->IoStatus.Status is set to STATUS_SUCCESS if the request is successful.

Otherwise, Status to the appropriate error condition as a NTSTATUS code.

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

To perform this operation, call the [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
function with the following parameters.

```
BOOL
   WINAPI
   DeviceIoControl( (HANDLE)       hDevice,         // handle to device
                    (DWORD)        IOCTL_SCSI_MINIPORT_DIAGNOSTIC, // dwIoControlCode
                    (LPDWORD)      lpInBuffer,      // input buffer
                    (DWORD)        nInBufferSize,   // size of input buffer
                    (LPDWORD)      lpOutBuffer,     // output buffer
                    (DWORD)        nOutBufferSize,  // size of output buffer
                    (LPDWORD)      lpBytesReturned, // number of bytes returned
                    (LPOVERLAPPED) lpOverlapped );  // OVERLAPPED structure
```

Parameters

## See also

[DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)

[STORAGE_DIAGNOSTIC_MP_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_storage_diagnostic_mp_request)