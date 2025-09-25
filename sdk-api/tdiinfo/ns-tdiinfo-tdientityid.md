# TDIEntityID structure

## Description

[This structure may be altered or unavailable in future versions of Windows.]

Contains a part of the [TDIObjectID](https://learn.microsoft.com/windows/desktop/api/tdiinfo/ns-tdiinfo-tdiobjectid) structure to represent information about TDI drivers retrieved using the [IOCTL_TCP_QUERY_INFORMATION_EX](https://learn.microsoft.com/windows/desktop/api/tcpioctl/ni-tcpioctl-ioctl_tcp_query_information_ex) control code.

## Members

### `tei_entity`

The type of entity being addressed. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **GENERIC_ENTITY** | Used when requesting a list of all entities. |
| **AT_ENTITY** | Identifies an address-translation (AT) entity. |
| **CL_NL_ENTITY** | Identifies a connectionless (CL) network-layer (NL) entity. |
| **CO_NL_ENTITY** | Identifies a connected, directed-packet (CO) network-layer (NL) entity. |
| **CL_TL_ENTITY** | Identifies a connectionless (CL) transport-layer (TL) entity. |
| **CO_TL_ENTITY** | Identifies a connected, directed-packet (CO) transport-layer (TL) entity. |
| **ER_ENTITY** | Identifies an Echo-Request/Echo-Reply (ER) entity. |
| **IF_ENTITY** | Identifies an interface entity. |

### `tei_instance`

An opaque value that can uniquely identify an entity, if a specific one is being addressed.

## See also

[IOCTL_TCP_QUERY_INFORMATION_EX](https://learn.microsoft.com/windows/desktop/api/tcpioctl/ni-tcpioctl-ioctl_tcp_query_information_ex)

[Management Information Base
Reference](https://learn.microsoft.com/previous-versions/windows/desktop/mib/management-information-base-reference)

[TDIObjectID](https://learn.microsoft.com/windows/desktop/api/tdiinfo/ns-tdiinfo-tdiobjectid)