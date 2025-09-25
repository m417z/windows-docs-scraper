# IFsrmReportJob::EnumReports

## Description

Enumerates all the reports configured for this report job.

## Parameters

### `reports` [out]

An [IFsrmCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmcollection) interface that contains a collection of reports. The collection is empty if no reports are defined for the job.

Each item of the collection is a **VARIANT** of type **VT_DISPATCH**. Query the **pdispVal** member to get the [IFsrmReport](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nn-fsrmreports-ifsrmreport) interface.

## Return value

The method returns the following return values.

## See also

[IFsrmReportJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nn-fsrmreports-ifsrmreportjob)