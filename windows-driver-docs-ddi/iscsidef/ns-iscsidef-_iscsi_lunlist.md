# _ISCSI_LUNList structure

## Description

The ISCSI_LUNList structure defines a mapping between the LUN number that is used by the operating system and the LUN number that is configured in the iSCSI target.

## Members

### `TargetLUN`

A LUN that is globally valid anywhere in the network.

### `OSLUN`

The SCSI LUN (which is valid in the local operating system) that the remote LUN is mapped to.

### `Reserved`

Reserved for Microsoft use only.

## See also

[ISCSI_LUNList WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-lunlist-wmi-class)