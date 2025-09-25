# VDS_LUN_PROP structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the properties of
a [LUN object](https://learn.microsoft.com/windows/desktop/VDS/lun-object).

## Members

### `id`

The GUID of the LUN object.

### `ullSize`

The size of the LUN, in bytes.

### `pwszFriendlyName`

The name of the LUN; a zero-terminated, human-readable string.

### `pwszIdentification`

The unique LUN identifier; a zero-terminated, human-readable string.

### `pwszUnmaskingList`

A list specifying the computers on the network to be granted access the LUN; a semicolon-delimited,
NULL-terminated, human-readable string.

If the value is "*", all computers on the network are to be granted
access to the LUN. If the value is "", no computers are to be granted access to the LUN.

**Note** In practice, if the value is "*", most hardware providers only grant the ports and initiators on the local computer access to the LUN.

If "*" or "" is specified, no other value can be specified.

For Fibre Channel networks and serial attached SCSI (SAS) networks, each entry is a 64-bit World-Wide Name (WWN) of each port to which the LUN is unmasked,
formatted as a hexadecimal string (16 characters long), most significant byte first. For
example, a WWN address of 01:23:45:67:89:AB:CD:EF is represented as "0123456789ABCDEF". For more information, see the T10 specifications for [Fibre Channel](https://t10.org/drafts.htm#FibreChannel) and [SAS](https://t10.org/drafts.htm#SCSI3_SAS).

For iSCSI networks, each entry is an iSCSI qualified name (IQN) of each initiator to which the LUN is unmasked. A LUN unmasked
to a particular initiator is considered to be associated with that initiator.

**Note** The unmasking list can contain the same WWN or IQN more than once. Duplicates are ignored.

### `ulFlags`

The LUN flags enumerated by [VDS_LUN_FLAG](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_lun_flag).

### `type`

The LUN type enumerated by [VDS_LUN_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_lun_type).

### `status`

The status of the LUN object enumerated by
[VDS_LUN_STATUS](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_lun_status).

### `health`

A
[VDS_HEALTH](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_health) enumeration value that specifies the health state of the LUN. The following are the valid values for this member.

#### VDS_H_UNKNOWN (0)

#### VDS_H_HEALTHY (1)

#### VDS_H_REBUILDING (2)

#### VDS_H_FAILING (4)

#### VDS_H_FAILING_REDUNDANCY (5)

#### VDS_H_FAILED_REDUNDANCY (6)

#### VDS_H_FAILED_REDUNDANCY_FAILING (7)

#### VDS_H_FAILED (8)

### `TransitionState`

The transition state of the LUN enumerated by
[VDS_TRANSITION_STATE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_transition_state).

### `sRebuildPriority`

The rebuild priority of the LUN object. A value between 0 (lowest priority) and 15 (highest priority).

##### - health.VDS_H_FAILED (8)

##### - health.VDS_H_FAILED_REDUNDANCY (6)

##### - health.VDS_H_FAILED_REDUNDANCY_FAILING (7)

##### - health.VDS_H_FAILING (4)

##### - health.VDS_H_FAILING_REDUNDANCY (5)

##### - health.VDS_H_HEALTHY (1)

##### - health.VDS_H_REBUILDING (2)

##### - health.VDS_H_UNKNOWN (0)

## Remarks

The [IVdsLun::GetProperties](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslun-getproperties) method returns
this structure to report the properties of a [LUN object](https://learn.microsoft.com/windows/desktop/VDS/lun-object).

## See also

[IVdsLun::GetProperties](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslun-getproperties)

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)

[VDS_HEALTH](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_health)

[VDS_LUN_STATUS](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_lun_status)

[VDS_LUN_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_lun_type)

[VDS_TRANSITION_STATE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_transition_state)