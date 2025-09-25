# USE_INFO_2 structure

## Description

The
**USE_INFO_2** structure contains information about a connection between a local computer and a shared resource, including connection type, connection status, user name, and domain name.

## Members

### `ui2_local`

Type: **LMSTR**

A pointer to a string that contains the local device name (for example, drive E or LPT1) being redirected to the shared resource. The constant DEVLEN specifies the maximum number of characters in the string. This member can be **NULL**. For more information, see the following Remarks section.

This string is Unicode if **_WIN32_WINNT** or **FORCE_UNICODE** are defined.

### `ui2_remote`

Type: **LMSTR**

A pointer to a string that contains the share name of the remote resource. The string is in the form

``` syntax
\\servername\sharename

```

This string is Unicode if **_WIN32_WINNT** or **FORCE_UNICODE** are defined.

### `ui2_password`

Type: **LMSTR**

A pointer to a string that contains the password needed to establish a session with a specific workstation.

This string is Unicode if **_WIN32_WINNT** or **FORCE_UNICODE** are defined.

### `ui2_status`

Type: **DWORD**

The status of the connection. This element is not used by the
[NetUseAdd](https://learn.microsoft.com/windows/desktop/api/lmuse/nf-lmuse-netuseadd) function. The following values are defined.

| Value | Meaning |
| --- | --- |
| **USE_OK** | The connection is successful. |
| **USE_PAUSED** | Paused by a local workstation. |
| **USE_SESSLOST** | Disconnected. |
| **USE_DISCONN** | An error occurred. |
| **USE_NETERR** | A network error occurred. |
| **USE_CONN** | The connection is being made. |
| **USE_RECONN** | Reconnecting. |

### `ui2_asg_type`

Type: **DWORD**

The type of remote resource being accessed. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **USE_WILDCARD** | Matches the type of the server's shared resources. Wildcards can be used only with the [NetUseAdd](https://learn.microsoft.com/windows/desktop/api/lmuse/nf-lmuse-netuseadd) function, and only when the **ui2_local** member is a **NULL** string. For more information, see the following Remarks section. |
| **USE_DISKDEV** | Disk device. |
| **USE_SPOOLDEV** | Spooled printer. |
| **USE_IPC** | Interprocess communication (IPC). |

### `ui2_refcount`

Type: **DWORD**

The number of files, directories, and other processes that are open on the remote resource. This element is not used by the
**NetUseAdd** function.

### `ui2_usecount`

Type: **DWORD**

The number of explicit connections (redirection with a local device name) or implicit UNC connections (redirection without a local device name) that are established with the resource.

### `ui2_username`

Type: **LPWSTR**

A pointer to a string that contains the name of the user who initiated the connection.

This string is Unicode if **_WIN32_WINNT** or **FORCE_UNICODE** are defined.

### `ui2_domainname`

Type: **LMSTR**

A pointer to a string that contains the domain name of the remote resource.

This string is Unicode if **_WIN32_WINNT** or **FORCE_UNICODE** are defined.

## Remarks

Specifying a **ui2_local** member that is **NULL** requests authentication with the server without redirecting a drive letter or a device. Future redirections involving the server while the same connection is in effect use the authentication information specified in the initial call to the
[NetUseAdd](https://learn.microsoft.com/windows/desktop/api/lmuse/nf-lmuse-netuseadd) function. This information includes the combination of the **ui2_password**, **ui2_username**, and **ui2_domainname** members.

## See also

[NetUseAdd](https://learn.microsoft.com/windows/desktop/api/lmuse/nf-lmuse-netuseadd)

[NetUseEnum](https://learn.microsoft.com/windows/desktop/api/lmuse/nf-lmuse-netuseenum)

[NetUseGetInfo](https://learn.microsoft.com/windows/desktop/api/lmuse/nf-lmuse-netusegetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[Use Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/use-functions)