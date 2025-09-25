# ITMultiTrackTerminal::get_DirectionsInUse

## Description

The
**get_DirectionsInUse** method returns the direction of all tracks managed currently by the multitrack terminal. For tracks that are multitrack terminals themselves, this method calls the track's **ITMultiTrackTerminal::get_DirectionsInUse** method to determine the track's directions.

## Parameters

### `plDirectionsInUsed` [out]

Pointer to the
[TERMINAL_DIRECTION](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-terminal_direction) descriptor of the directions.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITMultiTrackTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itmultitrackterminal)