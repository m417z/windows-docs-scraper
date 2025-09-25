# ITuneRequest::get_TuningSpace

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_TuningSpace** method retrieves the tuning space that was used to create this tune request.

## Parameters

### `TuningSpace` [out]

Receives a pointer to the [ITuningSpace](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ituningspace) interface. The caller must release the interface.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## Remarks

You must first access the tuning space in order to obtain the default locator and the default preferred component types.

## See also

[ITuneRequest Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-itunerequest)