# FT_STATE_EVENT_CAUSE enumeration

## Description

The
**FT_STATE_EVENT_CAUSE** enum indicates the type of file terminal event.

## Constants

### `FTEC_NORMAL:0`

State change in response to a normal API call.

### `FTEC_END_OF_FILE`

Storage EOF reached on playback.

### `FTEC_READ_ERROR`

Storage read error on playback.

### `FTEC_WRITE_ERROR`

Storage write error on the record.

#### - FTEC_MAX_DURATION_REACHED

Maximum duration threshold has been reached on the record.

#### - FTEC_PAUSE_ON_SILENCE_SIGNAL_DETECTED

Woken up from the pause caused by triggering the pause-on-silence threshold because a signal was detected.

#### - FTEC_PAUSE_ON_SILENCE_THRESHOLD_TRIGGERED

The pause-on-silence threshold has been reached.

#### - FTEC_STOP_ON_SILENCE_THRESHOLD_TRIGGERED

The stop-on-silence threshold has been reached.

## See also

[ITFileTerminalEvent::get_Cause](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itfileterminalevent-get_cause)