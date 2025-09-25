# ICondition2::GetLocale

## Description

Retrieves the property name, operation, and value from a leaf search condition node.

## Parameters

### `ppszLocaleName` [out, optional]

Type: **LPWSTR***

Receives the name of the locale of the leaf condition as a Unicode string. This parameter can be **NULL**.

## Return value

Type: **HRESULT**

Returns S_OK if successful, E_FAIL if this is not a leaf node, or an error value otherwise.

## See also

[CONDITION_OPERATION](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_operation)

[CONDITION_TYPE](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_type)

[ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition)

[ICondition2](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition2)

**Reference**