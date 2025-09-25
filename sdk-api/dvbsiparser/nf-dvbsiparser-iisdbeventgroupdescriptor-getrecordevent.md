# IIsdbEventGroupDescriptor::GetRecordEvent

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

 Gets data from an event record in an Integrated Services Digital Broadcasting (ISDB) event group descriptor.

## Parameters

### `bRecordIndex` [in]

Zero-based index of the event record containing the data. To get the number of components, call [IIsdbEventGrouptDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdbtsinformationdescriptor-getcountofrecords).

### `pwServiceId` [out]

Receives the value of the sevice_id field from the event record. This value identifies the information service and appears in the program_number field of the corresponding program map section.

### `pwEventId` [out]

Receives the value of the event_id field from the related event record. This value identifies the event.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbEventGroupDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbeventgroupdescriptor)

[IIsdbEventGrouptDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdbtsinformationdescriptor-getcountofrecords)