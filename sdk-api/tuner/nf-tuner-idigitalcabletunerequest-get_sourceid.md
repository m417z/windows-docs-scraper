# IDigitalCableTuneRequest::get_SourceID

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_SourceID** method retrieves the source identifier, which maps to a physical channel.

## Parameters

### `pSourceID` [out]

Receives the source identifier. If the value received is BDA_UNDEFINED_CHANNEL, the source identifier is not used.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[IDigitalCableTuneRequest Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-idigitalcabletunerequest)