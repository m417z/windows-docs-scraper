# IFsrmQuota::get_QuotaPeakUsage

## Description

[This property is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmquota) class.]

Retrieves the highest amount of disk space usage charged to this quota.

This property is read-only.

## Parameters

## Remarks

The value represents the highest amount of disk space charged to this quota since the last call to
[IFsrmQuota::ResetPeakUsage](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nf-fsrmquota-ifsrmquota-resetpeakusage). To reset this value,
call the **ResetPeakUsage** method.

#### Examples

For an example, see
[Getting Current Usage Values](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/getting-current-usage-values).

## See also

[IFsrmQuota](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nn-fsrmquota-ifsrmquota)

[MSFT_FSRMQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmquota)