# IPropertyDescription::GetAggregationType

## Description

Gets a value that describes how the property values are displayed when multiple items are selected in the UI.

## Parameters

### `paggtype` [out]

Type: **[PROPDESC_AGGREGATION_TYPE](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-propdesc_aggregation_type)***

When this method returns, contains a pointer to a value that indicates the aggregation type. See [PROPDESC_AGGREGATION_TYPE](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-propdesc_aggregation_type).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The information retrieved by this method comes from the *aggregationType* attribute of the [typeInfo](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-typeinfo) element in the property's .propdesc file.

## See also

[IPropertyDescription](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescription)

[Property Description Schema](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-entry)