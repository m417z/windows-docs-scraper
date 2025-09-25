# DataCollectorType enumeration

## Description

Defines the data collector types.

## Constants

### `plaPerformanceCounter:0`

Collects performance counter data. The [IPerformanceCounterDataCollector](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-iperformancecounterdatacollector) interface represents this data collector.

### `plaTrace:1`

Collects events from an event trace session. The [ITraceDataCollector](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-itracedatacollector) interface represents this data collector.

### `plaConfiguration:2`

Collects computer configuration information. The [IConfigurationDataCollector](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-iconfigurationdatacollector) interface represents this data collector.

### `plaAlert:3`

Monitors performance counters and performs actions if the counter value crosses the specified threshold. The [IAlertDataCollector](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-ialertdatacollector) interface represents this data collector.

### `plaApiTrace:4`

Logs API calls made by the process. The [IApiTracingDataCollector](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-iapitracingdatacollector) interface represents this data collector.

## See also

[IDataCollector::DataCollectorType](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollector-get_datacollectortype)