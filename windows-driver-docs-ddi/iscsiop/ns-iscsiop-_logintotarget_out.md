# _LoginToTarget_OUT structure

## Description

The LoginToTarget_OUT structure holds the output data for the [LoginToTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logintotarget) method.

## Members

### `Status`

On output from **LoginToTarget**, the status of the **LoginToTarget** operation. For a list of status qualifiers, see [ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers).

### `UniqueSessionId`

A 64-bit integer that uniquely identifies the session. The [LoginToTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logintotarget) and [AddConnectionToSession](https://learn.microsoft.com/windows-hardware/drivers/storage/addconnectiontosession) methods both return this value in their *UniqueSessionId* parameter. The unique session identifier (ID) does not change until the initiator logs off of the session. The session ID that the iSCSI initiator service exposes to user-mode software is a 128-bit number. The top (most significant) 64 bits consist of a unique adapter ID that the initiator reports in the **UniqueAdapterId** member of the [MSiSCSI_HBAInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsimgt/ns-iscsimgt-_msiscsi_hbainformation) class. The lower (least significant) 64 bits correspond to the value in **UniqueSessionId**. When the service communicates with the adapter, the service uses the lower 64 bits (**UniqueSessionId**), while user-mode software uses all of the 128 bits to communicate with the iSCSI initiator service.

### `UniqueConnectionId`

On output from **LoginToTarget**, a 64-bit integer that uniquely identifies the connection. The connection ID that the iSCSI initiator service exposes to user-mode software is a 128-bit number. The top (most significant) 64 bits consist of a unique adapter ID that the initiator reports in the **UniqueAdapterId** member of the [MSiSCSI_HBAInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsimgt/ns-iscsimgt-_msiscsi_hbainformation) class. The lower (least significant) 64 bits correspond to the value in **UniqueConnectionId**. When the service communicates with the adapter, the service uses the lower 64 bits (**UniqueConnectionId**), while user-mode software uses all the 128 bits to communicate with the iSCSI initiator service.

## Remarks

You must implement this method.

## See also

[AddConnectionToSession](https://learn.microsoft.com/windows-hardware/drivers/storage/addconnectiontosession)

[ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers)

[LoginToTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logintotarget)

[LoginToTarget_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_logintotarget_in)

[MSiSCSI_HBAInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsimgt/ns-iscsimgt-_msiscsi_hbainformation)

[MSiSCSI_Operations WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-operations-wmi-class)