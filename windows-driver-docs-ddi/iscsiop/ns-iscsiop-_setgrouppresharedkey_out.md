# _SetGroupPresharedKey_OUT structure

## Description

The SetGroupPresharedKey_OUT structure holds the output data for the [SetGroupPresharedKey](https://learn.microsoft.com/windows-hardware/drivers/storage/setgrouppresharedkey) method.

## Members

### `Status`

On output, the status of the **SetGroupPresharedKey** operation. For a list of status qualifiers, see [ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers).

## Remarks

You must implement this method.

## See also

[ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers)

[SetGroupPresharedKey](https://learn.microsoft.com/windows-hardware/drivers/storage/setgrouppresharedkey)

[SetGroupPresharedKey_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_setgrouppresharedkey_in)