# IATSCTuningSpace::get_MinMinorChannel

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_MinMinorChannel** method gets the lowest minor channel number ever allowed for this tuning space.

## Parameters

### `MinMinorChannelVal` [out]

Receives the lowest minor channel.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## See also

[IATSCTuningSpace Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iatsctuningspace)