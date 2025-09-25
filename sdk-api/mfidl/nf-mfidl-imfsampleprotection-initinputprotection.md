# IMFSampleProtection::InitInputProtection

## Description

Initializes sample protection on the downstream component.

## Parameters

### `dwVersion` [in]

Specifies the version number of the sample protection scheme. The version number is specified as a [SAMPLE_PROTECTION_VERSION](https://learn.microsoft.com/windows/desktop/api/mfidl/ne-mfidl-sample_protection_version) enumeration value.

### `dwInputId` [in]

Identifier of the input stream. The identifier corresponds to the output stream identifier returned by the [IMFTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imftransform) interface.

### `pbSeed` [in]

Pointer to a buffer that contains the initialization data provided by the upstream component. To retrieve this buffer, call [IMFSampleProtection::InitOutputProtection](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfsampleprotection-initoutputprotection).

### `cbSeed` [in]

Size of the *pbSeed* buffer, in bytes.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMFSampleProtection](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsampleprotection)