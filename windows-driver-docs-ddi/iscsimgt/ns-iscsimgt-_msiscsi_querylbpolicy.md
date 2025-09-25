# _MSiSCSI_QueryLBPolicy structure

## Description

This MSiSCSI_QueryLBPolicy method returns the MCS load balancing policy for each information if any that has been set across different iSCSI session.

## Members

### `UniqueAdapterId`

This is a unique connection identifier that the initiator uses to identify a connection. The [LoginToTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logintotarget) and [AddConnectionToSession](https://learn.microsoft.com/windows-hardware/drivers/storage/addconnectiontosession) methods both return this value in the UniqueConnectionId parameter.

### `Reserved`

Reserved for Microsoft use only.

### `SessionCount`

This specifies the number of active sessions for this adapter ID.

### `LoadBalancePolicies`

This is an enumeration that contains information required to set the load balance policy. For more information about how to set the load balance policy, see [ISCSI_Supported_LB_Policies](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsimgt/ns-iscsimgt-_iscsi_supported_lb_policies). There will be as many of these structures as the number of sessions available for this adapter.

## Remarks

You must implement this class only if the adapter supports MCS. Otherwise, it is optional.

## See also

[AddConnectionToSession](https://learn.microsoft.com/windows-hardware/drivers/storage/addconnectiontosession)

[ISCSI_Supported_LB_Policies](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsimgt/ns-iscsimgt-_iscsi_supported_lb_policies)

[LoginToTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logintotarget)