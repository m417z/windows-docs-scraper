# RtlQueryProcessPlaceholderCompatibilityMode function

## Description

 **RtlQueryProcessPlaceholderCompatibilityMode** returns the placeholder compatibility mode for the current process.

## Return value

This function returns the process's placeholder compatibility mode (PHCM_xxx), or a negative value on error (PCHM_ERROR_xxx). Contains one of the following values:

| Compatibility Mode | Value |
| --- | --- |
| PHCM_APPLICATION_DEFAULT | 0 |
| PHCM_DISGUISE_PLACEHOLDER | 1 |
| PHCM_EXPOSE_PLACEHOLDERS | 2 |
| PHCM_MAX | 2 |
| PHCM_ERROR_INVALID_PARAMETER | -1 |
| PHCM_ERROR_NO_TEB | -2 |

## Remarks

This function is similar to [RtlQueryThreadPlaceholderCompatibilityMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlquerythreadplaceholdercompatibilitymode), but performs at a process level instead of a thread level.

## See also

[RtlQueryThreadPlaceholderCompatibilityMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlquerythreadplaceholdercompatibilitymode)

[RtlSetProcessPlaceholderCompatibilityMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlsetprocessplaceholdercompatibilitymode)

[RtlSetThreadPlaceholderCompatibilityMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlsetthreadplaceholdercompatibilitymode)