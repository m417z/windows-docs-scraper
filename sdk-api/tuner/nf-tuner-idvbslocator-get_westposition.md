# IDVBSLocator::get_WestPosition

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_WestPosition** method retrieves a value indicating whether the orbital position is given in east or west longitude.

## Parameters

### `WestLongitude` [out]

Pointer to a variable of type **VARIANT_BOOL**; a value of true means "west longitude."

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## See also

[IDVBSLocator Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-idvbslocator)