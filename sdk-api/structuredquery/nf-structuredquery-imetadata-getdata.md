# IMetaData::GetData

## Description

Retrieves one key/value pair from the metadata of an [IEntity](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-ientity), [IRelationship](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-irelationship), or [ISchemaProvider](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-ischemaprovider) object.

## Parameters

### `ppszKey` [out]

Type: **LPCWSTR***

Receives the key of the metadata pair as a Unicode string. The calling application must free the returned string by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

### `ppszValue` [out]

Type: **LPWSTR***

Receives the value of the metadata pair as a Unicode string. The calling application must free the returned string by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.