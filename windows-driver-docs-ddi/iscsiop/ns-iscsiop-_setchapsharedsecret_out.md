# _SetCHAPSharedSecret_OUT structure

## Description

The SetCHAPSharedSecret_OUT structure holds the output data for the [SetCHAPSharedSecret](https://learn.microsoft.com/windows-hardware/drivers/storage/setchapsharedsecret) method.

## Members

### `Status`

On output, the status of the **SetCHAPSharedSecret** operation. For a list of status qualifiers, see [ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers).

## Remarks

You must implement this method.

## See also

[ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers)

[SetCHAPSharedSecret](https://learn.microsoft.com/windows-hardware/drivers/storage/setchapsharedsecret)

[SetCHAPSharedSecret_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_setchapsharedsecret_in)