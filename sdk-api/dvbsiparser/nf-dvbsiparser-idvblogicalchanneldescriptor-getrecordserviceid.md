# IDvbLogicalChannelDescriptor::GetRecordServiceId

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

**Note**This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 and later.

The **GetRecordServiceId** method returns the service identifier at a specified index in the channel list.

## Parameters

### `bRecordIndex` [in]

Zero-based index of the service identifier to return. To get the number of service identifiers in the descriptor, call [IDvbLogicalChannelDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvblogicalchanneldescriptor-getcountofrecords).

### `pwVal` [out]

Receives the service_id field.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDvbLogicalChannelDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvblogicalchanneldescriptor)