# IMSVidAnalogTuner::ChannelAvailable

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **ChannelAvailable** method queries whether a specified channel is available for viewing.

This method is currently not supported.

## Parameters

### `nChannel` [in]

Integer containing the channel.

### `SignalStrength` [in, out]

Pointer to a **long** value that specifies the signal strength.

### `fSignalPresent` [out]

Receives a **VARIANT_BOOL** that indicates whether a signal is present.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[IAMTuner::SignalPresent](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamtuner-signalpresent)

[IMSVidAnalogTuner Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidanalogtuner)