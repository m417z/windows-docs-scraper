# IoIncrementKeepAliveCount function

## Description

The **IoIncrementKeepAliveCount** routine increments a reference count associated with a Windows app process on a specific device. This routine is called by a kernel mode driver in response to the app opening a process for I/O. This prevents Windows from suspending the app before the I/O process is complete.

## Parameters

### `FileObject` [in, out]

The file object handle to the device.

### `Process` [in, out]

The process associated with the device.

## Return value

This routine returns **STATUS_SUCCESS** on success, or the appropriate **NTSTATUS** error code on failure. **NTSTATUS** error codes are defined in Ntstatus.h.

## See also

[IoDecrementKeepAliveCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iodecrementkeepalivecount)