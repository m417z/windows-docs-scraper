# IDirect3DAuthenticatedChannel9::GetCertificateSize

## Description

Gets the size of the driver's certificate chain.

## Parameters

### `pCertificateSize`

Receives the size of the certificate chain, in bytes.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To get the certificate chain, call [IDirect3DAuthenticatedChannel9::GetCertificate](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dauthenticatedchannel9-getcertificate).

This method fails if the channel type is **D3DAUTHENTICATEDCHANNEL_D3D9**, because the Direct3D 9 channel does not support authentication.

## See also

[GPU-Based Content Protection](https://learn.microsoft.com/windows/desktop/medfound/gpu-based-content-protection)

[IDirect3DAuthenticatedChannel9](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3dauthenticatedchannel9)