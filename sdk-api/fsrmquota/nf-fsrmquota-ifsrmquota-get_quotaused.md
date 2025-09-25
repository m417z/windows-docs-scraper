# IFsrmQuota::get_QuotaUsed

## Description

[This property is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmquota) class.]

Retrieves the current amount of disk space usage charged to this quota.

This property is read-only.

## Parameters

## Remarks

The value is the total disk space usage for the directory and all its subdirectories (recursively). Files,
directories, streams, metadata, and other file system–specific means of persisting data are
used in determining the usage.

#### Examples

For an example, see
[Getting Current Usage Values](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/getting-current-usage-values).

## See also

[IFsrmQuota](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nn-fsrmquota-ifsrmquota)

[MSFT_FSRMQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmquota)