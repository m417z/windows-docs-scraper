# _POS_CX_EVENT_DEST enumeration

## Description

The POS_CX_EVENT_DEST defines which applications receive this event.

## Constants

### `POS_CX_EVENT_DEST_INVALID`

Specifies that no devices will receive this event. This value should not be used.

### `POS_CX_EVENT_DEST_DEVICE_OWNER`

Specifies that only the current claim owner will receive this event.

### `POS_CX_EVENT_DEST_ALL`

Specifies that the event will be broadcast to all client handles.

### `POS_CX_EVENT_DEST__MAX`