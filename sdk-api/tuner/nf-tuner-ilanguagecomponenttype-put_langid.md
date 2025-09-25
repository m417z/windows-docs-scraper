# ILanguageComponentType::put_LangID

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_LangID** method specifies the LCID that identifies the language

## Parameters

### `LangID` [in]

Specifies the LCID.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## Remarks

The *LangID* parameter is a Win32 LCID. Use this method to set the language of an audio stream, for example when creating a new entry for the Guide Store database. Use the [IComponent::put_DescLangID](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-icomponent-put_desclangid) method to specify the language of the text description of the stream.

## See also

[ILanguageComponentType Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ilanguagecomponenttype)

[ILanguageComponentType::get_LangID](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-ilanguagecomponenttype-get_langid)