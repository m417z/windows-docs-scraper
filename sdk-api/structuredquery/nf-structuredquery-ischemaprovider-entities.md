# ISchemaProvider::Entities

## Description

Retrieves an enumeration of [IEntity](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-ientity) objects with one entry for each entity in the loaded schema.

## Parameters

### `riid` [in]

Type: **REFIID**

The desired IID of the result, either IID_IEnumUnknown or IID_IEnumVARIANT.

### `pEntities` [out, retval]

Type: **void****

Receives a pointer to an enumeration of entities. The calling application must release it by calling its [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.