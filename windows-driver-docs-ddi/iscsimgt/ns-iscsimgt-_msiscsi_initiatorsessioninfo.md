# _MSiSCSI_InitiatorSessionInfo structure

## Description

The MSiSCSI_InitiatorSessionInfo structure contains information about a collection of sessions that belong to the indicated HBA initiator.

## Members

### `UniqueAdapterId`

A 64-bit integer that uniquely identifies an HBA initiator and a loaded instance of a storage miniport driver that manages the HBA. The initiator should use the address of the adapter extension or another address that the device driver owns to construct this identifier (ID). The initiator reports this value in the **UniqueAdapterId** member of the [MSiSCSI_HBAInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsimgt/ns-iscsimgt-_msiscsi_hbainformation) structure.

### `SessionCount`

The number of sessions that have been established with the provided adapter ID.

### `SessionsList`

A variable length array of [ISCSI_SessionStaticInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsimgt/ns-iscsimgt-_iscsi_sessionstaticinfo) structures, which describe the static information that is associated with a session.

## Remarks

You must implement this class.

## See also

[ISCSI_SessionStaticInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsimgt/ns-iscsimgt-_iscsi_sessionstaticinfo)

[MSiSCSI_HBAInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsimgt/ns-iscsimgt-_msiscsi_hbainformation)

[MSiSCSI_InitiatorSessionInfo WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-initiatorsessioninfo-wmi-class)