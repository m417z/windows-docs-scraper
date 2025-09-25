## Description

The **USE_INFO_3** structure contains information about a connection between a local computer and a shared resource, including connection type, connection status, user name, domain name, and specific flags that describe connection behavior.

## Members

### `ui3_ui2`

[USE_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmuse/ns-lmuse-use_info_2) structure that contains

### `ui3_flags`

A set of bit flags that describe connection behavior and credential handling.

| Value | Meaning |
| --- | --- |
| **CREATE_NO_CONNECT** | Do not connect to the server. |
| **CREATE_BYPASS_CSC** | Force a connection to the server, bypassing the CSC. |
| **USE_DEFAULT_CREDENTIALS** | No explicit credentials are supplied in the call to [NetUseAdd](https://learn.microsoft.com/windows/desktop/api/lmuse/nf-lmuse-netuseadd). |

## See also

[NetUseEnum](https://learn.microsoft.com/windows/desktop/api/lmuse/nf-lmuse-netuseenum)

[NetUseGetInfo](https://learn.microsoft.com/windows/desktop/api/lmuse/nf-lmuse-netusegetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[Use functions](https://learn.microsoft.com/windows/desktop/NetMgmt/use-functions)