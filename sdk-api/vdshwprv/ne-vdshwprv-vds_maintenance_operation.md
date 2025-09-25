# VDS_MAINTENANCE_OPERATION enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of valid subsystem maintenance operations.

## Constants

### `BlinkLight:1`

Blinks a light on a drive.

### `BeepAlarm:2`

Beeps an alarm on a drive.

### `SpinDown:3`

Slows the spinning of a drive such that the drive enters an idle state. Typically used for the purpose of saving power.

### `SpinUp:4`

Starts the spinning of a drive in preparation for data reads.

### `Ping:5`

Pings a drive.

## Remarks

The [IVdsMaintenance::StartMaintenance](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsmaintenance-startmaintenance), [IVdsMaintenance::StopMaintenance](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsmaintenance-stopmaintenance), and [IVdsMaintenance::PulseMaintenance](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsmaintenance-pulsemaintenance) methods pass a **VDS_MAINTENANCE_OPERATION** value as an argument to specify operation details.

**Note** Additional constants might be added to the **VDS_MAINTENANCE_OPERATION** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_MAINTENANCE_OPERATION** enumeration constant.

## See also

[IVdsMaintenance::PulseMaintenance](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsmaintenance-pulsemaintenance)

[IVdsMaintenance::StartMaintenance](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsmaintenance-startmaintenance)

[IVdsMaintenance::StopMaintenance](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsmaintenance-stopmaintenance)

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)