# _MS_SMHBA_FC_PHY structure

## Description

The MS_SMHBA_FC_PHY structure is used to report the physical attributes of a fibre channel port.

## Members

### `PhySupportSpeed`

The signaling bit rates at which the port can operate. For a list of the values that this member supports, see PhySpeed.

### `PhySpeed`

The signaling bit rates at which PortWWN is currently operating. This member must have one of the values in the following table.

|  |  |
| --- | --- |
| **Value** | **Meaning** |
| HBA_PORTSPEED_UNKNOWN | Speed unknown. The transceiver is incapable of reporting the speed. |
| HBA_PORTSPEED_1GBIT | 1 gigabit per sec. |
| HBA_PORTSPEED_2GBIT | 2 gigabits per sec. |
| HBA_PORTSPEED_10GBIT | 10 gigabits per sec. |
| HBA_PORTSPEED_4GBIT | 4 gigabits per sec. |
| HBA_PORTSPEED_NOT_NEGOTIATED | The speed at which the port will operate has not yet been established. |

### `PhyType`

The port type. This member must have one of the values in the following table.

|  |  |
| --- | --- |
| **Value** | **Meaning** |
| HBA_PORTTYPE_UNKNOWN | Unknown port type. |
| HBA_PORTTYPE_OTHER | Value that is not a port type. |
| HBA_PORTTYPE_NOTPRESENT | Port not present. |
| HBA_PORTTYPE_NPORT | Fabric. |
| HBA_PORTTYPE_NLPORT | Public loop. |
| HBA_PORTTYPE_FLPORT | Fabric on a loop. |
| HBA_PORTTYPE_FPORT | Fabric port. |
| HBA_PORTTYPE_EPORT | Fabric expansion port. |
| HBA_PORTTYPE_GPORT | Generic fabric. |
| HBA_PORTTYPE_LPORT | Private loop port. |
| HBA_PORTTYPE_PTP | Point to point. |

### `MaxFrameSize`

The maximum frame size, in bytes, that is supported by PortWWN.