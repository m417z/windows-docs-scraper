# IDataCollectorCollection::CreateDataCollectorFromXml

## Description

Creates a data collector using the specified XML.

## Parameters

### `bstrXml` [in]

A string that contains the XML of the data collector to create. For details on specifying the XML string, see the Remarks section of the data collector that you want to create.

### `pValidation` [out]

An [IValueMap](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-ivaluemap) interface that you use to retrieve the validation error of each property whose value is not valid. The [IValueMap::Count](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemap-get_count) property is zero if there were no errors.

### `pCollector` [out]

An [IDataCollector](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatacollector) interface of the newly created data collector. To get the actual data collector interface requested, call the **QueryInterface** method.

## Return value

Returns S_OK if successful.

## Remarks

If the XML syntax is valid, this API will return S_OK, even if one or more properties is not valid. Those properties whose values are valid are set. Those properties whose values are not valid are set to their default value.

To determine the errors that occurred, retrieve the [IValueMapItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-ivaluemapitem) interface for each error. The [IValueMapItem::Key](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemapitem-get_key) property contains the XPath of the element in error, for example, /AlertDataCollector/TaskArguments. The [IValueMapItem::Value](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemapitem-get_value) property contains the HRESULT associated with the error, and the [IValueMapItem::Description](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemapitem-get_description) property contains the message text associated with the error.

Typically, any errors that occur will be one of the following HRESULT values.

| Error | Description |
| --- | --- |
| PLA_S_PROPERTY_IGNORED | PLA ignored the property element because the data collector does not contain the specified property. |
| PLA_E_PROPERTY_CONFLICT | The property conflicts with another property, for example, both [LogAppend](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollector-get_logappend) and [LogCircular](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollector-get_logcircular) are VARIANT_TRUE. |

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

[IDataCollectorCollection::CreateDataCollector](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorcollection-createdatacollector)