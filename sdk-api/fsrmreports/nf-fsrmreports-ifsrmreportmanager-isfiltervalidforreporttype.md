# IFsrmReportManager::IsFilterValidForReportType

## Description

Retrieves a value that determines whether a specified report filter is configurable for the specified report type.

## Parameters

### `reportType` [in]

Report type. For possible values, see the [FsrmReportType](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmreporttype) enumeration.

### `filter` [in]

Report filter. For possible values, see the [FsrmReportFilter](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmreportfilter) enumeration.

### `valid` [out]

Is **VARIANT_TRUE** if the filter is configurable for the report type, otherwise it is **VARIANT_FALSE**.

## Return value

The method returns the following return values.

## See also

[FsrmReportManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmreportmanager)

[IFsrmReportManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nn-fsrmreports-ifsrmreportmanager)