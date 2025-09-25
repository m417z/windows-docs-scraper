# ICondition::GetComparisonInfo

## Description

Retrieves the property name, operation, and value from a leaf search condition node.

## Parameters

### `ppszPropertyName` [out, optional]

Type: **LPWSTR***

Receives the name of the property of the leaf condition as a Unicode string.

### `pcop` [out, optional]

Type: **[CONDITION_OPERATION](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_operation)***

Receives the operation of the leaf condition as a [CONDITION_OPERATION](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_operation) enumeration.

### `ppropvar` [out, optional]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

Receives the value of the leaf condition as a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant).

## Return value

Type: **HRESULT**

Returns S_OK if successful, E_FAIL if this is not a leaf node, or an error value otherwise.

## Remarks

Any or all of the three parameters can be **NULL**.

## See also

[CONDITION_OPERATION](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_operation)

[CONDITION_TYPE](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_type)

[ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition)

[ICondition2](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition2)

**Reference**