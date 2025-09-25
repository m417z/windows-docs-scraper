# IQueryParser::RestatePropertyValueToString

## Description

Restates a specified property for a condition as a query string.

## Parameters

### `pCondition` [in]

Type: **[ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition)***

A condition to be restated as a query string.

### `fUseEnglish` [in]

Type: **BOOL**

Reserved. Must be **FALSE**.

### `ppszPropertyName` [out]

Type: **LPWSTR***

Receives a pointer to the property name as a Unicode string. The calling application must free the string by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

### `ppszQueryString` [out]

Type: **LPWSTR***

Receives a pointer to a query string for that property. The calling application must free the string by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the leaf nodes of the condition contain more than one property name, or no property name at all, E_INVALIDARG is returned.