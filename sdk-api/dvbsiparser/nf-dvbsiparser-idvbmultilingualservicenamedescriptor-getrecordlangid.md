# IDvbMultilingualServiceNameDescriptor::GetRecordLangId

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the three-character ISO 639 language code from a Digital Video Broadcast (DVB) multilingual service name descriptor. The language code
identifies the language used for text in the descriptor.

## Parameters

### `bRecordIndex` [in]

Specifies the service record number,
indexed from zero. Call the [IDvbMultilingualServiceNameDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvbmultilingualservicenamedescriptor-getcountofrecords) method to get the number of records in the multilingual service name descriptor.

### `ulVal` [out]

Pointer to a buffer that receives the language code. For a list of language codes, refer to [this document](http://www.sil.org/ISO639-3/codes.asp).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDvbMultilingualServiceNameDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvbmultilingualservicenamedescriptor)

[IDvbMultilingualServiceNameDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvbmultilingualservicenamedescriptor-getcountofrecords)