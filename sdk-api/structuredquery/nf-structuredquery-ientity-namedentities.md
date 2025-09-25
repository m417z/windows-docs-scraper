# IEntity::NamedEntities

## Description

Retrieves an enumeration of [INamedEntity](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-inamedentity) objects, one for each known named entity of this type.

## Parameters

### `riid` [in]

Type: **REFIID**

The desired IID of the result, either IID_IEnumUnknown or IID_IEnumVARIANT.

### `pNamedEntities` [out, retval]

Type: **void****

Receives the address of a pointer to an enumeration of [INamedEntity](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-inamedentity) objects, one for each known named entity of this type.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.