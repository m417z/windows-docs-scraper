# IServiceLocationDescriptor::GetElementLanguageCode

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the three-character ISO 639 language code for an Advanced Television Systems Committee (ATSC) service location descriptor.

## Parameters

### `bIndex` [in]

Specifies the elementary stream,
indexed from zero. Call the [IServiceLocationDescriptor::GetNumberOfElements](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nf-atscpsipparser-iservicelocationdescriptor-getnumberofelements) method to get the number of elementary streams in the descriptor.

### `LangCode` [out]

Pointer to a buffer that receives the language code. For a list of language codes, refer to [ISO 639 Code Tables](http://www-01.sil.org/iso639-3/codes.asp).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IServiceLocationDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nn-atscpsipparser-iservicelocationdescriptor)