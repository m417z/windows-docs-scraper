# _AddiSNSServer_OUT structure

## Description

The AddiSNSServer_OUT structure holds the output data for the user-mode **AddISNSServer** method.

## Members

### `Status`

On output from **AddISNSServer**, the status of the **AddISNSServer** operation. For a list of status qualifiers, see [ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers).

## Remarks

It is optional that you implement this method.

## See also

[AddiSNSServer_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_addisnsserver_in)

[ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers)

[MSiSCSI_Operations WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-operations-wmi-class)