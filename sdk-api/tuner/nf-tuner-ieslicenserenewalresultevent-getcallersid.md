# IESLicenseRenewalResultEvent::GetCallersId

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

 Gets a unique identifier from a **LicenseRenewalResult** event that identifies the caller. Each client that attempts to renew a license must specify this identifier to identify the client that is requesting the license renewal. When the renewal completes, this result is sent out and received by all the clients that are listening for this event. Clients can use this identifier value to match whether the result belongs to them or is intended for some other client.

## Parameters

### `pdwCallersId` [out, retval]

Receives the caller identifier.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IESLicenseRenewalResultEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ieslicenserenewalresultevent)