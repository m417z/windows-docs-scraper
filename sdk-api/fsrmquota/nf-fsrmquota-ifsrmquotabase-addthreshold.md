# IFsrmQuotaBase::AddThreshold

## Description

[This method is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmquota) class.]

Adds a threshold to the quota object.

## Parameters

### `threshold` [in]

The threshold to add to the quota object. The threshold is expressed as a percentage of the
[quota limit](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nf-fsrmquota-ifsrmquotabase-get_quotalimit). The value must be from 1 through
250, inclusively.

## Return value

The method returns the following return values.

## Remarks

You can specify up to 16 unique thresholds for a quota.

A threshold defines the percentage (as a whole number) of directory quota limit used. When the size of all
data in the directory exceeds the threshold, the FSRM server performs the specified actions (see
[IFsrmQuotaBase::CreateThresholdAction](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nf-fsrmquota-ifsrmquotabase-createthresholdaction)).

#### Examples

For an example, see
[Using Templates to Define Quotas](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/using-templates-to-define-quotas).

## See also

[IFsrmQuotaBase](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nn-fsrmquota-ifsrmquotabase)

[MSFT_FSRMQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmquota)