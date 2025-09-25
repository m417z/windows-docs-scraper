# IMFSSLCertificateManager::OnServerCertificate

## Description

Called by Media Foundation when the server SSL certificate has been received; indicates whether the server certificate is accepted.

## Parameters

### `pszURL` [in]

Pointer to a string that contains the URL used to send the request to the server, and for which a server-side SSL certificate has been received.

### `pbData` [in]

Pointer to a buffer that contains the server SSL certificate.

### `cbData` [in]

Pointer to a **DWORD** variable that indicates the size of *pbData* in bytes.

### `pfIsGood` [out]

Pointer to a **BOOL** variable that indicates whether the certificate is accepted.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFSSLCertificateManager](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsslcertificatemanager)