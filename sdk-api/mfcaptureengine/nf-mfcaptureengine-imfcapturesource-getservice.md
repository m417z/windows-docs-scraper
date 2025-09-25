# IMFCaptureSource::GetService

## Description

Gets a pointer to the underlying [Source Reader](https://learn.microsoft.com/windows/desktop/medfound/source-reader) object.

## Parameters

### `rguidService` [in]

A service identifier GUID. Currently the value must be **IID_IMFSourceReader** or **GUID_NULL**.

### `riid` [in]

The interface identifier (IID) of the interface being requested. The value must be **IID_IMFSourceReader**. If the value is not set to **IID_IMFSourceReader**, the call will fail and return **E_INVALIDARG**.

### `ppUnknown` [out]

Receives a pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface. The caller must release the interface.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | Invalid argument. |
| **MF_E_INVALIDREQUEST** | The capture source was not initialized. Possibly there is no capture device on the system. |

## See also

[IMFCaptureSource](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nn-mfcaptureengine-imfcapturesource)