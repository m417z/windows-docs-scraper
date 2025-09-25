# ITMediaControl::get_MediaState

## Description

The
**get_MediaState** method gets the current state of media on the file terminal.

## Parameters

### `pTerminalMediaState` [out]

Pointer to the
[TERMINAL_MEDIA_STATE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-terminal_media_state) descriptor of the current state of the file terminal.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITMediaControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itmediacontrol)

[TERMINAL_MEDIA_STATE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-terminal_media_state)