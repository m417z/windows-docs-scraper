# IMFSSLCertificateManager::GetCertificatePolicy

## Description

Indicates whether the server SSL certificate must be verified by the caller, Media Foundation, or the **IMFSSLCertificateManager** implementation class.

## Parameters

### `pszURL` [in]

 Pointer to a string that contains the URL that is sent to the server.

### `pfOverrideAutomaticCheck` [out]

Pointer to a **BOOL** value. Set to **TRUE** if [IMFSSLCertificateManager::OnServerCertificate](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfsslcertificatemanager-onservercertificate) is used to verify the server certificate.
Set to **FALSE** if Media Foundation verifies the server certificate by using the certificates in the Windows certificate store.

### `pfClientCertificateAvailable` [out]

Pointer to a **BOOL** value. Set to **TRUE** if the SSL certificate for the client is available for immediate retrieval. Media Foundation calls [IMFSSLCertificateManager::GetClientCertificate](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfsslcertificatemanager-begingetclientcertificate) to obtain the client certificate synchronously. If the value is set to **FALSE**, Media Foundation obtains the client SSL certificate with an asynchronous call to [IMFSSLCertificateManager::BeginGetClientCertificate](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfsslcertificatemanager-begingetclientcertificate).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFSSLCertificateManager](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsslcertificatemanager)