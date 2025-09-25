# EVT_SUBSCRIBE_NOTIFY_ACTION enumeration

## Description

Defines the possible types of data that the subscription service can deliver to your callback.

## Constants

### `EvtSubscribeActionError:0`

Indicates that the *Event* parameter contains a Win32 error code.

### `EvtSubscribeActionDeliver`

Indicates that the *Event* parameter contains an event that matches the subscriber's query.

## See also

[EVT_SUBSCRIBE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/winevt/nc-winevt-evt_subscribe_callback)