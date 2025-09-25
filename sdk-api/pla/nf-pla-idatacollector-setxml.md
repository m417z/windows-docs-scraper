# IDataCollector::SetXml

## Description

Sets the property values of those properties included in the XML.

## Parameters

### `Xml` [in]

XML that contains the collector properties to set. For details on specifying the XML string, see the Remarks section of [IDataCollector](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatacollector).

### `Validation` [out]

An [IValueMap](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-ivaluemap) interface that you use to retrieve the validation error of each property whose value is not valid. The [IValueMap::Count](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemap-get_count) property is zero if there were no errors.

## Return value

Returns S_OK if the method call was successful. You must check the value map for errors. If the method returns S_OK and there are no validation errors, then the collector was successfully initialized.

## Remarks

If the XML syntax is valid, this API will return S_OK, even if one or more properties are not valid. Those properties whose values are valid are set. Those properties whose values are not valid are set to their default value.

You can also initialize the collector properties by passing the XML to the [IDataCollectorCollection::CreateDataCollectorFromXml](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorcollection-createdatacollectorfromxml) property when you create the data collector.

The method fails if the collector element specified in the XML does not match the collector type of the interface.

To determine the errors that occurred, retrieve the [IValueMapItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-ivaluemapitem) interface for each error. The [IValueMapItem::Key](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemapitem-get_key) property contains the XPath of the element in error (for example, /AlertDataCollector/TaskArguments), the [IValueMapItem::Value](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemapitem-get_value) property contains the HRESULT associated with the error, and the [IValueMapItem::Description](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemapitem-get_description) property contains the message text associated with the error.

Typically, any errors that occur will be one of the following HRESULT values.

| Error | Description |
| --- | --- |
| PLA_S_PROPERTY_IGNORED | PLA ignored the property element because the data collector does not contain the specified property. |
| PLA_E_PROPERTY_CONFLICT | The property conflicts with another property, for example, both [LogAppend](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollector-get_logappend) and [LogCircular](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollector-get_logcircular) are VARIANT_TRUE. |

## See also

[IDataCollector](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatacollector)

[IDataCollector::Xml](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollector-get_xml)

[IDataCollectorSet::SetXml](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-setxml)