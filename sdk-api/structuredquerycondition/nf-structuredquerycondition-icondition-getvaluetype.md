# ICondition::GetValueType

## Description

Retrieves the semantic type of the value of the search condition node.

## Parameters

### `ppszValueTypeName` [out, retval]

Type: **LPWSTR***

Receives either a pointer to the semantic type of the value as a Unicode string or **NULL**.

## Return value

Type: **HRESULT**

Returns S_OK if successful, E_FAIL if this is not a leaf node, or an error value otherwise.

## See also

[CONDITION_OPERATION](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_operation)

[CONDITION_TYPE](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_type)

[ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition)

[ICondition2](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition2)

**Reference**