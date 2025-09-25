# ClfsMgmtQueryPolicy function

## Description

The **ClfsMgmtQueryPolicy** routine retrieves a specific [CLFS_MGMT_POLICY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_clfs_mgmt_policy) structure for a log.

## Parameters

### `LogFile` [in]

A pointer to a [LOG_FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) structure that represents the CLFS log whose policy is being retrieved.

### `PolicyType` [in]

A value of the [CLFS_MGMT_POLICY_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_clfs_mgmt_policy_type) enumeration that identifies the type of policy to be retrieved.

### `Policy` [out]

An instance of the [CLFS_MGMT_POLICY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_clfs_mgmt_policy) structure that contains the policy.

### `PolicyLength` [out]

The length of the *Policy* parameter.

## Return value

The **ClfsMgmtQueryPolicy** routine returns one of the following NTSTATUS values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | CLFS management has retrieved the requested policy. |
| **STATUS_UNSUCCESSFUL** | CLFS management was not able to process the request. |
| **STATUS_INVALID_PARAMETER** | The value of the *PolicyType* parameter is not valid for the **CLFS_MGMT_POLICY_TYPE** enumeration. |
| **STATUS_INVALID_PARAMETER_1** | A **NULL** value was supplied for the *LogFile* parameter. |
| **STATUS_INVALID_PARAMETER_2** | The value of the *PolicyLength* parameter is less than the size of an instance of the **CLFS_MGMT_POLICY** structure. |
| **STATUS_INSUFFICIENT_RESOURCES** | There is insufficient memory to complete the operation. |
| **STATUS_LOG_POLICY_NOT_INSTALLED** | No policy of this type has been registered for the log file. |

This routine might also return other [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## See also

[CLFS_MGMT_POLICY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_clfs_mgmt_policy)

[CLFS_MGMT_POLICY_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_clfs_mgmt_policy_type)