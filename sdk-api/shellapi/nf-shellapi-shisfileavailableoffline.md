# SHIsFileAvailableOffline function

## Description

Determines whether a file or folder is available for offline use. This function also determines whether the file would be opened from the network, from the local Offline Files cache, or from both locations.

## Parameters

### `pwszPath` [in]

Type: **PCWSTR**

A pointer to a string value that specifies the full path to a network file or directory. This path does not need to be in UNC form. If *pszPath* is not a network path, the function returns E_INVALIDARG.

### `pdwStatus` [out, optional]

Type: **LPDWORD**

A pointer to a variable of type **DWORD** that receives one or more of the following flags if the function succeeds.

#### OFFLINE_STATUS_LOCAL (0x01)

If the file is open, it is open in the cache.

#### OFFLINE_STATUS_REMOTE (0x02)

If the file is open, it is open on the server.

#### OFFLINE_STATUS_INCOMPLETE (0x04)

The local copy is currently incomplete. The file cannot be opened in offline mode until it has been synchronized.

## Return value

Type: **HRESULT**

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The file or directory is cached. It is available offline unless **OFFLINE_STATUS_INCOMPLETE** is set. |
| **E_INVALIDARG** | The path is invalid or not a network path. The file or directory is not cached. |
| **E_FAIL** | The file or directory is not cached. |

## Remarks

If *pszPath* is a directory, **SHIsFileAvailableOffline** will not return the **OFFLINE_STATUS_INCOMPLETE** flag.

If **SHIsFileAvailableOffline** returns both **OFFLINE_STATUS_LOCAL** and **OFFLINE_STATUS_REMOTE**, the file or directory is open in both places. This is common when the server is online.