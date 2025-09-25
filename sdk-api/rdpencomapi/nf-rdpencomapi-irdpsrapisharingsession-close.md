# IRDPSRAPISharingSession::Close

## Description

Disconnects all attendees from the session and stops listening to incoming connections.

When the attendees are disconnected, no attendee disconnect event occurs on the sharer side because it is the sharer that calls this method. The sharer is already aware that the attendees will be disconnected.

A closed session cannot be reopened by calling the [IRDPSRAPISharingSession::Open](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nf-rdpencomapi-irdpsrapisharingsession-open) method.

## Return value

If the method succeeds, the return value is **S_OK**. Otherwise, the return value is an error code.

## See also

[IRDPSRAPISharingSession](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapisharingsession)

[IRDPSRAPISharingSession2](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapisharingsession2)