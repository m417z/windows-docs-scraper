# IDvbLogicalChannel2Descriptor::GetListCountOfRecords

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets an indexed count of records for a channel list in a Digital Video Broadcast (DVB) logical channel descriptor.

## Parameters

### `bChannelListIndex` [in]

Specifies the channel list number,
indexed from zero. Call the [IDvbLogicalChannel2Descriptor::GetCountOfLists](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvblogicalchanneldescriptor-getcountofrecords) method to get the number of channel lists in the logical channel descriptor.

### `pbVal` [out]

Receives the number of channels in the list.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDvbLogicalChannel2Descriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvblogicalchannel2descriptor)

[IDvbLogicalChannel2Descriptor::GetCountOfLists](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvblogicalchanneldescriptor-getcountofrecords)