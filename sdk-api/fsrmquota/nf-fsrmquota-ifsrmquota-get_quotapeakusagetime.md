# IFsrmQuota::get_QuotaPeakUsageTime

## Description

[This property is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmquota) class.]

Retrieves the date and time that the
[IFsrmQuota::QuotaPeakUsage](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nf-fsrmquota-ifsrmquota-get_quotapeakusage) property was
set.

This property is read-only.

## Parameters

## Remarks

The time stamp is set when the quota usage reaches a new, higher peak level, or the peak usage value is
reset.

To get the highest peak usage value, access the
[QuotaPeakUsage](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nf-fsrmquota-ifsrmquota-get_quotapeakusage) property.

#### Examples

For an example, see
[Getting Current Usage Values](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/getting-current-usage-values).

## See also

[IFsrmQuota](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nn-fsrmquota-ifsrmquota)

[MSFT_FSRMQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmquota)