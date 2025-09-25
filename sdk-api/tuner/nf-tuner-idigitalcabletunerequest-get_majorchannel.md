# IDigitalCableTuneRequest::get_MajorChannel

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_MajorChannel** method retrieves the major channel number.

## Parameters

### `pMajorChannel` [out]

Receives the major channel number. If the value received is BDA_UNDEFINED_CHANNEL, the major channel number is not used.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[IDigitalCableTuneRequest Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-idigitalcabletunerequest)