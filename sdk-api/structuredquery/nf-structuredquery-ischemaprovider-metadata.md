# ISchemaProvider::MetaData

## Description

Retrieves an enumeration of global [IMetaData](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-imetadata) objects for the loaded schema.

## Parameters

### `riid` [in]

Type: **REFIID**

The desired IID of the result, either IID_IEnumUnknown or IID_IEnumVARIANT.

### `pMetaData` [out, retval]

Type: **void****

Receives a pointer to an enumeration of the [IMetaData](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-imetadata) objects. The calling application must release it by calling its [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.