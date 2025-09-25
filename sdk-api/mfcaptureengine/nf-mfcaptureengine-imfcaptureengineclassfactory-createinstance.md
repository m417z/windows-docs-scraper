# IMFCaptureEngineClassFactory::CreateInstance

## Description

Creates an instance of the capture engine.

## Parameters

### `clsid` [in]

The CLSID of the object to create.

Currently, this parameter must equal **CLSID_MFCaptureEngine**.

### `riid` [in]

The IID of the requested interface. The capture engine supports the [IMFCaptureEngine](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nn-mfcaptureengine-imfcaptureengine) interface.

### `ppvObject` [out]

Receives a pointer to the requested interface. The caller must release the interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Before calling this method, call the [MFStartup](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfstartup) function.

## See also

[IMFCaptureEngineClassFactory](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nn-mfcaptureengine-imfcaptureengineclassfactory)