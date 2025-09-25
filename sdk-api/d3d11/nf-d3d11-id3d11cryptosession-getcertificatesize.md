# ID3D11CryptoSession::GetCertificateSize

## Description

Gets the size of the driver's certificate chain.

## Parameters

### `pCertificateSize` [out]

Receives the size of the certificate chain, in bytes.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To get the certificate, call [ID3D11CryptoSession::GetCertificate](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11cryptosession-getcertificate).

## See also

[ID3D11CryptoSession](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11cryptosession)