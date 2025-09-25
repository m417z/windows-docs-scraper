# FIND_NAME_HEADER structure

## Description

[[Netbios](https://learn.microsoft.com/previous-versions/windows/desktop/netbios/portal) is not supported on Windows Vista, Windows Server 2008, and subsequent versions of the operating system]

The **FIND_NAME_HEADER** structure contains information about a network name. This structure is followed by as many [FIND_NAME_BUFFER](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-find_name_buffer) structures as are required to describe the name.

## Members

### `node_count`

Specifies the number of nodes on which the specified name was found. This structure is followed by the number of [FIND_NAME_BUFFER](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-find_name_buffer) structures specified by the **node_count** member.

### `reserved`

Reserved

### `unique_group`

Specifies whether the name is unique. This value is 0 to specify a unique name or 1 to specify a group.

## Remarks

The **FIND_NAME_HEADER** structure is pointed to by the **ncb_buffer** member of the [NCB](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-ncb) structure when an application issues an **NCBFINDNAME** command.

## See also

[FIND_NAME_BUFFER](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-find_name_buffer)

[NCB](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-ncb)

[NetBIOS Structures](https://learn.microsoft.com/previous-versions/windows/desktop/netbios/netbios-structures)

[The NetBIOS Interface Overview](https://learn.microsoft.com/previous-versions/windows/desktop/netbios/portal)