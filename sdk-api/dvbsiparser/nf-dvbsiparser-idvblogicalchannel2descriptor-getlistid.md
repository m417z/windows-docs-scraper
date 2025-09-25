# IDvbLogicalChannel2Descriptor::GetListId

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the identifier for a channel list from a Digital Video Broadcast (DVB) logical channel descriptor.

## Parameters

### `bListIndex` [in]

Specifies the channel list record number,
indexed from zero. Call the [IDvbLogicalChannel2Descriptor::GetListCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvblogicalchannel2descriptor-getlistcountofrecords) method to get the number of channel list records in the logical channel descriptor.

### `pbVal` [out]

Pointer to a byte that receives the channel list identifier.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDvbLogicalChannel2Descriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvblogicalchannel2descriptor)

[IDvbLogicalChannel2Descriptor::GetListCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvblogicalchannel2descriptor-getlistcountofrecords)