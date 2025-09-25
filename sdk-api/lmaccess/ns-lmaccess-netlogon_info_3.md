## Description

The **NETLOGON_INFO_3** structure defines a level-3 control query response from a domain controller.

## Members

### `netlog3_flags`

An integer value that contains one or more of the following control query responses from the DC.

| Value | Meaning |
| --- | --- |
| **NETLOGON_REPLICATION_NEEDED**<br><br>0x00000001 | Not supported. |
| **NETLOGON_REPLICATION_IN_PROGRESS**<br><br>0x00000002 | Not supported. |
| **NETLOGON_FULL_SYNC_REPLICATION**<br><br>0x00000004 | Not supported. |
| **NETLOGON_REDO_NEEDED**<br><br>0x00000008 | Not supported. |
| **NETLOGON_HAS_IP**<br><br>0x00000010 | Trusted domain DC has an IP address. |
| **NETLOGON_HAS_TIMESERV**<br><br>0x00000020 | Trusted domain DC runs the Windows Time Service. |
| **NETLOGON_DNS_UPDATE_FAILURE**<br><br>0x00000040 | Last update to the DNS records on the DC failed. |

### `netlog3_logon_attempts`

The number of logon attempts made for the domain.

### `netlog3_reserved1`

Reserved value.

### `netlog3_reserved2`

Reserved value.

### `netlog3_reserved3`

Reserved value.

### `netlog3_reserved4`

Reserved value.

### `netlog3_reserved5`

Reserved value.

## See also

[I_NetLogonControl2](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-i_netlogoncontrol2)