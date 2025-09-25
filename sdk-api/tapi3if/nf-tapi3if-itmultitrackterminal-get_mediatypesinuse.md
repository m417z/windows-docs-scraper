# ITMultiTrackTerminal::get_MediaTypesInUse

## Description

The
**get_MediaTypesInUse** method returns the media types (bitwise ORed) of all tracks managed currently by the multitrack terminal. For tracks that are multitrack terminals themselves, this method calls the track's **ITMultiTrackTerminal::get_MediaTypesInUse** method to determine the track's media types.

## Parameters

### `plMediaTypesInUse` [out]

Bitwise ORed list of
[media types](https://learn.microsoft.com/windows/desktop/Tapi/tapimediatype--constants) in use.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITMultiTrackTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itmultitrackterminal)