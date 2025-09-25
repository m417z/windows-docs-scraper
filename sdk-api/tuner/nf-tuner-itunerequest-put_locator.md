# ITuneRequest::put_Locator

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_Locator** method is called from the Network Provider to set the [ILocator](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ilocator) object associated with the requested broadcast.

## Parameters

### `Locator` [in]

Pointer to an **ILocator** interface that specifies the new locator.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## See also

[ITuneRequest Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-itunerequest)