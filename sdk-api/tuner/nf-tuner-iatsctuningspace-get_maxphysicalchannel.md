# IATSCTuningSpace::get_MaxPhysicalChannel

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_MaxPhysicalChannel** method gets the highest physical channel number for this tuning space.

## Parameters

### `MaxPhysicalChannelVal` [out]

Receives the highest physical channel.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## See also

[IATSCTuningSpace Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iatsctuningspace)

[IChannelTuneRequest::put_Channel](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-ichanneltunerequest-put_channel)