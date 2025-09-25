# IComponent::put_DescLangID

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_DescLangID** method sets the language for presentation of the description.

## Parameters

### `LangID` [in]

Specifies the language ID.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## Remarks

This is the language of the descriptive info in the component object. It is not the same as the language ID in the language component type which defines the language of the stream content. An application can modify this value in order to activate a different language substream.

## See also

[IComponent Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-icomponent)