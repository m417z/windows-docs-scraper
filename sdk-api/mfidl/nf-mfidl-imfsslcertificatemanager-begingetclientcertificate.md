# IMFSSLCertificateManager::BeginGetClientCertificate

## Description

Starts an asynchronous call to get the client SSL certificate.

## Parameters

### `pszURL` [in]

A null-terminated string that contains the URL for which a client-side SSL certificate is required. Media Foundation can resolve the scheme and send the request to the server.

### `pCallback` [in]

A pointer to the [IMFAsyncCallback](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasynccallback) interface of a callback object. The caller must implement this interface.

### `pState` [in]

A pointer to the **IUnknown** interface of a state object, defined by the caller. This parameter can be **NULL**. You can use this object to hold state information. The object is returned to the caller when the callback is invoked.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When the operation completes, the callback object's [IMFAsyncCallback::Invoke](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-invoke) method is called. At that point, the application should call [IMFSSLCertificateManager::EndGetClientCertificate](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfsslcertificatemanager-endgetclientcertificate) to complete the asynchronous request.

## See also

[Calling Asynchronous Methods](https://learn.microsoft.com/windows/desktop/medfound/calling-asynchronous-methods)

[IMFSSLCertificateManager](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsslcertificatemanager)