# _MSiSCSI_InitiatorInstanceStatistics structure

## Description

The MSiSCSI_InitiatorInstanceStatistics structure is used by iSCSI initiators to report initiator statistics.

## Members

### `UniqueAdapterId`

A 64-bit integer that uniquely identifies an HBA initiator and a loaded instance of a storage miniport driver that manages the HBA. The initiator should use the address of the adapter extension or another address that the device driver owns to construct this identifier (ID). The initiator reports this value in the **UniqueAdapterId** member of the [MSiSCSI_HBAInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsimgt/ns-iscsimgt-_msiscsi_hbainformation) structure. For more information about the class that generates MSiSCSI_HBAInformation, see [MSiSCSI_HBAInformation WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-hbainformation-wmi-class).

### `SessionDigestErrorCount`

The number of session digest errors.

### `SessionConnectionTimeoutErrorCount`

The number of session connection time-out errors.

### `SessionFormatErrorCount`

The number of session format errors.

### `SessionFailureCount`

The number of failed sessions that belong to the initiator instance that **UniqueAdapterId** specifies.

## Remarks

It is optional that you implement this class.

## See also

[MSiSCSI_HBAInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsimgt/ns-iscsimgt-_msiscsi_hbainformation)

[MSiSCSI_HBAInformation WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-hbainformation-wmi-class)

[MSiSCSI_InitiatorInstanceStatistics WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-initiatorinstancestatistics-wmi-class)