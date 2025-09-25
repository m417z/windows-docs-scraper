# TERMINAL_MEDIA_STATE enumeration

## Description

The
**TERMINAL_MEDIA_STATE** enum indicates the state of a file terminal.

## Constants

### `TMS_IDLE:0`

The file terminal is idle.

### `TMS_ACTIVE`

The file terminal is active.

### `TMS_PAUSED`

The file terminal is paused.

### `TMS_LASTITEM:TMS_PAUSED`

Last item in this enum.

## See also

[ITFileTerminalEvent::get_State](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itfileterminalevent-get_state)

[ITMediaControl::get_MediaState](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itmediacontrol-get_mediastate)