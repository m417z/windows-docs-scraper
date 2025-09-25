# IQuerySolution::GetQuery

## Description

Retrieves the condition tree and the semantic type of the solution.

## Parameters

### `ppQueryNode` [out]

Type: **[ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition)****

Receives a pointer to an [ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition) condition tree that is the interpretation of the query string. This parameter can be **NULL**.

### `ppMainType` [out]

Type: **[IEntity](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-ientity)****

Receives a pointer to an [IEntity](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-ientity) object that identifies the semantic type of the interpretation. This parameter can be **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.