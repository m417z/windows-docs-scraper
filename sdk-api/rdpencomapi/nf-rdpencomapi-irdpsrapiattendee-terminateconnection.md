# IRDPSRAPIAttendee::TerminateConnection

## Description

Disconnects the client represented by the attendee.

## Return value

Type: **HRESULT**

If the method succeeds, the return value is **S_OK**. Otherwise, the return value is an error code. The following is a possible value.

## Remarks

This method disconnects clients from the session. The clients can reconnect because the authentication is based on the invitation. To provide stricter access control to the session, an application can create one invitation object per attendee and revoke the invitation at the same time it calls this method.

This call is not blocking. However, termination is not immediate and can be delayed by a send operation. If the thread that is managing connections is in the middle of sending a buffer, it must wait for the buffer to be sent. The caller should consider the attendee disconnected only after the [_IRDPSessionEvents::OnAttendeeDisconnected](https://learn.microsoft.com/previous-versions/windows/desktop/rdp/onattendeedisconnected) event is fired.

## See also

[IRDPSRAPIAttendee](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapiattendee)