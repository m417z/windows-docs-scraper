# IPropertyDescription::GetConditionType

## Description

Gets the condition type and default condition operation to use when displaying the property in the query builder UI. This influences the list of predicate conditions (for example, equals, less than, and contains) that are shown for this property.

## Parameters

### `pcontype` [out]

Type: **[PROPDESC_CONDITION_TYPE](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-propdesc_condition_type)***

A pointer to a value that indicates the condition type.

### `popDefault` [out]

Type: **[CONDITION_OPERATION](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_operation)***

When this method returns, contains a pointer to a value that indicates the default condition operation.

## Return value

Type: **HRESULT**

Always returns **S_OK**.

## Remarks

For more information, see the *conditionType* attribute of the [typeInfo](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-typeinfo) element in the property's .propdesc file.

## See also

[IPropertyDescription](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescription)

[Property Description Schema](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-entry)