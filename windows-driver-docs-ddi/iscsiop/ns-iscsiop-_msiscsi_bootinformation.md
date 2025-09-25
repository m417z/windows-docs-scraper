# _MSiSCSI_BootInformation structure

## Description

The MSiSCSI_BootInformation structure is used with the [MSiSCSI_BootInformation WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-bootinformation-wmi-class) to expose information about the node that contains the target boot device.

## Members

### `NodeName`

The name of the initiator node that contains the boot device.

### `SharedSecretLength`

The length, in bytes, of the shared secret for the initiator node.

### `SharedSecret`

The shared secret for the initiator node.

## Remarks

You must implement this class if the adapter supports iSCSI boot.

## See also

[MSiSCSI_BootInformationWMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-bootinformation-wmi-class)