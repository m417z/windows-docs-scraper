# ISchemaProvider::RootEntity

## Description

Retrieves the root entity of the loaded schema.

## Parameters

### `pRootEntity` [out, retval]

Type: **[IEntity](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-ientity)****

Receives a pointer to the root entity. The calling application must release it by invoking its [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.