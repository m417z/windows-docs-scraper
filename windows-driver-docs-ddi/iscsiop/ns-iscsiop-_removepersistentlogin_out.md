# _RemovePersistentLogin_OUT structure

## Description

The RemovePersistentLogin_OUT structure holds the output data for the [RemovePersistentLogin](https://learn.microsoft.com/windows-hardware/drivers/storage/removepersistentlogin) method.

## Members

### `Status`

On output from **RemovePersistentLogin**, the status of the operation. For a list of status qualifiers, see [ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers).

## Remarks

You must implement this method.

## See also

[ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers)

[RemovePersistentLogin](https://learn.microsoft.com/windows-hardware/drivers/storage/removepersistentlogin)

[RemovePersistentLogin_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_removepersistentlogin_in)