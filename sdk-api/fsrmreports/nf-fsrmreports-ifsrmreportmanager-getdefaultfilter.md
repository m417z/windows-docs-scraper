# IFsrmReportManager::GetDefaultFilter

## Description

Retrieves the default report filter value that is used with the specified report type.

## Parameters

### `reportType` [in]

Report type. For possible values, see the [FsrmReportType](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmreporttype) enumeration.

### `filter` [in]

Report filter. For possible values, see the [FsrmReportFilter](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmreportfilter) enumeration.

### `filterValue` [out]

The default report filter value.

## Return value

The method returns the following return values.

## Remarks

This value is used if the [IFsrmReport::SetFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreport-setfilter) method was not called to specify a filter value for the report.

## See also

[FsrmReportManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmreportmanager)

[IFsrmReportManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nn-fsrmreports-ifsrmreportmanager)