# NAME_BUFFER structure

## Description

[[Netbios](https://learn.microsoft.com/previous-versions/windows/desktop/netbios/portal) is not supported on Windows Vista, Windows Server 2008, and subsequent versions of the operating system]

The **NAME_BUFFER** structure contains information about a local network name. One or more **NAME_BUFFER** structures follows an [ADAPTER_STATUS](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-adapter_status) structure when an application specifies the **NCBASTAT** command in the ncb_command member of the [NCB](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-ncb) structure.

## Members

### `name`

Specifies the local network name. This value is in the **ncb_name** member of the [NCB](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-ncb) structure.

### `name_num`

Specifies the number for the local network name. This value is in the **ncb_num** member of the [NCB](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-ncb) structure.

### `name_flags`

Specifies the current state of the name table entry. This member can be one of the following values.

**REGISTERED**

The name specified by the name member has been successfully added to the network.

**DEREGISTERED**

The name specified by the name member has an active session when an NCBDELNAME command is issued. The name will be removed from the name table when the session is closed.

**DUPLICATE**

A duplicate name was detected during registration.

**DUPLICATE_DEREG**

A duplicate name was detected with a pending deregistration.

**GROUP_NAME**

The name specified by the name member was created by using the NCBADDGRNAME command.

**UNIQUE_NAME**

The name specified by the name member was created by using the NCBADDNAME command.

## See also

[ADAPTER_STATUS](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-adapter_status)

[NCB](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-ncb)

[NetBIOS Structures](https://learn.microsoft.com/previous-versions/windows/desktop/netbios/netbios-structures)

[The NetBIOS Interface Overview](https://learn.microsoft.com/previous-versions/windows/desktop/netbios/portal)