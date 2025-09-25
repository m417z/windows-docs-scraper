# _CLFS_MGMT_POLICY structure

## Description

The **CLFS_MGMT_POLICY** structure holds a description of a policy for managing a CLFS log.

## Members

### `Version`

The version of the **CLFS_MGMT_POLICY** structure. Set this to **CLFS_MGMT_POLICY_VERSION**.

### `LengthInBytes`

The length of the **CLFS_MGMT_POLICY** structure.

### `PolicyFlags`

The flags that apply to this instance of the **CLFS_MGMT_POLICY** structure. The only flag that has been implemented for this release is **LOG_POLICY_OVERWRITE**, which indicates that when the policy is installed, it will replace the policy of the same type, if such a policy already exists.

### `PolicyType`

A value of the [CLFS_MGMT_POLICY_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_clfs_mgmt_policy_type) enumeration that supplies the type of this instance of the **CLFS_MGMT_POLICY** structure.

### `PolicyParameters`

The union that provides the detailed information about this instance of the **CLFS_MGMT_POLICY** structure.

### `PolicyParameters.MaximumSize`

The structure that provides the detailed information about a policy whose **PolicyType** is **ClfsMgmtPolicyMaximumSize**.

### `PolicyParameters.MaximumSize.Containers`

The maximum number of containers that the log will use.

### `PolicyParameters.MinimumSize`

The structure that provides the detailed information about a policy whose **PolicyType** is **ClfsMgmtPolicyMinimumSize**.

### `PolicyParameters.MinimumSize.Containers`

The minimum number of containers that the log will use.

### `PolicyParameters.NewContainerSize`

The structure that provides the detailed information about a policy whose **PolicyType** is **ClfsMgmtPolicyNewContainerSize**.

### `PolicyParameters.NewContainerSize.SizeInBytes`

The size of each of the log's containers.

### `PolicyParameters.GrowthRate`

The structure that provides the detailed information about a policy whose **PolicyType** is **ClfsMgmtPolicyGrowthRate**.

### `PolicyParameters.GrowthRate.AbsoluteGrowthInContainers`

The number of containers that should be added when the size of the log is increased. If the **RelativeGrowthPercentage** member is nonzero, then **AbsoluteGrowthInContainers** must be zero.

### `PolicyParameters.GrowthRate.RelativeGrowthPercentage`

The percentage by which the log's size should increase when the log grows, expressed as a number between zero and 100. For example, if the log consisted of 32 containers and **RelativeGrowthPercentage** was ten, then, when the log needed to grow, it would grow by three (32 * 10 percent, rounded down to the nearest integer) containers. If the **AbsoluteGrowthInContainers** member is nonzero, then **RelativeGrowthPercentage** must be zero.

### `PolicyParameters.LogTail`

The structure that provides the detailed information about a policy whose **PolicyType** is **ClfsMgmtPolicyLogTail**.

### `PolicyParameters.LogTail.MinimumAvailablePercentage`

When CLFS management notifies the client to move its log tail, it will specify that the tail be moved to an LSN that leaves at least **MinimumAvailablePercentage** percent of the log free. If the **MinimumAvailableContainers** member is nonzero, then **MinimumAvailablePercentage** must be zero.

### `PolicyParameters.LogTail.MinimumAvailableContainers`

When CLFS management notifies the client to move its log tail, it will specify that the tail be moved to an LSN that leaves at least **MinimumAvailableContainers** containers free. If the **MinimumAvailablePercentage** member is nonzero, then **MinimumAvailableContainers** must be zero.

### `PolicyParameters.AutoShrink`

The structure that provides the detailed information about a policy whose **PolicyType** is **ClfsMgmtPolicyAutoShrink**.

### `PolicyParameters.AutoShrink.Percentage`

When the percentage of free space in the log reaches **Percentage**, the log will shrink. Percentage is expressed as a number between 0 and 100, so a value of 25 would mean 25 percent.

### `PolicyParameters.AutoGrow`

The structure that provides the detailed information about a policy whose **PolicyType** is **ClfsMgmtPolicyAutoGrow**.

### `PolicyParameters.AutoGrow.Enabled`

A numeric value that determines whether automatic log growth is enabled. Any nonzero value enables automatic growth.

### `PolicyParameters.NewContainerPrefix`

The structure that provides the detailed information about a policy whose **PolicyType** is **ClfsMgmtPolicyNewContainerPrefix**.

### `PolicyParameters.NewContainerPrefix.PrefixLengthInBytes`

The length, in bytes, of the **PrefixString** member.

### `PolicyParameters.NewContainerPrefix.PrefixString`

A wide-character string that contains the full path to the directory where the log's containers reside, as well as a prefix that will be used as part of the file name for each container in the log.

### `PolicyParameters.NewContainerSuffix`

The structure that provides the detailed information about a policy whose **PolicyType** is **ClfsMgmtPolicyNewContainerSuffix**.

### `PolicyParameters.NewContainerSuffix.NextContainerSuffix`

The number to use as the suffix of the file name for the next container in the log. To form the file name, the number is converted to a string of decimal digits and appended to the prefix string. The number is incremented for the file name of each subsequent container.

### `PolicyParameters.NewContainerExtension`

The structure that provides the detailed information about a policy whose **PolicyType** is **ClfsMgmtPolicyNewContainerExtension**.

### `PolicyParameters.NewContainerExtension.ExtensionLengthInBytes`

The length, in bytes, of the **ExtensionString** member.

### `PolicyParameters.NewContainerExtension.ExtensionString`

A wide-character string that contains the extension to the file name for each container in the log. Container file names are built using the format [prefix][suffix][.extension]. An extension is optional. The default extension is the empty string.

## Remarks

The way a **CLFS_MGMT_POLICY** structure is interpreted depends on the type of policy that the structure holds.

You can provide *policies* that specify how the log will be managed. Each policy is an instance of the **CLFS_MGMT_POLICY** structure, but the structure is interpreted differently depending on the policy type. CLFS uses the information that you provided in the policies to tailor how it manages the log.

When you create a **CLFS_MGMT_POLICY** structure whose **PolicyType** is **ClfsMgmtPolicyNewContainerPrefix**, be sure to allocate enough space to hold the **PolicyParameters.NewContainerPrefix.PrefixString** string.

You can only install a policy whose policy type specified in the **PolicyType** value is **ClfsMgmtPolicyNewContainerSize** before there are any containers in the log. You can change other policies after the log exists.

## See also

[CLFS_MGMT_POLICY_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_clfs_mgmt_policy_type)

[ClfsMgmtInstallPolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsmgmtinstallpolicy)

[ClfsMgmtQueryPolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsmgmtquerypolicy)

[ClfsMgmtRemovePolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsmgmtremovepolicy)