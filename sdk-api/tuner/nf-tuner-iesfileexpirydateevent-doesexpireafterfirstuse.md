# IESFileExpiryDateEvent::DoesExpireAfterFirstUse

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets a flag from a **FileExpiryDate** event that indicates whether a license for protected content expires after its first use.

## Parameters

### `pfExpireAfterFirstUse` [out, retval]

Receives the flag, which is true if the license expires after first use or false otherwise.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IESFileExpiryDateEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iesfileexpirydateevent)