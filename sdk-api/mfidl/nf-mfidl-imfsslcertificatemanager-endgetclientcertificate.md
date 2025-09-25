# IMFSSLCertificateManager::EndGetClientCertificate

## Description

Completes an asynchronous request to get the client SSL certificate.

## Parameters

### `pResult` [in]

A pointer to the [IMFAsyncResult](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasyncresult) interface. Pass in the same pointer that your callback object received in the [IMFAsyncCallback::Invoke](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-invoke) method.

### `ppbData` [out]

Receives a pointer to the buffer that stores the certificate.
The caller must free the buffer by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

### `pcbData` [out]

Receives the size of the *ppbData* buffer, in bytes.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Call this method after the [IMFSSLCertificateManager::BeginGetClientCertificate](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfsslcertificatemanager-begingetclientcertificate) method completes asynchronously.

## See also

[Calling Asynchronous Methods](https://learn.microsoft.com/windows/desktop/medfound/calling-asynchronous-methods)

[IMFSSLCertificateManager](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsslcertificatemanager)