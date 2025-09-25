# IDeviceIoControl::DeviceIoControlSync

## Description

The **DeviceIoControlSync** method sends a synchronous device input/output (I/O) control request to the device interface that the call to the [CreateDeviceAccessInstance](https://learn.microsoft.com/previous-versions/windows/desktop/api/deviceaccess/nf-deviceaccess-createdeviceaccessinstance) function specified.

## Parameters

### `ioControlCode` [in]

The I/O control code for the operation.

### `inputBuffer` [in]

An optional input buffer for the operation.

### `inputBufferSize` [in]

The size of input buffer, in bytes.

### `outputBuffer` [out]

An optional output buffer for the operation.

### `outputBufferSize` [in]

The size of output buffer, in bytes.

### `bytesReturned` [out]

A pointer to a variable that receives the number of bytes that were written into the output buffer, if one was specified.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Because this is a synchronous method, you must not use it on a thread that can't handle being blocked for an extended period. In this case, you use the **DeviceIoControlAsync** method.

## See also

[IDeviceIoControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/deviceaccess/nn-deviceaccess-ideviceiocontrol)