# ClfsMgmtSetLogFileSize function

## Description

The **ClfsMgmtSetLogFileSize** routine adds containers to a log or deletes containers from a log.

## Parameters

### `LogFile` [in]

A pointer to a [LOG_FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) structure that represents the CLFS log, or a stream within the log, to which containers are being added or deleted.

### `NewSizeInContainers` [in]

A pointer to the requested log size. The caller sets this parameter to one of the following values.

| Value | Meaning |
| --- | --- |
| 0 | Enforce the minimum size policy. For more information about this policy, see [ClfsMgmtInstallPolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsmgmtinstallpolicy).<br><br>If a minimum size policy is not installed, one of the following occurs:<br><br>* If the log currently has less than 2 containers, the log will be expanded to a size of 2 containers.<br>* If the log currently has 2 or more containers, no changes are made and the call succeeds.<br><br>If a minimum size policy is installed, one of the following occurs:<br><br>* If the log currently has less than the minimum number of containers specified by the minimum size policy, the log expands to the policy-specified minimum number of containers.<br>* If the number of containers in the log is greater than or equal to the minimum number of containers specified by the minimum size policy, no changes are made and the call succeeds with no error. |
| 1 | Invalid value. The call fails and returns STATUS_INVALID_VALUE. |
| 2 to 1023 | The desired size of the log, expressed as the number of containers.<br><br>If this number is smaller than the minimum number of containers specified by the installed policy, the call fails with ERROR_COULD_NOT_RESIZE_LOG.<br><br>If this number is larger than the maximum number of containers specified by the installed policy, the log expands only as far as the policy-specified maximum number of containers, and the call succeeds with no error. |
| 1024 to MAXULONGLONG | If no maximum size policy is installed, the call fails and returns ERROR_LOG_POLICY_CONFLICT.<br><br>If a maximum size policy is installed, the log expands to the maximum number of containers specified by the maximum size policy and the call succeeds with no error. |

To determine the actual log size, which might be different from the requested size, use the *ResultingSizeInContainers* parameter.

### `ResultingSizeInContainers` [out]

A pointer to the resulting log size. If successful, the routine writes the actual size of the log, expressed as the number of containers in the log, to the location pointed to by this parameter.

### `CompletionRoutine` [in, optional]

 Not used. Set to NULL.

### `CompletionRoutineData` [in, optional]

 Not used. Set to NULL.

## Return value

The **ClfsMgmtSetLogFileSize** routine returns one of the following NTSTATUS values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The log file size has been set. The *ResultingSizeInContainers* parameter contains the current size of the log. |
| **STATUS_UNSUCCESSFUL** | CLFS management was not able to set the log file size. |
| **STATUS_INVALID_PARAMETER_1** | The value of the *LogFile* parameter is **NULL**, or the contents of the *NewSizeInContainers* parameter is 1. |
| **STATUS_INVALID_PARAMETER_2** | The value of the *NewSizeInContainers* parameter is **NULL**. |
| **STATUS_LOG_POLICY_INVALID** | There is a conflict between the maximum size and minimum size policies for the log. |
| **STATUS_COULD_NOT_RESIZE_LOG** | CLFS management could not delete enough containers to reach *NewSizeInContainers*. |
| **STATUS_LOG_POLICY_CONFLICT** | CLFS management could not add enough containers to the log to reach *NewSizeInContainers*. This might be due to a conflict with a policy that the client set. |

This routine might also return other [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

The **ClfsMgmtSetLogFileSize** routine is typically used only when a client starts or stops. Do not call the **ClfsMgmtSetLogFileSize** routine from within your [ClfsAdvanceTailCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pclfs_client_advance_tail_callback) function.

## See also

[CLFS_MGMT_POLICY_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_clfs_mgmt_policy_type)

[ClfsMgmtInstallPolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsmgmtinstallpolicy)