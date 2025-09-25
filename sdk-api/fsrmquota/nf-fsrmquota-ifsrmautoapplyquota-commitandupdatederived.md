# IFsrmAutoApplyQuota::CommitAndUpdateDerived

## Description

[This method is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMAutoQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmautoquota) class.]

Saves the quota and then applies any changes to the derived quotas.

## Parameters

### `commitOptions` [in]

The options for saving the quota. For possible values, see the
[FsrmCommitOptions](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmcommitoptions) enumeration.

### `applyOptions` [in]

The options used to choose the derived quotas to which the changes are applied. For possible values, see
the [FsrmTemplateApplyOptions](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmtemplateapplyoptions) enumeration.

### `derivedObjectsResult` [out]

An [IFsrmDerivedObjectsResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmderivedobjectsresult) interface
that you use to determine the list of derived objects that were updated and whether the update was
successful.

## Return value

The method returns the following return values.

## Remarks

In this context, a derived quota is any quota that is applied to a subdirectory of the automatic quota
directory. For example, if you create an automatic quota for *c:\folder1* and if
*folder1* has subdirectories of *c:\folder1\subfolder1*,
*c:\folder1\subfolder2*, and *c:\folder1\subfolder3*, then a
quota that exists on *subfolder1*, *subfolder2*, or
*subfolder3* is considered a derived quota.

You would call this method if you called the
[ApplyTemplate](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nf-fsrmquota-ifsrmquotaobject-applytemplate) method to change the source
template for the automatic quota. Calling the
**CommitAndUpdateDerived** method
would then propagate the new template's settings to the existing quotas under the automatic quota directory.

If you specify the **FsrmTemplateApplyOptions_ApplyToDerivedAll** option, FSRM will
create a quota for all immediate subdirectories that do not have a quota applied to them and will update any
existing quotas using the properties of the automatic quota, whether the quota was created from the automatic
quota or not. For example, if a quota in one of the subdirectories was originally derived from a template, the
quota is considered a derived quota and is updated using the automatic quota—the quota is no
longer considered derived from the template.

#### Examples

For an example, see [Updating a Quota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/updating-a-quota).

## See also

[IFsrmAutoApplyQuota](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nn-fsrmquota-ifsrmautoapplyquota)

[MSFT_FSRMAutoQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmautoquota)