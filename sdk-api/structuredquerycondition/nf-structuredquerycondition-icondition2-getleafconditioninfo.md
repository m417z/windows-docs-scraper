# ICondition2::GetLeafConditionInfo

## Description

Retrieves the property name, operation, and value from a leaf search condition node.

## Parameters

### `ppropkey` [out, optional]

Type: **[PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey)***

Receives the name of the property of the leaf condition as a PROPERTYKEY.

### `pcop` [out, optional]

Type: **[CONDITION_OPERATION](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_operation)***

Receives the operation of the leaf condition as a [CONDITION_OPERATION](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_operation) enumeration.

### `ppropvar` [out, optional]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

Receives the property value of the leaf condition as a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant).

## Return value

Type: **HRESULT**

Returns S_OK if successful, E_FAIL if this is not a leaf node, or an error value otherwise.

## Remarks

Any or all of the three parameters can be **NULL**.

The [StructuredQuerySample](https://github.com/microsoft/Windows-classic-samples/tree/master/Samples/Win7Samples/winui/WindowsSearch/StructuredQuerySample) demonstrates how to read lines from the console, parse them using the system schema, and display the resulting condition trees.

## See also

[CONDITION_OPERATION](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_operation)

[CONDITION_TYPE](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_type)

[ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition)

[ICondition2](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition2)

**Reference**