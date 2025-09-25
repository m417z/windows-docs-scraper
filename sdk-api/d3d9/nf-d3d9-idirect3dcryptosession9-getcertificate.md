# IDirect3DCryptoSession9::GetCertificate

## Description

Gets the driver's certificate chain.

## Parameters

### `CertifacteSize`

The size of the *ppCertificate* array, in bytes. To get the size of the certificate chain, call [IDirect3DCryptoSession9::GetCertificateSize](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dcryptosession9-getcertificatesize).

### `ppCertificate`

A pointer to a byte array that receives the driver's certificate chain. The caller must allocate the array.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The standard key-exchange mechanism uses the driver's Output Protection Manager (OPM) certificate, which is an X.509 certificate. The type of key exchange is given in the capabilities information returned by the [IDirect3DDevice9Video::GetContentProtectionCaps](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9video-getcontentprotectioncaps) method. The key-exchange mechanism is specified by the **KeyExchangeType** member of the [D3DCONTENTPROTECTIONCAPS](https://learn.microsoft.com/windows/desktop/api/d3d9caps/ns-d3d9caps-d3dcontentprotectioncaps) structure. If the value is **D3DKEYEXCHANGE_RSAES_OAEP**, an X.509 certificate is used.

For other types of key exchange, the driver might use some other type of certificate, or might not provide a certificate.

## See also

[GPU-Based Content Protection](https://learn.microsoft.com/windows/desktop/medfound/gpu-based-content-protection)

[IDirect3DCryptoSession9](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3dcryptosession9)