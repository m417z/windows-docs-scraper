# IESLicenseRenewalResultEvent::GetEntitlementTokenLength

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the length of the entitlement token in a protected-content license from a **LicenseRenewalResult** event.

## Parameters

### `pdwLength` [out, retval]

Receives the length of the entitlement token, in bytes.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IESLicenseRenewalResultEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ieslicenserenewalresultevent)