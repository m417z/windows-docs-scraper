# SetLogFileSizeWithPolicy function

## Description

Adds or deletes containers from a log based on the state of the installed policies.

## Parameters

### `hLog` [in]

A handle to a log.

### `pDesiredSize` [in]

A pointer to a value that specifies the requested log size, expressed as one of the following values. For the actual resultant size, refer to the *pResultingSize* parameter.

| Value | Meaning |
| --- | --- |
| 0 | Enforce the minimum size policy.<br><br>If a minimum size policy is not installed, one of the following occurs:<br><br>* If the log has fewer than two containers, the log will be expanded to a size of two containers.<br>* If the log has two or more containers, no changes are made and the function call succeeds.<br><br>If a minimum size policy is installed, one of the following occurs:<br><br>* If the log has fewer than the minimum number of containers specified by the minimum size policy, the log expands to the policy-specified minimum number of containers.<br>* If the log has a number of containers greater than or equal to the minimum number of containers specified by the minimum size policy, no changes are made and the function call succeeds with no error.<br><br>For more information, see [InstallLogPolicy](https://learn.microsoft.com/windows/desktop/api/clfsmgmtw32/nf-clfsmgmtw32-installlogpolicy). |
| 1 | Not a valid value; the function call fails with **ERROR_INVALID_PARAMETER**. |
| 2–1023 | The desired size of the log, expressed as the number of containers. <br><br>If this number is smaller than the minimum number of containers specified by the installed policy, the function call fails with **ERROR_COULD_NOT_RESIZE_LOG**.<br><br>If this number is larger than the maximum number of containers specified by the installed policy, the log expands only as far as the policy-specified maximum number of containers, and the function succeeds with no error. |
| 1024–MAXULONGLONG | If no maximum size policy is installed, the function call fails with **ERROR_LOG_POLICY_CONFLICT**.<br><br>If a maximum size policy is installed, the log expands to the maximum number of containers specified by the maximum size policy and the function succeeds with no error. |

### `pResultingSize` [out]

A pointer to a valid ULONGLONG data variable, receives the number of containers in the resized log upon success.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

Containers are created using the same security attributes as the .blf file and are created within the context of the application, not the context of the owner of the .blf file. For more information about .blf files, see [Log Types](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/log-types). If containers are deleted, they are deleted using the security context of the calling application.

#### Examples

For an example that uses this function, see [Creating a Log File](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/creating-a-log-file).

## See also

[Creating a Log File](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/creating-a-log-file)

[InstallLogPolicy](https://learn.microsoft.com/windows/desktop/api/clfsmgmtw32/nf-clfsmgmtw32-installlogpolicy)

[Log Types](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/log-types)