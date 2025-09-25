# IDvbLogicalChannel2Descriptor::GetListRecordLogicalChannelNumber

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the value of the logical_channel_number field from a Digital Video Broadcast (DVB) logical channel descriptor. The logical_channel_number field gives the ordinal position of the service record in the descriptor.

## Parameters

### `bListIndex` [in]

Specifies the channel list record number,
indexed from zero. Call the [IDvbLogicalChannel2Descriptor::GetCountOfLists](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvblogicalchannel2descriptor-getcountoflists) method to get the number of channel list records in the logical channel descriptor.

### `bRecordIndex` [in]

Specifies the service record number,
indexed from zero. Call the [IDvbLogicalChannel2Descriptor::GetListCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvblogicalchannel2descriptor-getlistcountofrecords) method to get the number of service records in the logical channel descriptor.

### `pwVal` [out]

Receives the logical channel number. This can be any of the following values:

| Value | Meaning |
| --- | --- |
| 0 | Service not suitable for user selection |
| 1 - 999 | Logical channel number |
| 1000 - 1023 | Reserved for future use |

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDvbLogicalChannel2Descriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvblogicalchannel2descriptor)

[IDvbLogicalChannel2Descriptor::GetCountOfLists](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvblogicalchannel2descriptor-getcountoflists)

[IDvbLogicalChannel2Descriptor::GetListCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvblogicalchannel2descriptor-getlistcountofrecords)