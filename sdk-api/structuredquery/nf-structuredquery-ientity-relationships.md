# IEntity::Relationships

## Description

Retrieves an enumeration of [IRelationship](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-irelationship) objects, one for each relationship this entity has.

## Parameters

### `riid` [in]

Type: **REFIID**

The desired IID of the result, either IID_IEnumUnknown or IID_IEnumVARIANT.

### `pRelationships` [out, retval]

Type: **void****

Receives the address of a pointer to the enumeration of the [IRelationship](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-irelationship) objects.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.