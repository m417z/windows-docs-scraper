# PRIVILEGE_SET structure

## Description

The **PRIVILEGE_SET** structure specifies a set of security privileges. It is also used to indicate which, if any, privileges are held by a user or group requesting access to an object.

## Members

### `PrivilegeCount`

The number of privileges in the privilege set.

### `Control`

Specifies a control flag related to the privileges. The PRIVILEGE_SET_ALL_NECESSARY control flag is currently defined. It indicates that all of the specified privileges must be held by the process requesting access. If this flag is not set, the presence of any privileges in the user's access token grants the access.

### `Privilege`

Specifies an array of [**LUID_AND_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_luid_and_attributes) structures describing the set's privileges. The following attributes are defined for privileges.

| Value | Meaning |
| ----- | ------- |
| SE_PRIVILEGE_ENABLED_BY_DEFAULT | The privilege is enabled by default. |
| SE_PRIVILEGE_ENABLED | The privilege is enabled. |
| SE_PRIVILEGE_USED_FOR_ACCESS | The privilege was used to gain access to an object or service. This flag is used to identify the relevant privileges in a set passed by a client application that may contain unnecessary privileges. |

## Remarks

A privilege is used to control access to an object or service more strictly than is typical with discretionary access control. A system manager uses privileges to control which users are able to manipulate system resources. An application uses privileges when it changes a system-wide resource, such as when it changes the system time or shuts down the system.

## See also

[**SeAccessCheck**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-seaccesscheck)

[**PRIVILEGE_SET** structure (winnt.h)](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-privilege_set)