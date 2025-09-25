# ICondition::GetValueNormalization

## Description

Retrieves the character-normalized value of the search condition node.

## Parameters

### `ppszNormalization` [out, retval]

Type: **LPWSTR***

Receives a pointer to a Unicode string representation of the value.

## Return value

Type: **HRESULT**

Returns S_OK if successful, E_FAIL if this is not a leaf node, or an error value otherwise.

## Remarks

In **Windows 7 and later**, if the value of the leaf node is **VT_EMPTY**, *ppwszNormalization* points to an empty string. If the value is a string, such as VT_LPWSTR, VT_BSTR or VT_LPSTR, then *ppwszNormalization* is set to a character-normalized form of the value. In other cases, *ppwszNormalization* is set to some other character-normalized string representation of the value.

## See also

[CONDITION_OPERATION](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_operation)

[CONDITION_TYPE](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_type)

[ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition)

[ICondition2](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition2)

**Reference**