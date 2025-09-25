# IPropertyChangeArray::IsKeyInArray

## Description

Specifies whether a particular property key exists in the change array.

## Parameters

### `key` [in]

Type: **REFPROPERTYKEY**

A reference to the [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structure of interest.

## Return value

Type: **HRESULT**

Returns **S_OK** if key is found; otherwise, E_FAIL.