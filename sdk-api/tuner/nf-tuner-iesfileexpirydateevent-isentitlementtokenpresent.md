# IESFileExpiryDateEvent::IsEntitlementTokenPresent

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets a flag from **FileExpiryDate** event that indicates whether a license for protected content contains an entitlement token. Media transform devices and media sink devices in a Protected Broadcast Driver Architecture (PBDA) filter graph can use entitlement tokens to verify whether users can access protected content.

## Parameters

### `pfEntTokenPresent` [out, retval]

Receives the flag, which is true if the license for protected content contains an entitlement token or false otherwise.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IESFileExpiryDateEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iesfileexpirydateevent)