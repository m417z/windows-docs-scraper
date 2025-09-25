# ACTION_HEADER structure

## Description

[[Netbios](https://learn.microsoft.com/previous-versions/windows/desktop/netbios/portal) is not supported on Windows Vista, Windows Server 2008, and subsequent versions of the operating system]

The ACTION_HEADER structure contains information about an action. This action is an extension to the standard transport interface.

## Members

### `transport_id`

Specifies the transport provider. This member can be used to check the validity of the request by the transport.

This member is always a four-character string. All strings starting with the letter M are reserved, as shown in the following example.

#### MOOO (All transports)

#### MNBF (NBF)

#### MABF (AsyBEUI)

#### MXNS (XNS)

**Windows XP:** Certain legacy networking protocols, including NetBEUI, will no longer be supported.

### `action_code`

Specifies the action.

### `reserved`

Reserved.

## Remarks

The scope of the action is determined by the **ncb_lsn** and **ncb_num** members of the [NCB](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-ncb) structure, as follows.

|  | ncb_lsn = 0 | ncb_lsn != 0 |
| --- | --- | --- |
| ncb_num = 0 | Action applies to control channel associated with the valid LAN adapter. | Action applies to connection identifier associated with the valid local session number. |
| ncb_num != 0 | Action applies to address associated with the valid LAN adapter. | Illegal combination. |

## See also

[NCB](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-ncb)

[NetBIOS Structures](https://learn.microsoft.com/previous-versions/windows/desktop/netbios/netbios-structures)

[The NetBIOS Interface Overview](https://learn.microsoft.com/previous-versions/windows/desktop/netbios/portal)