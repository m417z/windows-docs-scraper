# ISchemaProvider::LookupAuthoredNamedEntity

## Description

Finds named entities of a specified type in a tokenized string, and returns the value of the entity and the number of tokens the entity value occupies.

## Parameters

### `pEntity` [in]

Type: **[IEntity](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-ientity)***

A pointer to an [IEntity](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-ientity) object identifying the type of named entity to locate.

### `pszInputString` [in]

Type: **LPCWSTR**

An input string in which to search for named entity keywords.

### `pTokenCollection` [in]

Type: **[ITokenCollection](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-itokencollection)***

A pointer to the tokenization of the string in the *pszInputString* parameter.

### `cTokensBegin` [in]

Type: **ULONG**

The zero-based position of a token in the *pTokenCollection* from which to start searching.

### `pcTokensLength` [out]

Type: **ULONG***

Receives a pointer to the number of tokens covered by the named entity keyword that was found.

### `ppszValue` [out]

Type: **LPWSTR***

Receives a pointer to the value of the named entity that was found, as a Unicode string. The caller must free the string by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree). An [INamedEntity](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-inamedentity) object can be obtained by calling the [GetNamedEntity](https://learn.microsoft.com/windows/desktop/api/structuredquery/nf-structuredquery-ientity-getnamedentity) method of *pEntity* and passing the string that was received in this parameter.

## Return value

Type: **HRESULT**

Returns S_OK if the token sequence beginning at position *cTokensBegin* denotes a named entity of the specified (entity) type. If there is no such token sequence, returns S_FALSE.

## Remarks

The method finds only named entities authored with keywords in the schema, not named entities recognized by an [IConditionGenerator](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iconditiongenerator) object.