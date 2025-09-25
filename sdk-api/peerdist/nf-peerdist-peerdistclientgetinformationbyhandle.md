# PeerDistClientGetInformationByHandle function

## Description

The **PeerDistClientGetInformationByHandle** function retrieves additional information from the Peer Distribution service for a specific content handle.

## Parameters

### `hPeerDist` [in]

A **PEERDIST_INSTANCE_HANDLE** returned by the [PeerDistStartup](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdiststartup) function.

### `hContentHandle` [in]

A **PEERDIST_CONTENT_HANDLE** returned by the [PeerDistClientOpenContent](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientopencontent) function.

### `PeerDistClientInfoClass` [in]

A value from the [PEERDIST_CLIENT_INFO_BY_HANDLE_CLASS](https://learn.microsoft.com/windows/win32/api/peerdist/ne-peerdist-peerdist_client_info_by_handle_class) enumeration that indicates the information to retrieve.

### `dwBufferSize`

The size, in bytes, of the buffer for the *lpInformation* parameter.

### `lpInformation` [out]

A buffer for the returned information. The format of this information depends on the value of the *PeerDistClientInfoClass* parameter.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

## See also

[PEERDIST_CLIENT_INFO_BY_HANDLE_CLASS](https://learn.microsoft.com/windows/win32/api/peerdist/ne-peerdist-peerdist_client_info_by_handle_class)

[PeerDistClientOpenContent](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientopencontent)

[PeerDistStartup](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdiststartup)