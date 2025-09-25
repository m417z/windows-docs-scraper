# IDVBTLocator::get_LPInnerFEC

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_LPInnerFEC** method retrieves the inner FEC type of the low-priority stream.

## Parameters

### `FEC` [out]

Receives a member of the [FECMethod](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/fecmethod) enumeration.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## See also

[IDVBTLocator Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-idvbtlocator)