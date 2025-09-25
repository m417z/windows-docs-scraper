# IFsrmQuotaManager::CreateAutoApplyQuota

## Description

[This method is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmquota) class.]

Creates an automatic quota for the specified directory.

## Parameters

### `quotaTemplateName` [in]

The name of a template from which to derive the quota; automatic quotas must derive from a template. The
string is limited to 4,000 characters.

### `path` [in]

The local directory path to which the quota applies. The string is limited to 260 characters.

### `quota` [out]

An [IFsrmAutoApplyQuota](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nn-fsrmquota-ifsrmautoapplyquota) interface to the newly
created quota object. The specified template is used to initialize the quota. Use this interface to change the
quota and to exclude specific subdirectories from the quota. To add the quota to FSRM, call
[IFsrmAutoApplyQuota::Commit](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmobject-commit) method.

## Return value

The method returns the following return values.

## Remarks

When you save the automatic quota, FSRM creates quotas for all existing subdirectories under the specified
directory that do not already contain a quota. When a new subdirectory is created under the specified directory,
FSRM uses the properties of the automatic quota to create a quota for the new subdirectory.

If you are creating both the automatic quota and the subdirectories at the same time, you should first
create the subdirectories and then create the automatic quota because it provides better performance.

#### Examples

For an example, see [Defining a Quota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/defining-a-quota).

## See also

[FsrmQuotaManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmquotamanager)

[IFsrmQuotaManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nn-fsrmquota-ifsrmquotamanager)

[IFsrmQuotaManagerEx](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nn-fsrmquota-ifsrmquotamanagerex)

[MSFT_FSRMQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmquota)