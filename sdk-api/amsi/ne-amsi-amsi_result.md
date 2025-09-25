# AMSI_RESULT enumeration

## Description

The **AMSI_RESULT** enumeration specifies the types of results returned by scans.

## Constants

### `AMSI_RESULT_CLEAN`

Known good. No detection found, and the result is likely not going to change after a future definition update.

### `AMSI_RESULT_NOT_DETECTED`

No detection found, but the result might change after a future definition update.

### `AMSI_RESULT_BLOCKED_BY_ADMIN_START`

Administrator policy blocked this content on this machine (beginning of range).

### `AMSI_RESULT_BLOCKED_BY_ADMIN_END`

Administrator policy blocked this content on this machine (end of range).

### `AMSI_RESULT_DETECTED`

Detection found. The content is considered malware and should be blocked.

## Remarks

The antimalware provider may return a result between 1 and 32767, inclusive, as an estimated risk level. The larger the result, the riskier it is to continue with the content. These values are provider specific, and may indicate a malware family or ID.

Results within the range of **AMSI_RESULT_BLOCKED_BY_ADMIN_START** and **AMSI_RESULT_BLOCKED_BY_ADMIN_END** values (inclusive) are officially blocked by the admin specified policy. In these cases, the script in question will be blocked from executing. The range is large to accommodate future additions in functionality.

Any return result equal to or larger than 32768 is considered malware, and the content should be blocked. An app should use [AmsiResultIsMalware](https://learn.microsoft.com/windows/desktop/api/amsi/nf-amsi-amsiresultismalware) to determine if this is the case.