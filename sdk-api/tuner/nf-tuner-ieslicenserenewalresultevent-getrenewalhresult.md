# IESLicenseRenewalResultEvent::GetRenewalHResult

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the final **HRESULT** value from a **LicenseRenewalResult** event that is returned by a call to a COM interface method during the renewal process.

## Parameters

### `phr` [out, retval]

Receives the **HRESULT** value.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IESLicenseRenewalResultEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ieslicenserenewalresultevent)