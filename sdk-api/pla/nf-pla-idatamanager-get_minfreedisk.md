# IDataManager::get_MinFreeDisk

## Description

Retrieves or sets the minimum free disk space that needs to exist before data collection begins.

This property is read/write.

## Parameters

## Remarks

The minimum value applies to the folder specified in the [IDataCollectorSet::RootPath](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_rootpath) property. The [IDataManager::CheckBeforeRunning](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatamanager-get_checkbeforerunning) property checks this limit. The data manager also checks the limit when it runs.

## See also

[IDataManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatamanager)