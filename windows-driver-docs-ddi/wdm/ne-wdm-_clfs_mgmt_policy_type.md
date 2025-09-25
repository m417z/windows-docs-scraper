# _CLFS_MGMT_POLICY_TYPE enumeration

## Description

The **CLFS_MGMT_POLICY_TYPE** enumeration type identifies the type of a CLFS management policy.

## Constants

### `ClfsMgmtPolicyMaximumSize`

Indicates a policy that specifies the maximum size of a log.

### `ClfsMgmtPolicyMinimumSize`

Indicates a policy that specifies the minimum size of a log.

### `ClfsMgmtPolicyNewContainerSize`

Indicates a policy that specifies the size of new containers that are created.

### `ClfsMgmtPolicyGrowthRate`

Indicates a policy that specifies how many new containers will be added to the log each time the log grows.

### `ClfsMgmtPolicyLogTail`

Indicates a policy that specifies how much free space will be requested when a client is notified to move its log tail.

### `ClfsMgmtPolicyAutoShrink`

Indicates a policy that specifies when the log will shrink based on the percentage of the log that is free.

### `ClfsMgmtPolicyAutoGrow`

Indicates a policy that specifies whether the log should grow when fewer than two containers are free.

### `ClfsMgmtPolicyNewContainerPrefix`

Indicates a policy that specifies a prefix for the file name of each container, as well as the full path to the directory where the containers will be placed.

### `ClfsMgmtPolicyNewContainerSuffix`

Indicates a policy that specifies a number to use as the starting suffix for container file names.

### `ClfsMgmtPolicyNewContainerExtension`

Indicates a policy that specifies an extension for the file name of each container.

### `ClfsMgmtPolicyInvalid`

Reserved for internal use.

## Remarks

Each type of CLFS management policy corresponds to a specific interpretation of the [CLFS_MGMT_POLICY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_clfs_mgmt_policy) structure. The **PolicyType** member of the **CLFS_MGMT_POLICY** structure is a valid value of the **CLFS_MGMT_POLICY_TYPE** enumeration.

## See also

[CLFS_MGMT_POLICY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_clfs_mgmt_policy)