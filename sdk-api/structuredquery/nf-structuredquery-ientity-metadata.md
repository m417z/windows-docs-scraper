# IEntity::MetaData

## Description

Retrieves an enumeration of [IMetaData](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-imetadata) objects for this entity.

## Parameters

### `riid` [in]

Type: **REFIID**

The desired IID of the result, either IID_IEnumUnknown or IID_IEnumVARIANT.

### `pMetaData` [out, retval]

Type: **void****

Receives the address of a pointer to an enumeration of [IMetaData](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-imetadata) objects.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.