# IDvbTeletextDescriptor::GetRecordLangId

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the three-character ISO 639 language code from a Digital Video Broadcast (DVB)
teletext descriptor.

## Parameters

### `bRecordIndex` [in]

Zero-based index of the descriptor to return. To get the number of descriptors,
call [IDvbTeletextDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvbteletextdescriptor-getcountofrecords).

### `pulVal` [out]

Pointer to a 24-bit buffer that receives the language code. For a list of language codes, refer to [this document](http://www.sil.org/ISO639-3/codes.asp).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDvbTeletextDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvbteletextdescriptor)

[IDvbTeletextDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvbteletextdescriptor-getcountofrecords)