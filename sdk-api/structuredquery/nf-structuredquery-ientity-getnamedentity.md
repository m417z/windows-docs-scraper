# IEntity::GetNamedEntity

## Description

Retrieves an [INamedEntity](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-inamedentity) object based on an entity name.

## Parameters

### `pszValue` [in]

Type: **LPCWSTR**

The name of an entity to be found.

### `ppNamedEntity` [out, retval]

Type: **[INamedEntity](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-inamedentity)****

Receives a pointer to the [INamedEntity](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-inamedentity) object that was named in *pszValue*. **NULL** if no named entity was found.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or S_False if the named entity cannot be found.