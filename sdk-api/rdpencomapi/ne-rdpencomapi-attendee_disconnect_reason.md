# ATTENDEE_DISCONNECT_REASON enumeration

## Description

Defines values for the reasons why an attendee was disconnected from the session.

## Constants

### `ATTENDEE_DISCONNECT_REASON_MIN:0`

Minimum enumeration value.

### `ATTENDEE_DISCONNECT_REASON_APP:0`

The application called the [IRDPSRAPIAttendee::TerminateConnection](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nf-rdpencomapi-irdpsrapiattendee-terminateconnection) method.

### `ATTENDEE_DISCONNECT_REASON_ERR:1`

There was an internal error when processing data from an attendee or trying to manage an attendee

### `ATTENDEE_DISCONNECT_REASON_CLI:2`

The attendee disconnected after a request from the attendee itself.

### `ATTENDEE_DISCONNECT_REASON_MAX:2`

Maximum enumeration value.

## See also

[Reason Property of IRDPSRAPIAttendeeDisconnectInfo](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nf-rdpencomapi-irdpsrapiattendeedisconnectinfo-get_reason)