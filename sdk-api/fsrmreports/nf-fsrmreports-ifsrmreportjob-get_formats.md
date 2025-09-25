# IFsrmReportJob::get_Formats

## Description

Retrieves or sets an array of formats that determine the content format of the reports.

This property is read/write.

## Parameters

## Remarks

Each report in the job is generated in each of the specified formats.

The file name extension is based on the format. The extension for DHTML is
".html", the extension for HTML is ".htm", the
extension for TXT is ".txt", the extension for CSV is
".csv", and the extension for XML is
".xml".

If the report type is **FsrmReportType_ExportReport**, you can specify only the
**FsrmReportFormat_Csv** and **FsrmReportFormat_Xml** formats.
The report is not run if one or both of these formats are not specified. Other formats are ignored.

#### Examples

For an example, see [Defining a Report Job](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/defining-a-report-job).

## See also

[IFsrmReportJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nn-fsrmreports-ifsrmreportjob)