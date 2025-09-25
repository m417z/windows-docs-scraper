# IESLicenseRenewalResultEvent::GetEntitlementToken

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

 Gets the entitlement token in a protected-content license from a **LicenseRenewalResult** event. Clients can call the [GetEntitlementTokenLength](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-ieslicenserenewalresultevent-getentitlementtokenlength) method to get the number of bytes to read from this buffer.

## Parameters

### `pbData` [out, retval]

Pointer to a buffer that receives the entitlement token.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[GetEntitlementTokenLength](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-ieslicenserenewalresultevent-getentitlementtokenlength)

[IESLicenseRenewalResultEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ieslicenserenewalresultevent)