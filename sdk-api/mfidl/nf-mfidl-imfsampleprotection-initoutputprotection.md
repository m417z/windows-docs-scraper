# IMFSampleProtection::InitOutputProtection

## Description

Retrieves initialization information for sample protection from the upstream component.

## Parameters

### `dwVersion` [in]

Specifies the version number of the sample protection scheme. The version number is specified as a [SAMPLE_PROTECTION_VERSION](https://learn.microsoft.com/windows/desktop/api/mfidl/ne-mfidl-sample_protection_version) enumeration value.

### `dwOutputId` [in]

Identifier of the output stream. The identifier corresponds to the output stream identifier returned by the [IMFTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imftransform) interface.

### `pbCert` [in]

Pointer to a certificate provided by the downstream component.

### `cbCert` [in]

Size of the certificate, in bytes.

### `ppbSeed` [out]

Receives a pointer to a buffer that contains the initialization information for downstream component. The caller must free the memory for the buffer by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

### `pcbSeed` [out]

Receives the size of the *ppbSeed* buffer, in bytes.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOTIMPL** | Not implemented. |

## Remarks

This method must be implemented by the upstream component. The method fails if the component does not support the requested sample protection version. Downstream components do not implement this method and should return E_NOTIMPL.

## See also

[IMFSampleProtection](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsampleprotection)