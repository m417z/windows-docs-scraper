# PeerDistClientCloseContent function

## Description

The **PeerDistClientCloseContent** function closes the content handle opened by [PeerDistClientOpenContent](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientopencontent).

## Parameters

### `hPeerDist` [in]

A **PEERDIST_INSTANCE_HANDLE** returned by [PeerDistStartup](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdiststartup).

### `hContentHandle` [in]

A **PEERDIST_CONTENT_HANDLE** opened by [PeerDistClientOpenContent](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientopencontent).

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**. Otherwise, the function may return one of the following values:

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more parameters are invalid. |
| **ERROR_INVALID_HANDLE** | The *hPeerDist* or *hContent* handle is invalid. |

## Remarks

This function will cancel all pending asynchronous operations associated with the provided *hContentHandle*.

 All handles opened by the [PeerDistClientOpenContent](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientopencontent) function must be closed by **PeerDistClientCloseContent**.

## See also

[PeerDistClientOpenContent](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientopencontent)