# _MSiSCSI_InitiatorLoginStatistics structure

## Description

The MSiSCSI_InitiatorLoginStatistics structure is used by iSCSI initiators to report logon statistics.

## Members

### `UniqueAdapterId`

A 64-bit integer that uniquely identifies an HBA initiator and a loaded instance of a storage miniport driver that manages the HBA. The initiator should use the address of the adapter extension or another address that the device driver owns to construct this identifier (ID). The initiator reports this value in the **UniqueAdapterId** member of the [MSiSCSI_HBAInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsimgt/ns-iscsimgt-_msiscsi_hbainformation) structure.

### `LoginAcceptRsps`

The number of login accept responses.

### `LoginOtherFailRsps`

The number of failed responses.

### `LoginRedirectRsps`

The number of redirect responses.

### `LoginAuthFailRsps`

The number of logon responses that failed because the initiator and target did not have compatible authentication algorithms.

### `LoginAuthenticateFails`

The number of logons that failed because of a target authentication failure (the initiator and target did not have matching credentials).

### `LoginNegotiateFails`

The number of logons that failed because of negotiation failures.

### `LogoutNormals`

The number of logoff PDUs with a reason code of 0.

### `LogoutOtherCodes`

The number of logoff PDUs with a status code other than 0.

### `LoginFailures`

The number of times that a logon attempt by the initiator has failed.

## Remarks

It is optional that you implement this class.

## See also

[MSiSCSI_HBAInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsimgt/ns-iscsimgt-_msiscsi_hbainformation)

[MSiSCSI_InitiatorLoginStatistics WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-initiatorloginstatistics-wmi-class)