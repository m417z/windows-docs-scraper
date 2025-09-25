# SECPKG_CLIENT_INFO structure

## Description

The **SECPKG_CLIENT_INFO** structure holds information about a [security package's](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) client. This structure is used by the
[GetClientInfo](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_get_client_info) function.

## Members

### `LogonId`

The client's effective [logon identifier](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly).

### `ProcessID`

The client's process identifier.

### `ThreadID`

The client's thread identifier.

### `HasTcbPrivilege`

**TRUE** if the client has the SeTcbPrivilege privilege; otherwise **FALSE**.

### `Impersonating`

**TRUE** if the client is impersonating another [security principal](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

### `Restricted`

The client is restricted in its ability to access securable objects or perform privileged operations.

### `ClientFlags`

### `ImpersonationLevel`

### `ClientToken`