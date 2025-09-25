# IDataCollector::get_LogAppend

## Description

Retrieves or sets a value that indicates if PLA should append the collected data to the current file.

This property is read/write.

## Parameters

## Remarks

A validation error occurs if this property conflicts with the [IDataCollector::LogCircular](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollector-get_logcircular) or [IDataCollector::LogOverwrite](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollector-get_logoverwrite) properties.

## See also

[IDataCollector](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatacollector)

[IDataCollector::LogCircular](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollector-get_logcircular)

[IDataCollector::LogOverwrite](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollector-get_logoverwrite)