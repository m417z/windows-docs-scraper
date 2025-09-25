# _MSiSCSI_InitiatorInstanceFailureEvent structure

## Description

The MSiSCSI_InitiatorInstanceFailureEvent structure is used to report an event when an initiator instance failure occurs.

## Members

### `FailureType`

A [ISCSI_INITIATOR_FAILURE_TYPE_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-initiator-failure-type-qualifiers) value that indicates why the initiator instance failed.

### `RemoteNodeName`

The name of the target that is associated with the initiator instance that is reporting a failure.

## Remarks

We recommend that you implement this class.

## See also

[ISCSI_INITIATOR_FAILURE_TYPE_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-initiator-failure-type-qualifiers)

[MSiSCSI_InitiatorInstanceFailureEvent WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-initiatorinstancefailureevent-wmi-class)