# IMMEndpoint::GetDataFlow

## Description

The **GetDataFlow** method indicates whether the audio endpoint device is a rendering device or a capture device.

## Parameters

### `pDataFlow` [out]

Pointer to a variable into which the method writes the data-flow direction of the endpoint device. The direction is indicated by one of the following [EDataFlow](https://learn.microsoft.com/windows/win32/api/mmdeviceapi/ne-mmdeviceapi-edataflow) enumeration constants:

* eRender
* eCapture

The data-flow direction for a rendering device is eRender. The data-flow direction for a capture device is eCapture.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Parameter *ppDataFlow* is **NULL**. |

## See also

[IMMEndpoint Interface](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-immendpoint)