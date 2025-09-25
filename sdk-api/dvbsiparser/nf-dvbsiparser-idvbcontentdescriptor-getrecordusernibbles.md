# IDvbContentDescriptor::GetRecordUserNibbles

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the two 4-bit fields that make up a broadcaster-defined identifier for a content descriptor.

## Parameters

### `bRecordIndex` [in]

Zero-based index of the descriptor to return. To get the number of descriptors, call [IDvbContentDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvbcontentdescriptor-getcountofrecords)

### `pbVal1` [out]

Gets the most-significant four bits of the broadcaster-defined content identifier. These bits are returned in the right-most four bits of the byte.

### `pbVal2` [out]

Gets the least-significant four bits of the broadcaster-defined content identifier. These bits are returned in the left-most four bits of the byte.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDvbContentDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvbcontentdescriptor)