# IMFOutputPolicy::GetMinimumGRLVersion

## Description

Retrieves the minimum version of the global revocation list (GRL) that must be enforced by the protected environment for this policy.

## Parameters

### `pdwMinimumGRLVersion` [out]

Receives the minimum GRL version.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMFOutputPolicy](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfoutputpolicy)