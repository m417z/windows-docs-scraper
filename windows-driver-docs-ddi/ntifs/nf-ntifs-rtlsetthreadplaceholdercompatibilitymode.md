# RtlSetThreadPlaceholderCompatibilityMode function

## Description

**RtlSetThreadPlaceholderCompatibilityMode** sets the placeholder compatibility mode for the current thread. This allows a thread to explicitly request that placeholder files be either disguised or exposed, overriding the application’s default mode for that thread only.

## Parameters

### `Mode` [in]

Specifies the placeholder compatibility mode to set.

## Return value

Returns the thread's previous placeholder compatibility mode. If there was an error it returns a negative value. It can be one of the following values:

| Compatibility Mode | Value |
| --- | --- |
| PHCM_APPLICATION_DEFAULT | 0 |
| PHCM_DISGUISE_PLACEHOLDER | 1 |
| PHCM_EXPOSE_PLACEHOLDERS | 2 |
| PHCM_MAX | 2 |
| PHCM_ERROR_INVALID_PARAMETER | -1 |
| PHCM_ERROR_NO_TEB | -2 |

## Remarks

When placeholders are exposed, characteristics such as the presence of a reparse point, the sparse bit, and the offline bit are plainly visible through directory enumeration and other types of file information queries. When placeholders are disguised, these details are completely hidden, making the file look like a normal file.

Most Windows applications see exposed placeholders by default. For compatibility reasons, Windows may decide that certain applications see disguised placeholders by default.

## See also

[RtlQueryProcessPlaceholderCompatibilityMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlqueryprocessplaceholdercompatibilitymode)

[RtlQueryThreadPlaceholderCompatibilityMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlquerythreadplaceholdercompatibilitymode)

[RtlSetProcessPlaceholderCompatibilityMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlsetprocessplaceholdercompatibilitymode)