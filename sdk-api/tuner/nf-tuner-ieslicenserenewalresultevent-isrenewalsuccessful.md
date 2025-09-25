# IESLicenseRenewalResultEvent::IsRenewalSuccessful

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

 Gets a flag from a **LicenseRenewalResult** event that indicates whether the renewal was successful. In the event of failure, a client can call the [GetRenewalResultCode](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-ieslicenserenewalresultevent-getrenewalresultcode) or [GetRenewalHResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-ieslicenserenewalresultevent-getrenewalhresult) method to get information about the reason for the failure.

## Parameters

### `pfRenewalSuccessful` [out, retval]

Receives the renewal success flag: 1 indicates success; 0 indicates failure.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[GetRenewalHResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-ieslicenserenewalresultevent-getrenewalhresult)

[GetRenewalResultCode](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-ieslicenserenewalresultevent-getrenewalresultcode)

[IESLicenseRenewalResultEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ieslicenserenewalresultevent)