# IDvbShortEventDescriptor::GetLanguageCode

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the three-character ISO 639 language code from
a Digital Video Broadcast (DVB) short event descriptor.

## Parameters

### `pszCode`

Receives the language code. For a list of language codes, refer to [this document](http://www.sil.org/ISO639-3/codes.asp). The caller is responsible for freeing this memory.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDvbShortEventDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvbshorteventdescriptor)