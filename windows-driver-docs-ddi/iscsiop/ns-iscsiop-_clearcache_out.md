# _ClearCache_OUT structure

## Description

The ClearCache_OUT structure holds the output data for the [ClearCache](https://learn.microsoft.com/windows-hardware/drivers/storage/clearcache) method.

## Members

### `Status`

On output from **ClearCache**, the status of the **ClearCache** operation. For a list of status qualifiers, see [ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers).

## Remarks

You must implement this method.

## See also

[ClearCache](https://learn.microsoft.com/windows-hardware/drivers/storage/clearcache)

[ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers)

[MSiSCSI_SecurityConfigOperations WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-securityconfigoperations-wmi-class)