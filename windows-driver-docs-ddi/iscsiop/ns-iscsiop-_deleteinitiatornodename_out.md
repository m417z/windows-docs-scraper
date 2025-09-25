# _DeleteInitiatorNodeName_OUT structure

## Description

The DeleteInitiatorNodeName_OUT structure holds the output data for the [DeleteInitiatorNodeName](https://learn.microsoft.com/windows-hardware/drivers/storage/deleteinitiatornodename) method.

## Members

### `Status`

The status of the **DeleteInitiatorNodeName** operation. For a list of status qualifiers, see [ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers).

## Remarks

It is optional that you implement this method.

## See also

[DeleteInitiatorNodeName](https://learn.microsoft.com/windows-hardware/drivers/storage/deleteinitiatornodename)

[DeleteInitiatorNodeName_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_deleteinitiatornodename_in)

[ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers)