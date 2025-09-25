# _MSiSCSI_TargetMappings structure

## Description

The MSiSCSI_TargetMappings structure contains a set of logical unit number (LUN) mappings that are associated with an initiator instance.

## Members

### `UniqueAdapterId`

A 64-bit integer that uniquely identifies an HBA initiator and a loaded instance of a storage miniport driver that manages the HBA. The initiator should use the address of the adapter extension or another address that the device driver owns to construct this identifier (ID). The initiator reports this value in the **UniqueAdapterId** member of the [MSiSCSI_HBAInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsimgt/ns-iscsimgt-_msiscsi_hbainformation) structure.

### `TargetMappingCount`

The number of mappings in the **TargetMappings** member.

### `Reserved`

Reserved for Microsoft use only.

### `TargetMappings`

A variable-length array of [ISCSI_TargetMapping](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_targetmapping) structures, each of which provides a list of LUN mappings that are associated with a particular iSCSI session that is associated with the adapter ID.

## Remarks

You must implement this class.

## See also

[ISCSI_TargetMapping](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_targetmapping)

[MSiSCSI_HBAInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsimgt/ns-iscsimgt-_msiscsi_hbainformation)

[MSiSCSI_TargetMappings WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-targetmappings-wmi-class)