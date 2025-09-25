# IQueryParser::ParsePropertyValue

## Description

Parses a condition for a specified property.

## Parameters

### `pszPropertyName` [in]

Type: **LPCWSTR**

Property name.

### `pszInputString` [in]

Type: **LPCWSTR**

Query string to be parsed, relative to that property.

### `ppSolution` [out, retval]

Type: **[IQuerySolution](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iquerysolution)****

Receives an [IQuerySolution](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iquerysolution) object. The calling application must release it by calling its [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The input string can be anything that could have been written immediately after a property in a structured query. For example, "from:(bill OR alex)" would be a valid structured query, so passing System.StructuredQuery.Virtual.From (for which From is a keyword) in the *pszPropertyName* parameter and "(bill OR alex)" or "bill OR alex" in the *pszInputString* parameter would be valid. This would result in an **OR** of leaf nodes that relate the System.StructuredQuery.Virtual.From property with the strings "bill" and "alex".