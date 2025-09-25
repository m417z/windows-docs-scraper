# _AddConnectionToSession_OUT structure

## Description

The AddConnectionToSession_OUT structure holds output data for the [AddConnectionToSession](https://learn.microsoft.com/windows-hardware/drivers/storage/addconnectiontosession) method.

## Members

### `Status`

The status of the **AddConnectionToSession** operation. For a list of status qualifiers, see [ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers).

### `UniqueConnectionId`

A 64-bit integer that uniquely identifies the connection across the entire network.

## Remarks

The iSCSI service requires this method. It is optional that you implement this method.

## See also

[AddConnectionToSession](https://learn.microsoft.com/windows-hardware/drivers/storage/addconnectiontosession)

[AddConnectionToSession_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_addconnectiontosession_in)

[ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers)

[MSiSCSI_Operations WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-operations-wmi-class)