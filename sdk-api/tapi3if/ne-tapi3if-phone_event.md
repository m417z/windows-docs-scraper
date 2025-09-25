# PHONE_EVENT enumeration

## Description

The
**PHONE_EVENT** enum indicates a type of phone event.

## Constants

### `PE_DISPLAY:0`

Phone display has changed.

### `PE_LAMPMODE`

Lamp mode has changed.

### `PE_RINGMODE`

Ringing mode has changed.

### `PE_RINGVOLUME`

Ringing volume has changed.

### `PE_HOOKSWITCH`

Hookswitch status has changed.

### `PE_CAPSCHANGE`

Phone capabilities have changed.

### `PE_BUTTON`

The phone button has changed.

### `PE_CLOSE`

The phone has been closed.

### `PE_NUMBERGATHERED`

A dialed number has been gathered by the phone.

### `PE_DIALING`

The phone is dialing.

### `PE_ANSWER`

The phone has been answered.

### `PE_DISCONNECT`

The phone has been disconnected.

### `PE_LASTITEM`

Last item in enum. Allows device-specific additions to this enum.

## See also

[ITPhoneEvent::get_Event](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphoneevent-get_event)