# IEntity::GetRelationship

## Description

Retrieves the [IRelationship](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-irelationship) object for this entity as requested by name.

## Parameters

### `pszRelationName` [in]

Type: **LPCWSTR**

The name of the relationship to find.

### `pRelationship` [out, retval]

Type: **[IRelationship](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-irelationship)****

Receives the address of a pointer to the requested [IRelationship](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-irelationship) object, or **NULL** if this entity has no relationship with the name specified.

## Return value

Type: **HRESULT**

Returns S_OK if successful, S_FALSE if there is no matching relationship, or an error value otherwise.