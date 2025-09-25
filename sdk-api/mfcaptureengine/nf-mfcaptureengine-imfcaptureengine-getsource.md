# IMFCaptureEngine::GetSource

## Description

Gets a pointer to the capture source object. Use the capture source to configure the capture devices.

## Parameters

### `ppSource` [out]

Receives a pointer to the [IMFCaptureSource](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nn-mfcaptureengine-imfcapturesource) interface. The caller must release the interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFCaptureEngine](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nn-mfcaptureengine-imfcaptureengine)