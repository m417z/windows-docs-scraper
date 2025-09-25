# IRelationship::IsReal

## Description

Reports whether a relationship is real.

## Parameters

### `pIsReal` [out, retval]

Type: **BOOL***

Receives **TRUE** for a real relationship; otherwise, **FALSE**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A relationship is not considered real if its source entity derives from an entity
that has a relationship of the same name. The purpose of such a "shadow" relationship
is to store metadata specific to the inherited relationship.