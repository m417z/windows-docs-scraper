## Description

Returns if there is an active session on the system without enumerating through the list of sessions. It also does not obtain any extra information from Local Session Manager.

## Parameters

### `pbActiveSessionExists` [out]

A pointer to a boolean value indicating whether an active session exists.

## Return value

Returns zero if this function fails. If this function succeeds, a nonzero value is returned.

## Remarks

This function only determines if an active session exists. To get a list of sessions and their states, use `WTSEnumerateSessions`. Many processes running in session 0 use **[WTSEnumerateSessions](https://learn.microsoft.com/windows/win32/api/wtsapi32/nf-wtsapi32-wtsenumeratesessionsa)** to check if an active session exists, or to do things if an active session exists (ie: get user name, session id, etc). Using **WTSEnumerateSessions** when there are no active sessions is expensive because the entire list of inactive sessions must be enumerated.