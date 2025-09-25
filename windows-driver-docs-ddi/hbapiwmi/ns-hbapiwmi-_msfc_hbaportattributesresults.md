# _MSFC_HBAPortAttributesResults structure

## Description

The structure is used by the [GetDiscoveredPortAttributes](https://learn.microsoft.com/windows-hardware/drivers/storage/getdiscoveredportattributes) WMI method to report the attributes for a specified remote fibre channel port.

## Members

### `NodeWWN`

Contains a 64 bit world-wide name (WWN) that uniquely identifies the fibre channel node associated with **PortWWN**. For a discussion of worldwide names, see the T11 committee's *Fibre Channel HBA API* specification.

### `PortWWN`

Contains a 64 bit world-wide name (WWN) that uniquely identifies the fibre channel port. For a discussion of worldwide names, see the T11 committee's *Fibre Channel HBA API* specification.

### `PortFcId`

Contains the current fibre channel address of **PortWWN**. The high order byte of this member contains the first byte of the address, and successively lower order bytes of this member contain successively lower bytes of the address. The lowest order byte of this member must be zero.

### `PortType`

Indicates the port type. This member must have one of the following values:

| Value | Meaning |
| --- | --- |
| HBA_PORTTYPE_UNKNOWN | Unknown port type. |
| HBA_PORTTYPE_OTHER | Value that is not a port type. |
| HBA_PORTTYPE_NOTPRESENT | Port not present. |
| HBA_PORTTYPE_NPORT | Fabric. |
| HBA_PORTTYPE_NLPORT | Public loop. |
| HBA_PORTTYPE_FLPORT | Fabric on a loop. |
| HBA_PORTTYPE_FPORT | Fabric port. |
| HBA_PORTTYPE_EPORT | Fabric expansion port. |
| HBA_PORTTYPE_GPORT | Generic Fabric. |
| HBA_PORTTYPE_LPORT | Private loop port. |
| HBA_PORTTYPE_PTP | Point to point. |

### `PortState`

Contains the state of the port indicated by **PortWWN**. This member must have one of the following values:

| Value | Meaning |
| --- | --- |
| HBA_PORTSTATE_UNKNOWN | Unknown. |
| HBA_PORTSTATE_ONLINE | Operational. |
| HBA_PORTSTATE_OFFLINE | User Offline |
| HBA_PORTSTATE_BYPASSED | Bypassed. |
| HBA_PORTSTATE_DIAGNOSTICS | In diagnostics mode. |
| HBA_PORTSTATE_LINKDOWN | Link Down |
| HBA_PORTSTATE_ERROR | Port Error. |
| HBA_PORTSTATE_LOOPBACK | Loopback. |

### `PortSupportedClassofService`

Indicates the class of service that are supported by **PortWWN**. For a list of the differences classes of service and the values that must be assigned to this member for each class, see the ANSI standard for *Fibre Channel Generic Services 4th Generation* (FC-GS-4).

### `PortSupportedFc4Types`

Indicates the FC-4 types that are supported by **PortWWN**. For a discussion FC-4 types, see the ANSI standard for *Fibre Channel Generic Services 4th Generation* (FC-GS-4).

### `PortActiveFc4Types`

Indicates the FC-4 types that are currently available on **PortWWN**. For a discussion FC-4 types, see the ANSI standard for *Fibre Channel Generic Services 4th Generation* (FC-GS-4).

### `PortSupportedSpeed`

Indicates the signaling bit rates at which **PortWWN** can operate. For a list of the values that this member supports, see **PortSpeed**.

### `PortSpeed`

Indicates the signaling bit rates at which **PortWWN** is currently operating. This member must have one of the following values:

| Value | Meaning |
| --- | --- |
| HBA_PORTSPEED_UNKNOWN | Speed unknown. The transceiver is incapable of reporting the speed. |
| HBA_PORTSPEED_1GBIT | 1 gigabit per sec |
| HBA_PORTSPEED_2GBIT | 2 gigabits per sec |
| HBA_PORTSPEED_4GBIT | 4 gigabits per sec |
| HBA_PORTSPEED_10GBIT | 10 gigabits per sec |
| HBA_PORTSPEED_NOT_NEGOTIATED | The speed at which the port will operate has not yet been established. |

### `PortMaxFrameSize`

Indicates the maximum frame size, in bytes, that is supported by **PortWWN**.

### `FabricName`

Contains the name identifier for the fabric to which **PortWWN** is attached.

### `NumberofDiscoveredPorts`

Indicates the number of ports that are visible to **PortWWN**. For a more detailed explanation of the sorts of ports that this number takes into consideration, see the T11 committee's specification for *Fibre Channel HBA API* (FC-HBA).

## See also

[GetDiscoveredPortAttributes](https://learn.microsoft.com/windows-hardware/drivers/storage/getdiscoveredportattributes)