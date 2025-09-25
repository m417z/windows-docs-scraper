# IFsrmQuotaBase::DeleteThreshold

## Description

[This method is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmquota) class.]

Deletes a threshold from the quota object.

## Parameters

### `threshold` [in]

The threshold to delete.

## Return value

The method returns the following return values.

## Remarks

All the actions associated with the threshold are also deleted. Note that the actions are not deleted until
the [IFsrmQuotaBase::Commit](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmobject-commit) method is called.

## See also

[IFsrmQuotaBase](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nn-fsrmquota-ifsrmquotabase)

[MSFT_FSRMQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmquota)