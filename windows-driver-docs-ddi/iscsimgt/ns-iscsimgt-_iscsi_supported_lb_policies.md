# _ISCSI_Supported_LB_Policies structure

## Description

The ISCSI_Supported_LB_Policies structure contains information about load balancing policies for multiple connections per session (MCS).

## Members

### `UniqueSessionId`

A 64-bit integer that uniquely identifies the session. The [LoginToTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logintotarget) and [AddConnectionToSession](https://learn.microsoft.com/windows-hardware/drivers/storage/addconnectiontosession) methods both return this value in their UniqueSessionId parameter. Do not confuse this value with the values in the ISID and TSID members.

### `LoadBalancePolicy`

This specifies the type of load balance policy that has been established on a multiconnection session.

| Type | Meaning |
| --- | --- |
| MSiSCSI_LB_FAILOVER | An alternate path is used only for failover. |
| MSiSCSI_LB_ROUND_ROBIN | I/O operations are scheduled to all active paths in a round-robin fashion. |
| MSiSCSI_LB_ROUND_ROBIN_WITH_SUBSET | I/O operations are scheduled to all paths within a subset in a round-robin fashion. |
| MSiSCSI_LB_DYN_LEAST_QUEUE_DEPTH | I/O operations are balanced across a set of paths based on the least queue depth mechanism (I/O is scheduled to the path with the fewest pending I/Os in its queue). |
| MSiSCSI_LB_WEIGHTED_PATHS | I/O operations are scheduled based on the weights assigned to a path by an administrator. |
| MSiSCSI_LB_VENDOR_SPECIFIC | Vendor-specific I/O policies are in effect. |

### `iSCSI_PathCount`

The number of paths associated with a target in the context of this session.

### `iSCSI_Paths`

Path information as shown in the [ISCSI_Path](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsimgt/ns-iscsimgt-_iscsi_path) structure.

## See also

[AddConnectionToSession](https://learn.microsoft.com/windows-hardware/drivers/storage/addconnectiontosession)

[LoginToTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logintotarget)