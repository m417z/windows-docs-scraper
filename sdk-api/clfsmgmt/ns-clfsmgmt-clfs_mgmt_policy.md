# CLFS_MGMT_POLICY structure

## Description

The **CLFS_MGMT_POLICY** structure specifies a Common Log File System (CLFS) management policy. The **PolicyType** member specifies the members used for a policy.

## Members

### `Version`

Specifies the version of the log manager headers that the application is compiled with.

Set this to CLFS_MGMT_POLICY_VERSION.

### `LengthInBytes`

 Specifies the length of the entire structure.

### `PolicyFlags`

Reserved. Specify zero.

### `PolicyType`

Specifies the members used for a specific policy. Valid values are specified by [CLFS_MGMT_POLICY_TYPE](https://learn.microsoft.com/windows/desktop/api/clfsmgmt/ne-clfsmgmt-clfs_mgmt_policy_type).

### `PolicyParameters`

Specifies the specific policy this structure describes.

### `PolicyParameters.MaximumSize`

Specifies the maximum size of a log.

### `PolicyParameters.MaximumSize.Containers`

Specifies the maximum size of the log as a number of containers. There is no default maximum value.

### `PolicyParameters.MinimumSize`

Specifies the minimum size of a log.

### `PolicyParameters.MinimumSize.Containers`

Specifies the minimum size of the log as a number of containers. The minimum size is two (2) containers.

### `PolicyParameters.NewContainerSize`

Controls the size of a new container.

### `PolicyParameters.NewContainerSize.SizeInBytes`

Specifies the size, in bytes, of any new containers created.

### `PolicyParameters.GrowthRate`

Controls the rate of growth of a log. The growth rate can be either a relative percentage or an absolute number of containers added, but not both. Valid values are zero (0) and greater. Specify zero (0) to indicate that the log is not to grow in size.

### `PolicyParameters.GrowthRate.AbsoluteGrowthInContainers`

Specifies the growth rate as an absolute number of containers. The default value of this member is two (2).

### `PolicyParameters.GrowthRate.RelativeGrowthPercentage`

Specifies the growth rate as a relative percentage. There is no default value for this member.

### `PolicyParameters.LogTail`

Controls the amount of space that [LOG_TAIL_ADVANCE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/clfsmgmtw32/nc-clfsmgmtw32-plog_tail_advance_callback) requests. The value is either a relative percentage or an absolute number of bytes, but not both. The value is always rounded up to the nearest container. Specify zero to indicate that no action is taken to advance the base log tail.

### `PolicyParameters.LogTail.MinimumAvailablePercentage`

Specifies the amount of space that is requested as a percentage of the entire log. The minimum amount requested frees up space in a container.

### `PolicyParameters.LogTail.MinimumAvailableContainers`

Specifies the amount of space that is requested as an absolute number of containers.

### `PolicyParameters.AutoShrink`

Controls the timing of the log-shrinking feature. This value represents the percent of free space that must exist to trigger the auto-shrink operation. The log cannot be shrunk to a size smaller than the value specified by the **ClfsMgmtPolicyMinimumSize** policy.

### `PolicyParameters.AutoShrink.Percentage`

Specifies the percentage to shrink the log by. There is no default value.

### `PolicyParameters.AutoGrow`

Controls the auto-grow feature. If auto-grow is enabled, the log grows according to the value of the **GrowthRate** member, and is limited by the value of the **MaximumSize** member when the log reaches a state where one or no containers are free.

### `PolicyParameters.AutoGrow.Enabled`

Specifies whether the auto-grow policy is enabled. Specify zero to disable the auto-grow policy. The default is disabled.

### `PolicyParameters.NewContainerPrefix`

Controls the prefix that is given to a new container.

### `PolicyParameters.NewContainerPrefix.PrefixLengthInBytes`

Specifies the length of **PrefixString**.

### `PolicyParameters.NewContainerPrefix.PrefixString`

Specifies the prefix string. This string should include a full path to the directory where the containers are created, and a prefix for the container name.

The default path to the container is the directory that contains the base log. The default value is "Container". The log container is created with the name <Name of Log><Default Prefix><Number>.

**Note** The Common Log File System (CLFS) determines the value of <Number>.

### `PolicyParameters.NewContainerSuffix`

Controls the suffix that is given to a new container.

### `PolicyParameters.NewContainerSuffix.NextContainerSuffix`

Specifies the suffix given to a new container.

### `PolicyParameters.NewContainerExtension`

Controls the extension that is given to a new container.

### `PolicyParameters.NewContainerExtension.ExtensionLengthInBytes`

Specifies the length of **ExtensionString**.

### `PolicyParameters.NewContainerExtension.ExtensionString`

Specifies the extension given to the container file.

## See also

[CLFS_MGMT_POLICY_TYPE](https://learn.microsoft.com/windows/desktop/api/clfsmgmt/ne-clfsmgmt-clfs_mgmt_policy_type)