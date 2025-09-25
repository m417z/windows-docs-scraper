# IESLicenseRenewalResultEvent::IsCheckEntitlementCallRequired

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

 Gets a flag from a **LicenseRenewalResult** event that indicates whether the client should check the entitlement token from the license. The client can call the [IBDA_ConditionalAccessEx::CheckEntitlementToken](https://learn.microsoft.com/windows/desktop/api/bdaiface/nf-bdaiface-ibda_conditionalaccessex-checkentitlementtoken) method to validate the entitlement token.

## Parameters

### `pfCheckEntTokenCallNeeded` [out, retval]

Receives the check entitlement token flag: 1 indicates that a check is needed; 0 indicates that no check is needed.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IBDA_ConditionalAccessEx::CheckEntitlementToken](https://learn.microsoft.com/windows/desktop/api/bdaiface/nf-bdaiface-ibda_conditionalaccessex-checkentitlementtoken)

[IESLicenseRenewalResultEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ieslicenserenewalresultevent)