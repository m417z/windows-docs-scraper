# VSS_COMPONENT_FLAGS enumeration

## Description

The **VSS_COMPONENT_FLAGS** enumeration is
used by writers to indicate support for
[auto-recovery](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-a). These
values are used in the **dwComponentFlags** member of
the [VSS_COMPONENTINFO](https://learn.microsoft.com/windows/desktop/api/vsbackup/ns-vsbackup-vss_componentinfo) structure and the
*dwComponentFlags* parameter of
the [IVssCreateWriterMetadata::AddComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-addcomponent) method.

## Constants

### `VSS_CF_BACKUP_RECOVERY:0x00000001`

The writer will need write access to this component after the shadow copy has been created.

This flag can be used together with the **VSS_VOLSNAP_ATTR_TRANSPORTABLE** value of the [_VSS_VOLUME_SNAPSHOT_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_volume_snapshot_attributes) enumeration if the VSS hardware provider supports LUN masking.**Windows Vista and Windows Server 2003 with SP1:** This flag is incompatible with **VSS_VOLSNAP_ATTR_TRANSPORTABLE**.

This flag is not supported for express writers.

### `VSS_CF_APP_ROLLBACK_RECOVERY:0x00000002`

If this is a rollback shadow copy
(see the **VSS_VOLSNAP_ATTR_ROLLBACK_RECOVERY** value of the [_VSS_VOLUME_SNAPSHOT_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_volume_snapshot_attributes) enumeration), the writer for this
component will need write access to this component after the shadow copy has been created.

This flag can be used together with the **VSS_VOLSNAP_ATTR_TRANSPORTABLE** value of the [_VSS_VOLUME_SNAPSHOT_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_volume_snapshot_attributes) enumeration if the VSS hardware provider supports LUN masking.**Windows Vista and Windows Server 2003 with SP1:** This flag is incompatible with **VSS_VOLSNAP_ATTR_TRANSPORTABLE**.

This flag is not supported for express writers.

### `VSS_CF_NOT_SYSTEM_STATE:0x00000004`

This component is not part of system state.

**Windows Server 2003 with SP1:** This value is not supported until Windows Vista.

## See also

[IVssCreateWriterMetadata::AddComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-addcomponent)

[VSS_BACKUP_SCHEMA](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_backup_schema)

[VSS_COMPONENTINFO](https://learn.microsoft.com/windows/desktop/api/vsbackup/ns-vsbackup-vss_componentinfo)

[VSS_USAGE_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_usage_type)