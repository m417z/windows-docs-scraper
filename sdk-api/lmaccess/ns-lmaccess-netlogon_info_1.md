# NETLOGON_INFO_1 structure

## Description

The **NETLOGON_INFO_1** structure defines a level-1 control query response from a domain controller.

## Members

### `netlog1_flags`

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

### `netlog1_pdc_connection_status`

An enumerated integer value that contains a status code defined in Lmerr.h, with a value greater than 2100. This value applies only to backup domain controllers, and shows the status of the secure channel connection to the PDC in their domain.

## See also

[I_NetLogonControl2](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-i_netlogoncontrol2)