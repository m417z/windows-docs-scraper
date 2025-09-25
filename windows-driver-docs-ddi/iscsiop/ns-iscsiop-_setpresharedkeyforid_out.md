# _SetPresharedKeyForId_OUT structure

## Description

The SetPresharedKeyForId_OUT structure holds the output data for the [SetPresharedKeyForId](https://learn.microsoft.com/windows-hardware/drivers/storage/setpresharedkeyforid) method.

## Members

### `Status`

On output, the status of the **SetPresharedKeyForId** operation. For a list of status qualifiers, see [ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers).

## Remarks

You must implement this method.

## See also

[ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers)

[SetPresharedKeyForId](https://learn.microsoft.com/windows-hardware/drivers/storage/setpresharedkeyforid)

[SetPresharedKeyForId_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_setpresharedkeyforid_in)