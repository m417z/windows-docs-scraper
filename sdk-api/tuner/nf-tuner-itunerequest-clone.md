# ITuneRequest::Clone

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **Clone** method returns a new copy of this tune request.

## Parameters

### `NewTuneRequest` [out]

Address of an **ITuneRequest** interface pointer that will be set to the new object.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## Remarks

This method performs a "deep copy" of the object; in other words it copies all sub-objects as well, including [Components](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/components-object), [LanguageComponentType](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/languagecomponenttype-object) objects, and so on.

## See also

[ITuneRequest Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-itunerequest)