# IESFileExpiryDateEvent::GetMaxRenewalCount

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the maximum number of times that a license for protected content can be renewed from a **FileExpiryDate** event.

## Parameters

### `dwMaxRenewalCount` [out, retval]

Receives the maximum renewal count.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IESFileExpiryDateEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iesfileexpirydateevent)