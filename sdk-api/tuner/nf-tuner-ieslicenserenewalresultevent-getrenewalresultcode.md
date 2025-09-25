# IESLicenseRenewalResultEvent::GetRenewalResultCode

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets a constant from a Protected Broadcast Driver Architecture (PBDA) **LicenseRenewalResult** event that indicates which step in the renewal process caused the renewal to succeed or fail. A client can call the [IsRenewalSuccessful](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-ieslicenserenewalresultevent-isrenewalsuccessful) method to determine if the renewal was successful, and then call this method to get information about the reason for any failure.

## Parameters

### `pdwRenewalResultCode` [out, retval]

Receives the result code. The result code indicates the license renewal step that failed and can be any of the following values.

| Value | Meaning |
| --- | --- |
| LBE_RenewalStage_Invalid | Received license was invalid. |
| LRE_RenewalStage_RenewalFailed | Renewal attempt failed. |
| LRE_RenewalStage_CheckForRenewableLicense | Renewal attempt failed during the check for a renewable license. |
| LRE_RenewalStage_RenewLicenseAtTuner | Renewal attempt failed at the tuner. |
| LRE_RenewalStage_StoreLicenseInDRM | Renewal attempt failed during license storage. |
| LRE_RenewalStage_RenewalSuccessful | License renewal was successful. |

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IESLicenseRenewalResultEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ieslicenserenewalresultevent)