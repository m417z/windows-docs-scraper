# IDvbParentalRatingDescriptor::GetTag

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

 Gets the tag that describes a Digital Video Broadcast (DVB) parental rating descriptor.

## Parameters

### `pbVal` [out]

Receives the parental rating descriptor tag. This value is "0x55" for parental rating descriptors.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDvbParentalRatingDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvbparentalratingdescriptor)