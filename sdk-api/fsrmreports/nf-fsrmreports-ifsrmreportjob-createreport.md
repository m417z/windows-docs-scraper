# IFsrmReportJob::CreateReport

## Description

Creates a new report object of the specified type.

## Parameters

### `reportType` [in]

Type of report to generate. For possible values, see the[FsrmReportType](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmreporttype) enumeration.

Note that the job can contain only one report of each type.

### `report` [out]

An [IFsrmReport](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nn-fsrmreports-ifsrmreport) interface to the newly created report. Use the interface to configure the report.

## Return value

The method returns the following return values.

## See also

[IFsrmReportJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nn-fsrmreports-ifsrmreportjob)