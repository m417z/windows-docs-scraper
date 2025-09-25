# RtlQueryThreadPlaceholderCompatibilityMode function

## Description

**RtlQueryThreadPlaceholderCompatibilityMode** returns the placeholder compatibility mode for the current thread.

## Return value

Returns the thread's placeholder compatibility mode. If there was an error it returns a negative value. It can be one of the following values:

| Compatibility Mode | Value |
| --- | --- |
| PHCM_APPLICATION_DEFAULT | 0 |
| PHCM_DISGUISE_PLACEHOLDER | 1 |
| PHCM_EXPOSE_PLACEHOLDERS | 2 |
| PHCM_MAX | 2 |
| PHCM_ERROR_INVALID_PARAMETER | -1 |
| PHCM_ERROR_NO_TEB | -2 |

## Remarks

This function is similar to [RtlQueryProcessPlaceholderCompatibilityMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlqueryprocessplaceholdercompatibilitymode), but performs at a thread level instead of a process level.

## See also

[RtlQueryProcessPlaceholderCompatibilityMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlqueryprocessplaceholdercompatibilitymode)

[RtlSetProcessPlaceholderCompatibilityMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlsetprocessplaceholdercompatibilitymode)

[RtlSetThreadPlaceholderCompatibilityMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlsetthreadplaceholdercompatibilitymode)