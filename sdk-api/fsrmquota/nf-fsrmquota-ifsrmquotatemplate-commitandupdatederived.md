# IFsrmQuotaTemplate::CommitAndUpdateDerived

## Description

[This method is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmquota) class.]

Saves the quota template and then applies any changes to the derived quota objects.

## Parameters

### `commitOptions` [in]

The options for saving the template. For possible values, see the
[FsrmCommitOptions](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmcommitoptions) enumeration.

### `applyOptions` [in]

The options used to choose the derived objects to which the changes are applied. For possible values, see
the [FsrmTemplateApplyOptions](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmtemplateapplyoptions) enumeration.

### `derivedObjectsResult` [out]

An [IFsrmDerivedObjectsResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmderivedobjectsresult) interface
that you use to determine the list of derived objects that were updated and whether the update was
successful.

## Return value

The method returns the following return values.

## See also

[IFsrmQuotaTemplate](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nn-fsrmquota-ifsrmquotatemplate)

[MSFT_FSRMQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmquota)