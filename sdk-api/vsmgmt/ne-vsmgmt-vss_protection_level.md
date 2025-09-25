# VSS_PROTECTION_LEVEL enumeration

## Description

Defines the set of volume shadow copy protection levels.

## Constants

### `VSS_PROTECTION_LEVEL_ORIGINAL_VOLUME:0`

Specifies that I/O to the original volume must be maintained at the expense of shadow copies. This is the default protection level. Shadow copies might be deleted if both of the following conditions occur:

* A write to the original volume occurs.
* The integrity of the shadow copy cannot be maintained for some reason, such as a failure to write to the shadow copy storage area or a failure to allocate sufficient memory.

### `VSS_PROTECTION_LEVEL_SNAPSHOT`

Specifies that shadow copies must be maintained at the expense of I/O to the original volume. This protection level is called "shadow copy protection mode." All I/O to the original volume will fail if both of the following conditions occur:

* A write to the original volume occurs.
* The corresponding write to the shadow copy storage area cannot be completed for some reason, such as a failure to write to the shadow copy storage area or a failure to allocate sufficient memory.

## Remarks

When a volume is in shadow copy protection mode, requesters must set shadow copy storage area (diff area) associations using the [IVssDifferentialSoftwareSnapshotMgmt::AddDiffArea](https://learn.microsoft.com/windows/desktop/api/vsmgmt/nf-vsmgmt-ivssdifferentialsoftwaresnapshotmgmt-adddiffarea) method.

## See also

[IVssDifferentialSoftwareSnapshotMgmt3](https://learn.microsoft.com/windows/desktop/api/vsmgmt/nn-vsmgmt-ivssdifferentialsoftwaresnapshotmgmt3)

[IVssDifferentialSoftwareSnapshotMgmt3::GetVolumeProtectLevel](https://learn.microsoft.com/windows/desktop/api/vsmgmt/nf-vsmgmt-ivssdifferentialsoftwaresnapshotmgmt3-getvolumeprotectlevel)

[IVssDifferentialSoftwareSnapshotMgmt3::SetVolumeProtectLevel](https://learn.microsoft.com/windows/desktop/api/vsmgmt/nf-vsmgmt-ivssdifferentialsoftwaresnapshotmgmt3-setvolumeprotectlevel)

[VSS_PROTECTION_FAULT](https://learn.microsoft.com/windows/desktop/api/vsmgmt/ne-vsmgmt-vss_protection_fault)

[VSS_VOLUME_PROTECTION_INFO](https://learn.microsoft.com/windows/desktop/api/vsmgmt/ns-vsmgmt-vss_volume_protection_info)