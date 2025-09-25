# IDataCollector::put_FileName

## Description

Retrieves or sets the base name of the file that will contain the data collector data.

This property is read/write.

## Parameters

## Remarks

The actual file name used could be different if you specified formatting options in the [IDataCollector::FileNameFormat](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollector-get_filenameformat) property. The [IDataCollector::LatestOutputLocation](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollector-get_latestoutputlocation) property contains the actual file name used.

Do not include the path in the file name; the [IDataCollectorSet::RootPath](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_rootpath) and [IDataCollectorSet::Subdirectory](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_subdirectory) properties determine the path to the file.

The file name extension that you specify depends on the type of data collector. The following table shows the correct extension to use for each data collector. If you specify a different extension, PLA will use it. If you do not specify an extension, PLA adds the correct extension to the file.

| Data collector type | Extension to use |
| --- | --- |
| Configuration data collectors | .xml |
| Performance data collectors | Can be .blg, .csv, or .tsv depending on the value of the [IPerformanceCounterDataCollector::LogFileFormat](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-iperformancecounterdatacollector-get_logfileformat) property. |
| Trace data collectors | .etl |

The [IDataCollector::LogAppend](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollector-get_logappend) and [IDataCollector::LogOverwrite](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollector-get_logoverwrite) properties determine the action taken if the file already exists.

## See also

[IDataCollector](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatacollector)

[IDataCollector::FileNameFormat](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollector-get_filenameformat)

[IDataCollector::FileNameFormatPattern](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollector-get_filenameformatpattern)