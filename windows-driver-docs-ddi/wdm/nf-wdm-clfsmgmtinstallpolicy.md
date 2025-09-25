# ClfsMgmtInstallPolicy function

## Description

The **ClfsMgmtInstallPolicy** routine adds a [CLFS_MGMT_POLICY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_clfs_mgmt_policy) structure to a physical log.

## Parameters

### `LogFile` [in]

A pointer to a [LOG_FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) structure that represents the CLFS log that this instance of the **CLFS_MGMT_POLICY** structure will apply to. The policy applies to all streams within the log, even if a single stream within the log was specified.

### `Policy` [in]

A pointer to a [CLFS_MGMT_POLICY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_clfs_mgmt_policy) structure that contains the policy to be installed.

### `PolicyLength` [in]

The length, in bytes, of the structure pointed to by the *Policy* parameter.

## Return value

The **ClfsMgmtInstallPolicy** routine returns one of the following NTSTATUS values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The policy has been installed. |
| **STATUS_INVALID_PARAMETER_1** | A **NULL** value was supplied for the *LogFile* parameter. |
| **STATUS_INVALID_PARAMETER_2** | A **NULL** value was supplied for the *Policy* parameter. |
| **STATUS_INVALID_PARAMETER_3** | The value of the *PolicyLength* parameter is less than the size of an instance of the [CLFS_MGMT_POLICY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_clfs_mgmt_policy) structure. |
| **STATUS_NOT_SUPPORTED** | The **PolicyFlags** member of the **CLFS_MGMT_POLICY_STRUCTURE** pointed to by the *Policy* parameter specifies any flag other than LOG_POLICY_OVERWRITE. |
| **STATUS_INVALID_PARAMETER** | One of the following conditions is true:<br><br>* The *Policy* parameter's **Version** member is not equal to CLFS_MGMT_POLICY_VERSION.<br>* The value of the *Policy* parameter is equal to **ClfsMgmtPolicyInvalid**.<br>* The *Policy* parameter's **PolicyFlags** member specifies any flag other than LOG_POLICY_OVERWRITE. |
| **STATUS_LOG_POLICY_ALREADY_INSTALLED** | The log already has a policy of this type, and the LOG_POLICY_OVERWRITE flag is not set. |
| **STATUS_INSUFFICIENT_RESOURCES** | There is insufficient memory to complete the operation. |

This routine might also return other [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

Policies are volatile. When all handles to the log are closed, the policies will be lost. You should install policies each time you register the first client.

You should only register a **CLFS_MGMT_POLICY** structure whose **PolicyType** member is equal to **ClfsMgmtPolicyNewContainerSize** before the first container in the log is created. Any subsequent registrations are ignored.

The log policy that is installed applies to the physical log, even if the *LogFile* parameter specifies a log stream.

## See also

[CLFS_MGMT_POLICY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_clfs_mgmt_policy)