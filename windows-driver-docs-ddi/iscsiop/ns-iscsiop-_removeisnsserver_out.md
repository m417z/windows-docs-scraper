# _RemoveiSNSServer_OUT structure

## Description

The RemoveiSNSServer_OUT structure holds the output data for the user-mode **RemoveISNSServer** method.

## Members

### `Status`

On output from **RemoveISNSServer**, the status of the operation. For a list of status qualifiers, see [ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers).

## Remarks

It is optional that you implement this method.

## See also

[ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers)

[RemoveiSNSServer_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_removeisnsserver_in)