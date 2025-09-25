# PeerDistStartup function

## Description

The **PeerDistStartup** function creates a new Peer Distribution instance handle which must be passed to all other Peer Distribution APIs.

## Parameters

### `dwVersionRequested` [in]

Contains the minimum version of the Peer Distribution requested by the application. The high order byte specifies the minor version number; the low order byte specifies the major version number.

### `phPeerDist` [out]

A pointer to a **PEERDIST_INSTANCE_HANDLE** variable which upon success receives a newly created handle.

### `pdwSupportedVersion` [out, optional]

A pointer to a variable which, if not **NULL**, contains the maximum version number that is supported by the Peer Distribution system. The high order byte specifies the minor version number; the low order byte specifies the major version number.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**. Otherwise, the function may return one of the following values:

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more parameters are invalid. |
| **PEERDIST_ERROR_VERSION_UNSUPPORTED** | The requested version is not supported by client side DLL. |

## Remarks

**PeerDistStartup** must be called before any other Peer Distribution functions. When no longer needed, the handle returned by **PeerDistStartup** should be closed via a call to [PeerDistShutdown](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistshutdown).

## See also

[PeerDistShutdown](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistshutdown)