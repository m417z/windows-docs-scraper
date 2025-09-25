# _SetGenerationalGuid_OUT structure

## Description

The SetGenerationalGuid_OUT structure holds the output data for the [SetGenerationalGuid](https://learn.microsoft.com/windows-hardware/drivers/storage/setgenerationalguid) method.

## Members

### `Status`

On output, the status of the **SetGenerationalGuid** operation. For a list of status qualifiers, see [ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers).

## Remarks

You must implement this method.

## See also

[ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers)

[SetGenerationalGuid](https://learn.microsoft.com/windows-hardware/drivers/storage/setgenerationalguid)

[SetGenerationalGuid_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_setgenerationalguid_in)