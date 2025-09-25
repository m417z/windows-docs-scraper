# IDvbLogicalChannel2Descriptor::GetListRecordLogicalChannelAndVisibility

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the visible_service_flag and logical_channel_number fields from a Digital Video Broadcast (DVB) logical channel descriptor. The visible_service_flag indicates whether a service record in the DVB logical channel descriptor is visible through the receiver service list and can be selected. The logical_channel_number field contains a broadcaster-defined channel number that is used to order services.

## Parameters

### `bListIndex` [in]

Specifies the channel list record number,
indexed from zero. Call the [GetCountOfLists](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvblogicalchannel2descriptor-getcountoflists) method to get the number of channel list records in the logical channel descriptor.

### `bRecordIndex` [in]

Specifies the service record number,
indexed from zero. Call the [GetListCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvblogicalchannel2descriptor-getlistcountofrecords) method to get the number of service records in the logical channel descriptor.

### `pwVal` [out]

Receives the visible_service_flag (defined by bit 15) and logical_channel_number (defined by bits 0 - 9) field values.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The combinations of visible_service_flag and local_channel_number field values have the following meanings.

| visible_service_flag | logical_channel_number | Meaning |
| --- | --- | --- |
| 0 | 0 | Service not suitable for selection by the user. For example, the value zero may be used for data services intended only for selection from interactive applications or for firmware download services. |
| 1 | 0 | Reserved for future use. |
| 0 | 1-1024 | Reserved for future use. |
| 1 | 1-999 | Service is displayed in service lists and Event Schedule Guide (ESG). Service is accessible via P+/- keys or from numeric keys (same value as decimal value of logical_channel_number). |
| 1 | > 999 | Reserved. |

## See also

[GetCountOfLists](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvblogicalchannel2descriptor-getcountoflists)

[GetListCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvblogicalchannel2descriptor-getlistcountofrecords)

[IDvbLogicalChannel2Descriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvblogicalchannel2descriptor)