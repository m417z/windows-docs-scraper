# IDvbSubtitlingDescriptor::GetTag

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the tag for a Digital Video Broadcast (DVB) subtitling descriptor.

## Parameters

### `pbVal` [out]

Receives the subtitling descriptor tag. For subtitling descriptors, this tag value is "0x59".

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDvbSubtitlingDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvbsubtitlingdescriptor)