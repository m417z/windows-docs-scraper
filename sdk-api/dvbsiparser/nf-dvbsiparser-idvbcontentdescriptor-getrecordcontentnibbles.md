# IDvbContentDescriptor::GetRecordContentNibbles

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the two 4-bit fields that make up a DVB-defined identifier for a content descriptor.

## Parameters

### `bRecordIndex` [in]

Zero-based index of the descriptor to return. To get the number of descriptors, call [IDvbContentDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvbcontentdescriptor-getcountofrecords)

### `pbValLevel1` [out]

Gets the most-significant four bits of the content identifier.

### `pbValLevel2` [out]

Gets the least-significant four bits of the content identifier.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For a list of content descriptors associated with the values returned in the *dwVal1* and *dwVal2* parameters, see Table 28 in Section 6.2.9 of the DVB standard document titled
*Digital Video Broadcasting (DVB);
Specification for Service Information (SI) in DVB systems (DVB Document A038 Rev. 4)*. (This resource may not be available in some languages

and countries.)

## See also

[IDvbContentDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvbcontentdescriptor)