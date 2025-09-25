# IoDecrementKeepAliveCount function

## Description

The **IoDecrementKeepAliveCount** routine decrements a reference count associated with a Windows app on a specific device. This routine is called by a kernel mode driver when the app's I/O process has completed. If the app's reference count drops to 0, Windows can suspend the app.

## Parameters

### `FileObject` [in, out]

The file object handle to the device.

### `Process` [in, out]

The process associated with the device.

## Return value

This routine returns **STATUS_SUCCESS** on success, or the appropriate **NTSTATUS** error code on failure. **NTSTATUS** error codes are defined in Ntstatus.h.