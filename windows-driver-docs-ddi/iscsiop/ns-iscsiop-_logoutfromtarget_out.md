# _LogoutFromTarget_OUT structure

## Description

The LogoutFromTarget_OUT structure holds the output data for the [LogoutFromTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logoutfromtarget) method.

## Members

### `Status`

On output from **LogoutFromTarget**, the status of the logoff operation. For a list of status qualifiers, see [ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers).

## Remarks

You must implement this method.

## See also

[ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers)

[LoginToTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logintotarget)

[LogoutFromTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logoutfromtarget)

[LogoutFromTarget_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_logoutfromtarget_in)

[MSiSCSI_Operations WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-operations-wmi-class)