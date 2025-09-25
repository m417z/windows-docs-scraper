# ITMultiTrackTerminal::CreateTrackTerminal

## Description

The
**CreateTrackTerminal** method creates a multitrack terminal that can handle a given media type or types and media direction.

## Parameters

### `MediaType` [in]

Bitwise ORed list of
[media types](https://learn.microsoft.com/windows/desktop/Tapi/tapimediatype--constants) required for the terminal.

### `TerminalDirection` [in]

The
[TERMINAL_DIRECTION](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-terminal_direction) descriptor for the terminal.

### `ppTerminal` [out]

Pointer to the
[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal) interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

TAPI calls the **AddRef** method on the
[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal) interface returned by **ITMultiTrackTerminal::CreateTrackTerminal**. The application must call **Release** on the
**ITTerminal** interface to free resources associated with it.

## See also

[ITMultiTrackTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itmultitrackterminal)

[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal)