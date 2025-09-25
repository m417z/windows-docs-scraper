# _SetRADIUSSharedSecret_OUT structure

## Description

The SetRADIUSSharedSecret_OUT structure holds the output data for the [SetRADIUSSharedSecret](https://learn.microsoft.com/windows-hardware/drivers/storage/setradiussharedsecret) method.

## Members

### `Status`

On output, the status of the **SetRADIUSSharedSecret** operation. For a list of status qualifiers, see [ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers).

## Remarks

You must implement this method.

## See also

[ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers)

[SetRADIUSSharedSecret](https://learn.microsoft.com/windows-hardware/drivers/storage/setradiussharedsecret)

[SetRADIUSSharedSecret_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_setradiussharedsecret_in)