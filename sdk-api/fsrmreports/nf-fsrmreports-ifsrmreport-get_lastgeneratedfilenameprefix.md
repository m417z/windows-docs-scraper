# IFsrmReport::get_LastGeneratedFileNamePrefix

## Description

Retrieves the report's generated file name for the last time the report was run. The string is used to make the report name unique.

This property is read-only.

## Parameters

## Remarks

The file names are generated to identify the collection of files that were generated for a report job the last time the report job ran.

To determine where the reports are stored, access the [IFsrmReportJob::LastGeneratedInDirectory](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreportjob-get_lastgeneratedindirectory) property.

## See also

[IFsrmReport](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nn-fsrmreports-ifsrmreport)