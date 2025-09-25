# SetupComm function

## Description

Initializes the communications parameters for a specified communications device.

## Parameters

### `hFile` [in]

A handle to the communications device. The
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function returns this handle.

### `dwInQueue` [in]

The recommended size of the device's internal input buffer, in bytes.

### `dwOutQueue` [in]

The recommended size of the device's internal output buffer, in bytes.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

After a process uses the
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function to open a handle to a communications device, but before doing any I/O with the device, it can call
**SetupComm** to set the communications parameters for the device. If it does not set them, the device uses the default parameters when the first call to another communications function occurs.

The *dwInQueue* and *dwOutQueue* parameters specify the recommended sizes for the internal buffers used by the driver for the specified device. For example, YMODEM protocol packets are slightly larger than 1024 bytes. Therefore, a recommended buffer size might be 1200 bytes for YMODEM communications. For Ethernet-based communications, a recommended buffer size might be 1600 bytes, which is slightly larger than a single Ethernet frame.

The device driver receives the recommended buffer sizes, but is free to use any input and output (I/O) buffering scheme, as long as it provides reasonable performance and data is not lost due to overrun (except under extreme circumstances). For example, the function can succeed even though the driver does not allocate a buffer, as long as some other portion of the system provides equivalent functionality.

## See also

[Communications Functions](https://learn.microsoft.com/windows/desktop/DevIO/communications-functions)

[Communications Resources](https://learn.microsoft.com/windows/desktop/DevIO/communications-resources)

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[SetCommState](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setcommstate)