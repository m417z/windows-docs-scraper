# IMFSSLCertificateManager::GetClientCertificate

## Description

Gets the client SSL certificate synchronously.

## Parameters

### `pszURL` [in]

Pointer to a string that contains the URL for which a client-side SSL certificate is required. Media Foundation can resolve the scheme and send the request to the server.

### `ppbData` [out]

Pointer to the buffer that stores the certificate.
This caller must free the buffer by calling **CoTaskMemFree**.

### `pcbData` [out]

Pointer to a **DWORD** variable that receives the number of bytes required to hold the certificate data in the buffer pointed by **ppbData*.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFSSLCertificateManager](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsslcertificatemanager)