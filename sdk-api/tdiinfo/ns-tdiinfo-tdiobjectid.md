# TDIObjectID structure

## Description

[This structure may be altered or unavailable in future versions of Windows.]

Contains a part of the [TCP_REQUEST_QUERY_INFORMATION_EX](https://learn.microsoft.com/windows/desktop/api/tdiinfo/ns-tdiinfo-tcp_request_query_information_ex_w2k) structure that is used with the [IOCTL_TCP_QUERY_INFORMATION_EX](https://learn.microsoft.com/windows/desktop/api/tcpioctl/ni-tcpioctl-ioctl_tcp_query_information_ex) control code to specify the kind of information being requested from the TCP driver.

## Members

### `toi_entity`

This is a [TDIEntityID](https://learn.microsoft.com/windows/desktop/api/tdiinfo/ns-tdiinfo-tdientityid) structure.

### `toi_class`

The kind of information being requested. The value can be one of the following.

| Value | Meaning |
| --- | --- |
| **INFO_CLASS_GENERIC** | Used when requesting an enumeration of all TDI entities on the current machine, or when determining the type of one of those TDI entities. |
| **INFO_CLASS_PROTOCOL** | Used when requesting information about a specific interface or IP entity. |

### `toi_type`

The type of object being queried. The value can be one of the following.

| Value | Meaning |
| --- | --- |
| **INFO_TYPE_PROVIDER** | A service provider. All queries described in the [IOCTL_TCP_QUERY_INFORMATION_EX](https://learn.microsoft.com/windows/desktop/api/tcpioctl/ni-tcpioctl-ioctl_tcp_query_information_ex) topic use this type value. |
| **INFO_TYPE_ADDRESS_OBJECT** | An address object. |
| **INFO_TYPE_CONNECTION** | A connection object. |

### `toi_id`

 If **toi_class** is **INFO_CLASS_GENERIC**, **toi_id** can be one of the following.

| Value | Meaning |
| --- | --- |
| **ENTITY_LIST_ID** | The query returns a list of all TDI entities on the local machine. |
| **ENTITY_TYPE_ID** | The query returns a type value for a specified TDI entity. |

If **toi_class** is **INFO_CLASS_PROTOCOL**, **toi_id** can be one of the following.

| Value | Meaning |
| --- | --- |
| **IF_MIB_STATS_ID** | When the entity being queried is an interface supporting MIB-II, causes the query to return an [IFEntry](https://learn.microsoft.com/windows/desktop/api/tcpioctl/ns-tcpioctl-ifentry) structure that contains information about the interface. |
| **IP_MIB_STATS_ID** | When the entity being queried is a network-layer IP entity, causes the query to return an [IPSNMPInfo](https://learn.microsoft.com/windows/desktop/api/tcpioctl/ns-tcpioctl-ipsnmpinfo) structure that contains information about the entity. |
| **IP_MIB_ADDRTABLE_ENTRY_ID** | When the entity being queried is a network-layer IP entity on which one or more IP addresses are active, causes the query to return an array of [IPAddrEntry](https://learn.microsoft.com/windows/desktop/api/tcpioctl/ns-tcpioctl-ipaddrentry) structures that contain information about those addresses. |
| **IP_INTFC_INFO_ID** | Causes an [IPInterfaceInfo](https://learn.microsoft.com/windows/desktop/api/tcpioctl/ns-tcpioctl-ipinterfaceinfo) structure to be returned with information about a specific IP address specified in the **Context** member of the [TCP_REQUEST_QUERY_INFORMATION_EX](https://learn.microsoft.com/windows/desktop/api/tdiinfo/ns-tdiinfo-tcp_request_query_information_ex_w2k) structure. |

## See also

[IOCTL_TCP_QUERY_INFORMATION_EX](https://learn.microsoft.com/windows/desktop/api/tcpioctl/ni-tcpioctl-ioctl_tcp_query_information_ex)

[Management Information Base
Reference](https://learn.microsoft.com/previous-versions/windows/desktop/mib/management-information-base-reference)