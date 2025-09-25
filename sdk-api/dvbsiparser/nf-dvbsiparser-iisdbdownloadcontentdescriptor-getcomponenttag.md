# IIsdbDownloadContentDescriptor::GetComponentTag

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the tag that identifies a stream component from an Integrated Services Digital Broadcasting (ISDB) download content descriptor. This tag also identifies the stream in the program map table (PMT).

## Parameters

### `pbVal` [out]

Receives the component tag.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbDownloadContentDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbdownloadcontentdescriptor)