# IMFSampleProtection::GetProtectionCertificate

## Description

Retrieves the sample protection certificate.

## Parameters

### `dwVersion` [in]

Specifies the version number of the sample protection scheme for which to receive a certificate. The version number is specified as a [SAMPLE_PROTECTION_VERSION](https://learn.microsoft.com/windows/desktop/api/mfidl/ne-mfidl-sample_protection_version) enumeration value.

### `ppCert` [out]

Receives a pointer to a buffer containing the certificate. The caller must free the memory for the buffer by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

### `pcbCert` [out]

Receives the size of the *ppCert* buffer, in bytes.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOTIMPL** | Not implemented. |

## Remarks

For certain version numbers of sample protection, the downstream component must provide a certificate. Components that do not support these version numbers can return E_NOTIMPL.

## See also

[IMFSampleProtection](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsampleprotection)