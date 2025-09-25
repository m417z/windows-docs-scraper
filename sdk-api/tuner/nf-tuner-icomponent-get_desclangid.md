# IComponent::get_DescLangID

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_DescLangID** method retrieves the language identifier for the description property.

## Parameters

### `LangID` [out]

Receives the language identifier.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## Remarks

The returned language identifier identifies the language of the description property, which is obtained by calling the **get_Description** method.

To get the language of the stream content, call the [ILanguageComponentType::get_LangID](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-ilanguagecomponenttype-get_langid) method (only if the component object exposes the [ILanguageComponentType](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ilanguagecomponenttype) interface).

## See also

[IComponent Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-icomponent)

[IComponent::get_Description](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-icomponent-get_description)