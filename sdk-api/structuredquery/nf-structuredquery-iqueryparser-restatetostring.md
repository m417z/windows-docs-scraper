# IQueryParser::RestateToString

## Description

Restates a condition as a structured query string. If the condition was the result of parsing an original query string, the keywords of that query string are used to a great extent. If not, default keywords are used.

## Parameters

### `pCondition` [in]

Type: **[ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition)***

The condition to be restated.

### `fUseEnglish` [in]

Type: **BOOL**

Reserved. Must be **FALSE**.

### `ppszQueryString` [out]

Type: **LPWSTR***

Receives the restated query string. The caller must free the string by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.