# IATSCChannelTuneRequest::put_MinorChannel

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_MinorChannel** method sets the minor channel to be tuned.

## Parameters

### `MinorChannel` [in]

Specifies the minor channel. If the value is -1, the tuner tunes to the first valid minor channel it finds.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## See also

[IATSCChannelTuneRequest Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iatscchanneltunerequest)