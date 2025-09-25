# IDirect3DAuthenticatedChannel9::GetCertificate

## Description

Gets the driver's certificate chain.

## Parameters

### `CertifacteSize`

The size of the *ppCertificate* array, in bytes. To get the size of the certificate chain, call [IDirect3DAuthenticatedChannel9::GetCertificateSize](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dauthenticatedchannel9-getcertificatesize).

### `ppCertificate`

A pointer to a byte array that receives the driver's X.509 certificate chain. The caller must allocate the array.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You can use the certificate chain to verify that the driver's certificate was signed by Microsoft and has not been revoked. The driver's certificate also contains the driver's public key. Use the public key to establish a session key, by calling the [IDirect3DAuthenticatedChannel9::NegotiateKeyExchange](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dauthenticatedchannel9-negotiatekeyexchange) method.

This method fails if the channel type is **D3DAUTHENTICATEDCHANNEL_D3D9**, because the Direct3D 9 channel does not support authentication.

## See also

[GPU-Based Content Protection](https://learn.microsoft.com/windows/desktop/medfound/gpu-based-content-protection)

[IDirect3DAuthenticatedChannel9](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3dauthenticatedchannel9)