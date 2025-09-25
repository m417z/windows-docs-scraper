# _GetPresharedKeyForId_OUT structure

## Description

The GetPresharedKeyForId_OUT structure holds the output data for the [GetPresharedKeyForId](https://learn.microsoft.com/windows-hardware/drivers/storage/getpresharedkeyforid) method.

## Members

### `Status`

On output from **GetPresharedKeyForId**, the status of the **GetPresharedKeyForId** operation. For a list of status qualifiers, see [ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers).

### `SecurityFlags`

A bitwise OR of flags that indicate the security requirements of a target. For a list of possible values for this member, see [SECURITY_FLAG_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/security-flag-qualifiers).

## Remarks

You must initiate this method if the initiator supports IKE.

## See also

[GetPresharedKeyForId](https://learn.microsoft.com/windows-hardware/drivers/storage/getpresharedkeyforid)

[GetPresharedKeyForId_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_getpresharedkeyforid_in)

[ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers)

[MSiSCSI_SecurityConfigOperations WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-securityconfigoperations-wmi-class)

[SECURITY_FLAG_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/security-flag-qualifiers)