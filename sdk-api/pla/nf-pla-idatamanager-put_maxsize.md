# IDataManager::put_MaxSize

## Description

Retrieves or sets the maximum disk space to be used by all data collectors in the set.

This property is read/write.

## Parameters

## Remarks

The maximum value applies to all files in all subfolders under the path specified by the [IDataCollectorSet::RootPath](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_rootpath) property.

This value is used by the data manager:

* Before the data collector set starts if the value of the [IDataManager::CheckBeforeRunning](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatamanager-get_checkbeforerunning) property is VARIANT_TRUE. If the maximum size is exceeded, the manager prevents the data collector set from running.
* After the collection is completed. If the maximum size is exceeded, the data manager will start deleting folders (according to the [IDataManager::ResourcePolicy](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatamanager-get_resourcepolicy) property) until the total size is below the maximum size.

The maximum size value is ignored for performance counter log collection. To work around this issue, you can do one of two things:

* Set the [IDataCollector::LogCircular](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollector-get_logcircular) property to **True** and set the [IDataCollectorSet::SegmentMaxSize](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_segmentmaxsize) property to the desired maximum size.
* Set the [IDataCollector::LogCircular](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollector-get_logcircular) property to **False**, set the [IDataCollectorSet::SegmentMaxSize](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_segmentmaxsize) property equal to the maximum folder size, and set the [IDataCollectorSet::Segment](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_segment) property to **False**.

## See also

[IDataManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatamanager)