# IESLicenseRenewalResultEvent::GetExpiryDate

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

 Gets the expiry date of a renewed protected-content license from a **LicenseRenewalResult** event.

## Parameters

### `pqwExpiryDate` [out, retval]

Receives the expiry date in number of seconds since epoch.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IESLicenseRenewalResultEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ieslicenserenewalresultevent)