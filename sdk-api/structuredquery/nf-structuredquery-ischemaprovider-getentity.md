# ISchemaProvider::GetEntity

## Description

Retrieves an entity by name from the loaded schema.

## Parameters

### `pszEntityName` [in]

Type: **LPCWSTR**

The name of the entity being requested.

### `pEntity` [out, retval]

Type: **[IEntity](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-ientity)****

Receives the address of a pointer to the requested entity. The calling application must release the entity by calling its [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method. If there is no entity with the specified name, this parameter is set to **NULL**.

## Return value

Type: **HRESULT**

Returns S_OK if successful, S_FALSE if there is no entity with the specified name, or an error value otherwise.