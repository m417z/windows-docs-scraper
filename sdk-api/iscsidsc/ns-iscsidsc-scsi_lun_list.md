# SCSI_LUN_LIST structure

## Description

The **SCSI_LUN_LIST** structure is used to construct a list of logical unit numbers (LUNs) associated with target devices.

## Members

### `OSLUN`

The LUN assigned by the operating system to the target device when it was enumerated by the initiator Host Bus Adapter (HBA).

### `TargetLUN`

The LUN assigned by the target subsystem to the target device.

## See also

[ISCSI_TARGET_MAPPING](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_target_mappinga)