# IMFSampleProtection::GetInputProtectionVersion

## Description

Retrieves the version of sample protection that the component implements on input.

## Parameters

### `pdwVersion` [out]

Receives a member of the [SAMPLE_PROTECTION_VERSION](https://learn.microsoft.com/windows/desktop/api/mfidl/ne-mfidl-sample_protection_version) enumeration.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMFSampleProtection](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsampleprotection)