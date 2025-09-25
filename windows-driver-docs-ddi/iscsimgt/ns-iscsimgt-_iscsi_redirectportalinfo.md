# _ISCSI_RedirectPortalInfo structure

## Description

This ISCSI_RedirectPortalInfo structure contains information about a collection of iSCSI portals that can be used during portal hopping or portal redirect operations. If a target portal is not available for login, the initiator can "hop" through the list of target portals that it discovered and that can be used for login operations. That is, the initiator will continue to try the list of portals that are available until it finds one that can be used for login, so it can then log in to the available target portal.

## Members

### `UniqueConnectionId`

The connection identifier (ID) that the operating system and application software use to uniquely identify the connection. The [LoginToTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logintotarget) and [AddConnectionToSession](https://learn.microsoft.com/windows-hardware/drivers/storage/addconnectiontosession) methods both return this value in the UniqueConnectionId parameter. This value is not to be confused with the connection ID (CID).

### `OriginalIPAddr`

This is the original IP address given during login from which redirection is to be set, and the IP address is provided via the ISCSI_IP_Address structure.

### `OriginalPort`

This is the original portals socket number given during login.

### `RedirectedIPAddr`

This is the IP address to which traffic needs to be redirected. The IP address is provided via the ISCSI_IP_Address structure.

### `RedirectedPort`

This is the socket number for the redirected target portal.

### `Redirected`

This indicates whether the login is redirected. If this value is **TRUE**, RedirectedIPAddr and RedirectedPort are valid.

### `TemporaryRedirect`

This value is **true** if redirection is temporary.

## See also

[AddConnectionToSession](https://learn.microsoft.com/windows-hardware/drivers/storage/addconnectiontosession)

[LoginToTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logintotarget)