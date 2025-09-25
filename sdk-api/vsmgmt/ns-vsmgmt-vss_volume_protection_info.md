# VSS_VOLUME_PROTECTION_INFO structure

## Description

Contains information about a volume's shadow copy protection level.

## Members

### `m_protectionLevel`

A value from the [VSS_PROTECTION_LEVEL](https://learn.microsoft.com/windows/desktop/api/vsmgmt/ne-vsmgmt-vss_protection_level) enumeration that specifies the target protection level for the volume.

### `m_volumeIsOfflineForProtection`

TRUE if the volume is offline due to a protection fault, or **FALSE** otherwise.

### `m_protectionFault`

A value from the [VSS_PROTECTION_FAULT](https://learn.microsoft.com/windows/desktop/api/vsmgmt/ne-vsmgmt-vss_protection_fault) enumeration that describes the shadow copy protection fault that caused the volume to go offline.

### `m_failureStatus`

The internal failure status code.

### `m_volumeHasUnusedDiffArea`

TRUE if the volume has unused shadow copy storage area files, or **FALSE** otherwise.

### `m_reserved`

Reserved for system use.

## See also

[IVssDifferentialSoftwareSnapshotMgmt3](https://learn.microsoft.com/windows/desktop/api/vsmgmt/nn-vsmgmt-ivssdifferentialsoftwaresnapshotmgmt3)