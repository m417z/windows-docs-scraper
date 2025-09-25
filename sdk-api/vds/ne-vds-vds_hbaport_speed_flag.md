# VDS_HBAPORT_SPEED_FLAG enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of valid flags for determining the speeds supported by an HBA port.
These values are used in the **ulPortSpeed** member of the
[VDS_HBAPORT_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_hbaport_prop) structure.

## Constants

### `VDS_HSF_UNKNOWN:0`

The HBA port speed is unknown. The transceiver is incapable of reporting.

HBA_PORTSPEED_UNKNOWN

### `VDS_HSF_1GBIT:0x1`

The HBA port supports a transfer rate of 1 gigabit per second.

HBA_PORTSPEED_1GBIT

### `VDS_HSF_2GBIT:0x2`

The HBA port supports a transfer rate of 2 gigabits per second.

HBA_PORTSPEED_2GBIT

### `VDS_HSF_10GBIT:0x4`

The HBA port supports a transfer rate of 10 gigabits per second.

HBA_PORTSPEED_10GBIT

### `VDS_HSF_4GBIT:0x8`

The HBA port supports a transfer rate of 4 gigabits per second.

HBA_PORTSPEED_4GBIT

### `VDS_HSF_NOT_NEGOTIATED`

The HBA port speed has not been established.

HBA_PORTSPEED_NOT_NEGOTIATED

## Remarks

**Note** Additional constants might be added to the **VDS_HBAPORT_SPEED_FLAG** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_HBAPORT_SPEED_FLAG** enumeration constant.

## See also

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)

[VDS_HBAPORT_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_hbaport_prop)