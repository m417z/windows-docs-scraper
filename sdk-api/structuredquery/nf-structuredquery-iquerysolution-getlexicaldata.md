# IQuerySolution::GetLexicalData

## Description

Reports the query string, how it was tokenized, and what language code identifier (LCID) and word breaker were used to parse it.

## Parameters

### `ppszInputString` [out]

Type: **LPWSTR***

Receives the query string. This parameter can be **NULL**.

### `ppTokens` [out]

Type: **[ITokenCollection](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-itokencollection)****

Receives a pointer to an [ITokenCollection](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-itokencollection) object that describes how the query was tokenized. This parameter can be **NULL**.

### `plcid` [out]

Type: **LCID***

Receives a LCID for the word breaker used for this query. This parameter can be **NULL**.

### `ppWordBreaker` [out]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)****

Receives a pointer to the word breaker used for this query. This parameter can be **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.