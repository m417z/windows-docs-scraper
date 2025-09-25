# IQueryParser::GetSchemaProvider

## Description

Retrieves a schema provider for browsing the currently loaded schema.

## Parameters

### `ppSchemaProvider` [out, retval]

Type: **[ISchemaProvider](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-ischemaprovider)****

Receives the address of a pointer to an [ISchemaProvider](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-ischemaprovider) object. The calling application must release it by invoking its [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.