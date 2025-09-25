# IDvbExtendedEventDescriptor::GetRecordItemRawBytes

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the raw data from the
current item in a Digital Video Broadcast (DVB) extended event descriptor.

## Parameters

### `bRecordIndex` [in]

Specifies the item record number,
indexed from zero. Call the [IDvbExtendedEventDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvbextendedeventdescriptor-getcountofrecords) method to get the number of records in the extended event descriptor.

### `ppbRawItem` [out]

Pointer to a buffer that gets the item data. The caller is responsible for freeing this memory.

### `pbItemLength` [out]

Receives the number of bytes in the item description.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDvbExtendedEventDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvbextendedeventdescriptor)

[IDvbExtendedEventDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvbextendedeventdescriptor-getcountofrecords)