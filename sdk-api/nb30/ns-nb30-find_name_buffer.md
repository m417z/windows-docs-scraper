# FIND_NAME_BUFFER structure

## Description

[[Netbios](https://learn.microsoft.com/previous-versions/windows/desktop/netbios/portal) is not supported on Windows Vista, Windows Server 2008, and subsequent versions of the operating system]

The **FIND_NAME_BUFFER** structure contains information about a local network session. One or more **FIND_NAME_BUFFER** structures follows a [FIND_NAME_HEADER](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-find_name_header) structure when an application specifies the **NCBFINDNAME** command in the ncb_command member of the [NCB](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-ncb) structure.

## Members

### `length`

Specifies the length, in bytes, of the **FIND_NAME_BUFFER** structure. Although this structure always occupies 33 bytes, not all of the structure is necessarily valid.

### `access_control`

Specifies the access control for the LAN header.

### `frame_control`

Specifies the frame control for the LAN header.

### `destination_addr`

Specifies the destination address of the remote node where the name was found.

### `source_addr`

Specifies the source address for the remote node where the name was found.

### `routing_info`

Specifies additional routing information.

## See also

[FIND_NAME_HEADER](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-find_name_header)

[NCB](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-ncb)

[NetBIOS Structures](https://learn.microsoft.com/previous-versions/windows/desktop/netbios/netbios-structures)

[The NetBIOS Interface Overview](https://learn.microsoft.com/previous-versions/windows/desktop/netbios/portal)