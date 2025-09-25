# IFsrmQuotaManager::CreateQuota

## Description

[This method is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmquota) class.]

Creates a quota for the specified directory.

## Parameters

### `path` [in]

The local directory path to which the quota applies. The string is limited to 260 characters.

### `quota` [out]

An [IFsrmQuota](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nn-fsrmquota-ifsrmquota) interface to the newly created quota
object. Use this interface to define the quota. To add the quota to FSRM, call
[IFsrmQuota::Commit](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmobject-commit) method.

## Return value

The method returns the following return values.

## Remarks

The quota applies to the directory and all its subdirectories (recursively). Quotas specified on directories
higher in the directory tree further restrict the quota specified on this directory.

If the quota specifies the **FsrmQuotaFlags_Enforce**
[quota flag](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nf-fsrmquota-ifsrmquotabase-get_quotaflags), the file IO is blocked when the quota
is exceeded, but there are no actions taken, such as a command being run or a report generated. To perform actions
when the quota is exceeded, [create a threshold](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nf-fsrmquota-ifsrmquotabase-addthreshold)
and specify an action to run. To perform the action when the quota is exceeded, set the threshold to
100 (percent).

#### Examples

For an example, see [Defining a Quota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/defining-a-quota).

## See also

[FsrmQuotaManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmquotamanager)

[IFsrmQuotaManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nn-fsrmquota-ifsrmquotamanager)

[IFsrmQuotaManagerEx](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nn-fsrmquota-ifsrmquotamanagerex)

[MSFT_FSRMQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmquota)