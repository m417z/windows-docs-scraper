# CB\_TARGET\_INFO structure

Contains information about the target computer and IP addresses where incoming connections should be redirected. This structure is used with the [**IConnectionBrokerClient::GetTargetInfo**](https://learn.microsoft.com/windows/win32/termserv/iconnectionbrokerclient-gettargetinfo) method.

## Members

**ServerName**

Represents the fully qualified domain name of the target server. For a Remote Desktop virtualization (RDV) scenario, this member is **NULL**. For a Remote Desktop session host (RDSH) scenario, this member contains the server name where the incoming connection is redirected.

**AddressCount**

The number of valid entries in the **Addresses** array.

**Addresses**

An array of strings that contain the IP addresses where the incoming connections are redirected. The number of valid elements in this array is specified in the **AddressCount** member.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8<br> |
| Minimum supported server<br> | Windows Server 2012<br> |
| Header<br> | Cbclient.h |

## See also

[**IConnectionBrokerClient::GetTargetInfo**](https://learn.microsoft.com/windows/win32/termserv/iconnectionbrokerclient-gettargetinfo)

