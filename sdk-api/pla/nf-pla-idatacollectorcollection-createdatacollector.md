# IDataCollectorCollection::CreateDataCollector

## Description

Creates a data collector of the specified type.

## Parameters

### `Type` [in]

The type of data collector to create. For possible data collector types, see the [DataCollectorType](https://learn.microsoft.com/windows/win32/api/pla/ne-pla-datacollectortype) enumeration.

### `Collector` [out]

An [IDataCollector](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatacollector) interface of the newly created data collector. To get the actual data collector interface requested, call the **QueryInterface** method.

## Return value

Returns S_OK if successful.

## Remarks

Use one of the following interface identifiers to query the [IDataCollector](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatacollector) interface for the specific data collector.

| Data collector interface | Interface identifier |
| --- | --- |
| [IApiTracingDataCollector](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-iapitracingdatacollector) | IID_IApiTracingDataCollector |
| [IAlertDataCollector](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-ialertdatacollector) | IID_IAlertDataCollector |
| [IConfigurationDataCollector](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-iconfigurationdatacollector) | IID_IConfigurationDataCollector |
| [IPerformanceCounterDataCollector](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-iperformancecounterdatacollector) | IID_IPerformanceCounterDataCollector |
| [ITraceDataCollector](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-itracedatacollector) | IID_ITraceDataCollector |

## See also

[IDataCollectorCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatacollectorcollection)

[IDataCollectorCollection::CreateDataCollectorFromXml](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorcollection-createdatacollectorfromxml)