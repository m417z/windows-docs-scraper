# IIsdbAudioComponentDescriptor::GetLanguageCode2

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

In ES multilingual mode, gets the second three-character ISO 639 language code from an ISDB audio component descriptor.

## Parameters

### `pszCode`

Pointer to the buffer that receives the language code. For a list of language codes, refer to [ISO 639 Code Tables](http://www.sil.org/ISO639-3/codes.asp).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbAudioComponentDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbaudiocomponentdescriptor)