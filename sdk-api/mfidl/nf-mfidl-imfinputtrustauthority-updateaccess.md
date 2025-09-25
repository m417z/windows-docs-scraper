# IMFInputTrustAuthority::UpdateAccess

## Description

Notifies the input trust authority (ITA) when the number of output trust authorities (OTAs) that will perform a specified action has changed.

## Parameters

### `pParam` [in]

Pointer to an [MFINPUTTRUSTAUTHORITY_ACCESS_PARAMS](https://learn.microsoft.com/windows/desktop/api/mfidl/ns-mfidl-mfinputtrustauthority_access_params) structure that contains parameters for the **UpdateAccess** action.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The ITA can update its internal state if needed. If the method returns a failure code, the Media Session cancels the action.

## See also

[IMFInputTrustAuthority](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfinputtrustauthority)