# IDeviceIoControl::DeviceIoControlAsync

## Description

The **DeviceIoControlAsync** method sends an asynchronous device input/output (I/O) control request to the device interface that the call to the [CreateDeviceAccessInstance](https://learn.microsoft.com/previous-versions/windows/desktop/api/deviceaccess/nf-deviceaccess-createdeviceaccessinstance) function specified.

## Parameters

### `ioControlCode` [in]

The I/O control code for the operation.

### `inputBuffer` [in]

An optional input buffer for the operation.

### `inputBufferSize` [in]

The size of input buffer, in bytes.

### `outputBuffer` [out]

An operational output buffer for the operation.

### `outputBufferSize` [in]

The size of output buffer, in bytes.

### `requestCompletionCallback` [in]

The callback interface on which the [RequestCompletion](https://learn.microsoft.com/previous-versions/windows/desktop/api/deviceaccess/nf-deviceaccess-idevicerequestcompletioncallback-requestcompletion) method is called if the operation is submitted successfully.

### `cancelContext` [out]

An optional pointer that receives a cancel context that can be passed to the [CancelOperation](https://learn.microsoft.com/previous-versions/windows/desktop/api/deviceaccess/nf-deviceaccess-ideviceiocontrol-canceloperation) method to cancel an outstanding request.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the request is submitted successfully (that is, calling this function doesn't immediately return an error), the result of the operation is available in the [RequestCompletion](https://learn.microsoft.com/previous-versions/windows/desktop/api/deviceaccess/nf-deviceaccess-idevicerequestcompletioncallback-requestcompletion) callback of the supplied [IDeviceRequestCompletionCallback](https://learn.microsoft.com/previous-versions/windows/desktop/api/deviceaccess/nn-deviceaccess-idevicerequestcompletioncallback) interface.

An operation that the system (operating system or device driver) fails immediately doesn't result in a callback.This means that the caller receives a callback only if this function returns **S_OK**.

## See also

[IDeviceIoControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/deviceaccess/nn-deviceaccess-ideviceiocontrol)