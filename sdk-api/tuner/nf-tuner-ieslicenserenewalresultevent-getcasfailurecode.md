# IESLicenseRenewalResultEvent::GetCASFailureCode

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

 Gets a code from a **LicenseRenewalResult** event that indicates the reason for the failure in the conditional access system (CAS).

## Parameters

### `pdwCASFailureCode` [out, retval]

Receives the CAS failure code. This code is defined by the CAS that is used.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IESLicenseRenewalResultEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ieslicenserenewalresultevent)