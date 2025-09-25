# IDataCollector::get_LatestOutputLocation

## Description

Retrieves or sets the fully decorated file name that PLA used the last time it created the file.

This property is read/write.

## Parameters

## Remarks

Typically, you do not set this property. When the data collector starts, PLA sets this property using the value from the [IDataCollector::OutputLocation](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollector-get_outputlocation) property.

You can set this property to empty if the file has been deleted.

For trace data collectors only, you can set this property to the name of the file to use. If it is not set, PLA creates it as it would for any other data collector.

## See also

[IDataCollector](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatacollector)

[IDataCollector::OutputLocation](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollector-get_outputlocation)