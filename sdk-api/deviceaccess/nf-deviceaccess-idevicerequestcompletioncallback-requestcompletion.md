# IDeviceRequestCompletionCallback::RequestCompletion

## Description

Implement the **RequestCompletion** method to handle the completion of calls to the [DeviceIoControlAsync](https://learn.microsoft.com/previous-versions/windows/desktop/api/deviceaccess/nf-deviceaccess-ideviceiocontrol-deviceiocontrolasync) method.

## Parameters

### `requestResult` [in]

The result code that's returned for the I/O operation.

### `bytesReturned` [in]

The number of bytes that were transferred as a result of the I/O operation.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDeviceRequestCompletionCallback](https://learn.microsoft.com/previous-versions/windows/desktop/api/deviceaccess/nn-deviceaccess-idevicerequestcompletioncallback)