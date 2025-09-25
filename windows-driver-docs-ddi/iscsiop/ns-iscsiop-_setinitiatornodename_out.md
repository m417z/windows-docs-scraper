# _SetInitiatorNodeName_OUT structure

## Description

The SetInitiatorNodeName_OUT structure holds the output data for the [SetInitiatorNodeName](https://learn.microsoft.com/windows-hardware/drivers/storage/setinitiatornodename) method.

## Members

### `Status`

On output, the status of the **SetInitiatorNodeName** operation. For a list of status qualifiers, see [ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers).

## Remarks

It is optional that you implement this class.

## See also

[ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers)

[SetInitiatorNodeName](https://learn.microsoft.com/windows-hardware/drivers/storage/setinitiatornodename)

[SetInitiatorNodeName_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_setinitiatornodename_in)