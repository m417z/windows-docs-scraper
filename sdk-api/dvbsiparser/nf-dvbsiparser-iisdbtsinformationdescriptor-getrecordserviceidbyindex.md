# IIsdbTSInformationDescriptor::GetRecordServiceIdByIndex

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets a service identifier from a specified service record in an Integrated Services Digital Broadcasting (ISDB) transport stream (TS) information descriptor.

## Parameters

### `bRecordIndex` [in]

Zero-based index of the descriptor to return. To get the number of descriptors, call [IIsdbTSInformationDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdbtsinformationdescriptor-getcountofrecords).

### `bServiceIndex` [in]

Zero-based index of the service identifier to return. To get the number of identifiers, call [IIsdbTSInformationDescriptor::GetRecordNumberOfServices](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdbtsinformationdescriptor-getrecordnumberofservices).

### `pdwVal` [out]

Receives the service identifier.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbTSInformationDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbtsinformationdescriptor)

[IIsdbTSInformationDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdbtsinformationdescriptor-getcountofrecords)

[IIsdbTSInformationDescriptor::GetRecordNumberOfServices](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdbtsinformationdescriptor-getrecordnumberofservices)