# ILocator::Clone

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **Clone** method creates a copy of the Locator.

## Parameters

### `NewLocator` [out]

Receives a pointer to the [ILocator](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ilocator) interface. The caller must release the interface.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## See also

[ILocator Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ilocator)