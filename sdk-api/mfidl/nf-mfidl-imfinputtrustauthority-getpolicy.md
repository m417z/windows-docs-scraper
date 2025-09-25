# IMFInputTrustAuthority::GetPolicy

## Description

Retrieves the policy that defines which output protection systems are allowed for this stream, and the configuration data for each protection system.

## Parameters

### `Action` [in]

The action that will be performed on this stream, specified as a member of the [MFPOLICYMANAGER_ACTION](https://learn.microsoft.com/windows/desktop/api/mfidl/ne-mfidl-mfpolicymanager_action) enumeration.

### `ppPolicy` [out]

Receives a pointer to the [IMFOutputPolicy](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfoutputpolicy) interface. The caller must release the interface.

## Return value

The method returns an HRESULT. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMFInputTrustAuthority](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfinputtrustauthority)