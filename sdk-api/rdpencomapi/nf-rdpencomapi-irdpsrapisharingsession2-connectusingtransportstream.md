# IRDPSRAPISharingSession2::ConnectUsingTransportStream

## Description

Connects using the specified transport stream.

## Parameters

### `pStream` [in]

The transport stream used for the connection.

### `bstrGroup` [in]

The name of the group. The string must be unique for the session. Applications typically use the group name to separate attendees into groups that can be granted different authorization levels.

### `bstrAuthenticatedAttendeeName` [in]

The name of the authenticated attendee.

## Return value

If the method succeeds, the return value is **S_OK**. Otherwise, the return value is an error code.

## See also

[IRDPSRAPISharingSession2](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapisharingsession2)