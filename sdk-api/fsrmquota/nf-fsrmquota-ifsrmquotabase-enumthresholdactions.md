# IFsrmQuotaBase::EnumThresholdActions

## Description

[This method is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmquota) class.]

Enumerates all the actions for the specified threshold.

## Parameters

### `threshold` [in]

The threshold that contains the actions that you want to enumerate.

### `actions` [out]

An [IFsrmCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmcollection) interface that contains a
collection of actions. The variant type of each item in the collection is **VT_DISPATCH**.
Query the **pdispVal** member of the variant to get an
[IFsrmAction](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmaction) interface. You can use the
[IFsrmAction::ActionType](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmaction-get_actiontype) property to determine
the actual action interface to query.

## Return value

The method returns the following return values.

## See also

[IFsrmQuotaBase](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nn-fsrmquota-ifsrmquotabase)

[MSFT_FSRMQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmquota)