# IFsrmAutoApplyQuota::get_ExcludeFolders

## Description

[This property is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMAutoQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmautoquota) class.]

Retrieves or sets an array of immediate subdirectories to exclude from the automatic
quota.

This property is read/write.

## Parameters

## Remarks

The list can contain the names of existing subdirectories or subdirectories that may exist in the future.

Setting this property overwrites the current list of subdirectories to exclude. To remove all folders, pass an
empty array.

## See also

[IFsrmAutoApplyQuota](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nn-fsrmquota-ifsrmautoapplyquota)

[MSFT_FSRMAutoQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmautoquota)