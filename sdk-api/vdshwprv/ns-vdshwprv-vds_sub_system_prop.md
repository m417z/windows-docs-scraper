# VDS_SUB_SYSTEM_PROP structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the
properties of a [subsystem object](https://learn.microsoft.com/windows/desktop/VDS/subsystem-object).

## Members

### `id`

The GUID of the subsystem object.

### `pwszFriendlyName`

The name of the subsystem, typically a brand name and a model name; a zero-terminated, human-readable
string.

### `pwszIdentification`

The subsystem identifier; a zero-terminated, human-readable string.

### `ulFlags`

A bitmask of one or more
[VDS_SUB_SYSTEM_FLAG](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_sub_system_flag) enumeration values.

### `ulStripeSizeFlags`

The set of stripe sizes supported by a provider for striped volumes and/or LUNs. A stripe size must be a
power of 2. Each bit in the 32-bit integer represents a size, in bytes. For example, if the *n*th
bit is set, then VDS supports stripe size of 2^*n*. Thus, bits 0 through 31 can specify
2^0 through 2^31.

### `status`

A [VDS_SUB_SYSTEM_STATUS](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_sub_system_status) enumeration value that specifies the status of the subsystem object.

### `health`

A
[VDS_HEALTH](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_health) enumeration value that specifies the health state of the subsystem. The following are the valid values for this member.

#### VDS_H_UNKNOWN (0)

#### VDS_H_HEALTHY (1)

#### VDS_H_FAILED (8)

#### VDS_H_DEGRADED (11)

### `sNumberOfInternalBuses`

The number of buses (or "channels") that the subsystem contains.

### `sMaxNumberOfSlotsEachBus`

The maximum number of slots that each of the buses can include. Each slot can accommodate one drive. The subsystem
model assumes that each bus has the same maximum number of slots.

### `sMaxNumberOfControllers`

The maximum number of controllers that the subsystem can contain.

### `sRebuildPriority`

The rebuild priority of the LUNs that belong to the subsystem. This value can range from 0 (lowest priority) through 15 (highest priority).

##### - health.VDS_H_DEGRADED (11)

##### - health.VDS_H_FAILED (8)

##### - health.VDS_H_HEALTHY (1)

##### - health.VDS_H_UNKNOWN (0)

## Remarks

The [IVdsSubSystem::GetProperties](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdssubsystem-getproperties)
method returns this structure to report the properties of a [subsystem object](https://learn.microsoft.com/windows/desktop/VDS/subsystem-object).

## See also

[IVdsSubSystem::GetProperties](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdssubsystem-getproperties)

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)

[VDS_HEALTH](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_health)

[VDS_SUB_SYSTEM_STATUS](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_sub_system_status)