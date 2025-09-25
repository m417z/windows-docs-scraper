# _SetTunnelModeOuterAddress_OUT structure

## Description

The SetTunnelModeOuterAddress_OUT structure holds the output data for the [SetTunnelModeOuterAddress](https://learn.microsoft.com/windows-hardware/drivers/storage/settunnelmodeouteraddress) method.

## Members

### `Status`

On output, the status of the **SetTunnelModeOuterAddress** operation. For a list of status qualifiers, see [ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers).

## Remarks

You must implement this method.

## See also

[ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers)

[SetTunnelModeOuterAddress](https://learn.microsoft.com/windows-hardware/drivers/storage/settunnelmodeouteraddress)

[SetTunnelModeOuterAddress_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_settunnelmodeouteraddress_in)