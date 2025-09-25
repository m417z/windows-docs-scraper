# IDataManager::put_MaxFolderCount

## Description

Retrieves or sets the maximum number of folders to be used by all data collectors in the set.

This property is read/write.

## Parameters

## Remarks

The maximum value applies to all subfolders under the path specified by the [IDataCollectorSet::RootPath](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_rootpath) property. The [IDataManager::CheckBeforeRunning](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatamanager-get_checkbeforerunning) property checks this limit. The data manager also checks the limit when it runs.

## See also

[IDataManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatamanager)