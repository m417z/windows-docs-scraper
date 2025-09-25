# IEntity::Base

## Description

Retrieves the parent entity of this entity.

## Parameters

### `pBaseEntity` [out, retval]

Type: **[IEntity](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-ientity)****

Receives a pointer to the parent [IEntity](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-ientity) object, or **NULL** if there is no parent entity.

## Return value

Type: **HRESULT**

Returns one of the following, or an error value otherwise.

| Return code | Description |
| --- | --- |
| **S_OK** | *pBaseEntity* successfully set. |
| **S_FALSE** | The entity has no parent; *pBaseEntity* successfully set to **NULL**. |

## Remarks

Each entity derives from some other entity, except the entity named Entity, for which this method returns S_FALSE. The derived entity inherits all relationships from the base entity.