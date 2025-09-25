# IATSCTuningSpace::put_MaxMinorChannel

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_MaxMinorChannel** method gets the highest minor channel number for this tuning space.

## Parameters

### `NewMaxMinorChannelVal` [in]

The highest minor channel.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## Remarks

This property must be set before calling [put_MinMinorChannel](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-iatsctuningspace-put_minminorchannel) to avoid the case where the minimum minor channel is greater than the maximum minor channel. Both properties default to -1 (not set).

## See also

[IATSCTuningSpace Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iatsctuningspace)