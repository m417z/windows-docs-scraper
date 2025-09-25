# IMFSecureChannel::GetCertificate

## Description

Retrieves the client's certificate.

## Parameters

### `ppCert` [out]

Receives a pointer to a buffer allocated by the object. The buffer contains the client's certificate. The caller must release the buffer by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

### `pcbCert` [out]

Receives the size of the *ppCert* buffer, in bytes.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMFSecureChannel](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsecurechannel)