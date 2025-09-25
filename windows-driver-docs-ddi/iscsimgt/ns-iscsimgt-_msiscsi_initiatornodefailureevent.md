# _MSiSCSI_InitiatorNodeFailureEvent structure

## Description

The MSiSCSI_InitiatorNodeFailureEvent structure is used to report an event when a node failure occurs.

## Members

### `FailureTime`

A timestamp that indicates when the node failure occurred.

### `FailureType`

The type of node failure. This member can have the following integer values, which are defined in a ValueMap in *Mgmt.mof*.

| Value | Failure type |
| --- | --- |
| LoginOtherFail | The logon failed for unspecified reasons. |
| LoginAuthFail | The logon failed, because the initiator and target do not have compatible authentication algorithms. |
| LoginAuthenticateFail | The logon failed, because the credentials of the initiator and target do not match and the initiator could not authenticate the target. |
| LoginNegotiateFail | The logon failed, because the initiator could not successfully negotiate a connection with the target. |
| LogoutOthers | The logout failed due to other reasons. |

### `TargetFailureName`

A wide character string that specifies the name of the target that a logon or logoff failed for.

### `TargetFailureAddr`

A [ISCSI_IP_Address](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_ip_address) structure that specifies the IP address of the target that a logon or logoff failed for.

## Remarks

It is optional that you implement this class.

## See also

[ISCSI_IP_Address](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_ip_address)

[MSiSCSI_InitiatorNodeFailureEvent WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-initiatornodefailureevent-wmi-class)