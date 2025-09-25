# IRelationship::Destination

## Description

Retrieves the destination [IEntity](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-ientity) object of the relationship. The destination of a relationshipo corresponds to the type of a property.

## Parameters

### `pDestinationEntity` [out, retval]

Type: **[IEntity](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-ientity)****

Receives the address of a pointer to an [IEntity](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-ientity) object, or **NULL** if the relationship is not real. For more information, see [IRelationship::IsReal](https://learn.microsoft.com/windows/desktop/api/structuredquery/nf-structuredquery-irelationship-isreal).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.