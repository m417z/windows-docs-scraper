# IDirect3DCryptoSession9::GetCertificateSize

## Description

Gets the size of the driver's certificate chain.

## Parameters

### `pCertificateSize`

Receives the size of the certificate chain, in bytes.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To get the certificate, call [IDirect3DCryptoSession9::GetCertificate](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dcryptosession9-getcertificate).

## See also

[GPU-Based Content Protection](https://learn.microsoft.com/windows/desktop/medfound/gpu-based-content-protection)

[IDirect3DCryptoSession9](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3dcryptosession9)