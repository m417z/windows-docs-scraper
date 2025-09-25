# IDvbLogicalChannel2Descriptor::GetListCountryCode

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the three-character ISO 3166 country code for a channel list in a Digital Video Broadcast (DVB) logical channel descriptor.

## Parameters

### `bListIndex` [in]

Specifies the channel list record number,
indexed from zero. Call the [IDvbLogicalChannel2Descriptor::GetListCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvblogicalchannel2descriptor-getlistcountofrecords) method to get the number of channel list records in the logical channel descriptor.

### `pszCode` [out]

Pointer to a buffer that receives the country code. This code is a 3-character, null-terminated string, so the buffer must be at least four bytes long. The caller is responsible for releasing this memory.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDvbLogicalChannel2Descriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvblogicalchannel2descriptor)