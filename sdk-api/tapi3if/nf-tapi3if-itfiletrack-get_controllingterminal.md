# ITFileTrack::get_ControllingTerminal

## Description

The
**get_ControllingTerminal** method returns the multitrack terminal that controls the current track.

## Parameters

### `ppControllingTerminal` [out]

Pointer to the
[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal) interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

TAPI calls the **AddRef** method on the
[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal) interface returned by **ITFileTrack::get_ControllingTerminal**. The application must call **Release** on
**ITTerminal** to free resources associated with it.

## See also

[ITFileTrack](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itfiletrack)

[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal)