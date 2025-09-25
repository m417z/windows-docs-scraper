# IDVBTLocator::get_Bandwidth

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_Bandwidth** method retrieves the bandwidth of the frequency.

## Parameters

### `BandWidthVal` [out]

Receives the bandwidth, in megahertz (MHz).

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## Remarks

The bandwidth is determined by the bandwidth field in the DVB terrestrial delivery system descriptor, as defined in EN 300 468. Valid values are 7 or 8.

## See also

[IDVBTLocator Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-idvbtlocator)