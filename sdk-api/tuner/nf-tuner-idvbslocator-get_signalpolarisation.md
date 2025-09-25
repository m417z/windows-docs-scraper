# IDVBSLocator::get_SignalPolarisation

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_SignalPolarisation** method retrieves the signal polarisation.

## Parameters

### `PolarisationVal` [out]

Pointer to a variable of type [Polarisation](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/polarisation) that receives the polarisation value.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## Remarks

This method and the associated enumeration type use the British spelling for "polarisation" to maintain consistency with standards documentation.

## See also

[IDVBSLocator Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-idvbslocator)