# ID3D11CryptoSession::GetCertificate

## Description

Gets the driver's certificate chain.

## Parameters

### `CertificateSize` [in]

The size of the *pCertificate* array, in bytes. To get the size of the certificate chain, call [ID3D11CryptoSession::GetCertificateSize](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11cryptosession-getcertificatesize).

### `pCertificate` [out]

A pointer to a byte array that receives the driver's certificate chain. The caller must allocate the array.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ID3D11CryptoSession](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11cryptosession)