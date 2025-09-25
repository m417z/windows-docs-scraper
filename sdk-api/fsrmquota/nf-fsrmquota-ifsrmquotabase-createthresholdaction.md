# IFsrmQuotaBase::CreateThresholdAction

## Description

[This method is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmquota) class.]

Creates an action and associates it with the specified threshold.

## Parameters

### `threshold` [in]

The threshold with which to associate the action. Specify the same value that you specified when calling
the [IFsrmQuotaBase::AddThreshold](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nf-fsrmquota-ifsrmquotabase-addthreshold)
method.

### `actionType` [in]

The action to perform when the threshold is reached or exceeded. For possible values, see the
[FsrmActionType](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmactiontype) enumeration.

### `action` [out]

An [IFsrmAction](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmaction) interface of the newly created action.
Query the interface for the action interface that you specified in the *actionType*
parameter. For example, if the action type is **FsrmActionType_Command**, query the
interface for the [IFsrmActionCommand](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmactioncommand) interface.

## Return value

The method returns the following return values.

## Remarks

You can specify up to four unique actions for each threshold.

The action is deleted if the threshold is deleted.

#### Examples

For an example, see
[Using Templates to Define Quotas](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/using-templates-to-define-quotas).

## See also

[IFsrmQuotaBase](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nn-fsrmquota-ifsrmquotabase)

[MSFT_FSRMQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmquota)