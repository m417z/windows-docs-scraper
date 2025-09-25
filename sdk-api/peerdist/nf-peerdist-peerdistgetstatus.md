# PeerDistGetStatus function

## Description

The **PeerDistGetStatus** function returns the current status of the Peer Distribution service.

## Parameters

### `hPeerDist` [in]

A **PEERDIST_INSTANCE_HANDLE** returned by [PeerDistStartup](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdiststartup).

### `pPeerDistStatus` [out]

A pointer to a [PEERDIST_STATUS](https://learn.microsoft.com/windows/desktop/api/peerdist/ne-peerdist-peerdist_status) enumeration which upon operation success receives the current status of the Peer Distribution service.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

## Remarks

A Group Policy change can result in the Peer Distribution service moving to an available, unavailable, or disabled state. Depending on the resultant state of this transition, the content, content information, or stream handles the caller has access to may no longer function. If this is the case, the caller must explicitly close the handles by calling the appropriate Peer Distribution API.

## See also

[PEERDIST_STATUS](https://learn.microsoft.com/windows/desktop/api/peerdist/ne-peerdist-peerdist_status)

[PeerDistClientCloseContent](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientclosecontent)

[PeerDistServerCloseContentInformation](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserverclosecontentinformation)

[PeerDistServerCloseStreamHandle](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserverclosestreamhandle)