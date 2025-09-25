# IDvbContentIdentifierDescriptor::GetRecordCrid

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the content reference identifier (CRID) from a Digital Video Broadcast (DVB) content identifier descriptor.

## Parameters

### `bRecordIndex` [in]

Zero-based index of the service record to return. To get the number of service records in the descriptor, call the [IDvbContentIdentifierDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvbcontentidentifierdescriptor-getcountofrecords) method.

### `pbType` [out]

Receives the type of the CRID.

### `pbLocation` [out]

Gets the location of the CRID.

### `pbLength` [out]

Gets the number of bytes required to return the CRID.

### `ppbBytes` [out]

Pointer to a buffer that receives the CRID. The caller is responsible for freeing this memory.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDvbContentIdentifierDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvbcontentidentifierdescriptor)

[IDvbContentIdentifierDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvbcontentidentifierdescriptor-getcountofrecords)