# IATSCLocator::get_PhysicalChannel

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_PhysicalChannel** method retrieves the physical channel.

## Parameters

### `PhysicalChannel` [out]

Receives the physical channel.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## Remarks

This is a required property. A tuner cannot locate an ATSC transmission source without it.

## See also

[IATSCLocator Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iatsclocator)