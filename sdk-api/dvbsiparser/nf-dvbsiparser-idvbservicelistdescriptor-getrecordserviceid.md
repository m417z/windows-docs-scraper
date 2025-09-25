# IDvbServiceListDescriptor::GetRecordServiceId

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the value of the service_id field from a Digital Video Broadcast (DVB) service list descriptor.The service_id field value uniquely identifies the service within the MPEG-2 transport stream.

## Parameters

### `bRecordIndex` [in]

Specifies the service record number,
indexed from zero. Call the [IDvbServiceListDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvbservicelistdescriptor-getcountofrecords) method to get the number of records in the logical channel descriptor.

### `pwVal` [out]

Receives the service_id field value.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDvbServiceListDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvbservicelistdescriptor)

[IDvbServiceListDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvbservicelistdescriptor-getcountofrecords)