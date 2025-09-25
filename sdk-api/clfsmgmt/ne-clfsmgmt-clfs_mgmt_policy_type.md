# CLFS_MGMT_POLICY_TYPE enumeration

## Description

The **CLFS_MGMT_POLICY_TYPE** enumeration lists the valid policy types.

## Constants

### `ClfsMgmtPolicyMaximumSize:0x0`

Specifies the maximum size of the log.

### `ClfsMgmtPolicyMinimumSize`

Specifies the minimum size of the log.

### `ClfsMgmtPolicyNewContainerSize`

Specifies the size of a new container.

### `ClfsMgmtPolicyGrowthRate`

Controls the rate of growth of the log.

### `ClfsMgmtPolicyLogTail`

Controls the amount of space that [LOG_TAIL_ADVANCE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/clfsmgmtw32/nc-clfsmgmtw32-plog_tail_advance_callback) requests.

### `ClfsMgmtPolicyAutoShrink`

Controls the percentage of containers that are removed if the log is set to autogrow.

### `ClfsMgmtPolicyAutoGrow`

Indicates if the log should automatically shrink or grow.

### `ClfsMgmtPolicyNewContainerPrefix`

Controls the prefix given to a new container.

### `ClfsMgmtPolicyNewContainerSuffix`

Controls the suffix given to a new container.

### `ClfsMgmtPolicyNewContainerExtension`

Controls the extension given to a new container.

### `ClfsMgmtPolicyInvalid`

## See also

[CLFS_MGMT_POLICY](https://learn.microsoft.com/windows/desktop/api/clfsmgmt/ns-clfsmgmt-clfs_mgmt_policy)