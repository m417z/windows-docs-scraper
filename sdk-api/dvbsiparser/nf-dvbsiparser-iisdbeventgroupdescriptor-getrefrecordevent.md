# IIsdbEventGroupDescriptor::GetRefRecordEvent

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets data from a related event record in an Integrated Services Digital Broadcasting (ISDB) event group descriptor. The descriptor contains records for related events if the group_type field of the descriptor has a value of 4 or 5. If this field has a value of 4, it indicates an event relay to other networks. If this field has a value of 5, it indicates an event movement from other networks.

## Parameters

### `bRecordIndex` [in]

Zero-based index of the related event record containing the data. To get the number of components, call [IIsdbEventGrouptDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdbtsinformationdescriptor-getcountofrecords).

### `pwOriginalNetworkId` [out]

Receives the value of the original_network_id field from the related
event record. This value is transmitted at the time of event relay or event move across networks.

### `pwTransportStreamId` [out]

Receives the value of the transport_stream_id field from the related
event record. This value that is transmitted at the time of event relay or event move across networks.

### `pwServiceId` [out]

Receives the value of the sevice_id field from the related event record. This value identifies the related information service and appears in the program_number field of the corresponding program map section.

### `pwEventId` [out]

Receives the value of the event_id field from the related event record. This value identifies the related event.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbEventGroupDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbeventgroupdescriptor)

[IIsdbEventGrouptDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdbtsinformationdescriptor-getcountofrecords)