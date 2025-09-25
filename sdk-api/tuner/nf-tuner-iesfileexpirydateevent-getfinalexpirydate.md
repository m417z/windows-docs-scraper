# IESFileExpiryDateEvent::GetFinalExpiryDate

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the date from a **FileExpiryDate** event that indicates when a renewable license for protected content finally expires.

## Parameters

### `pqwExpiryDate` [out, retval]

Receives the final expiry date.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IESFileExpiryDateEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iesfileexpirydateevent)