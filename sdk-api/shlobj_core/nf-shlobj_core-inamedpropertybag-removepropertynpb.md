# INamedPropertyBag::RemovePropertyNPB

## Description

Removes a property from a named property bag.

## Parameters

### `pszBagname` [in]

Type: **PCWSTR**

A pointer to a string that contains the name of the property bag from which a property is to be removed.

### `pszPropName` [in]

Type: **PCWSTR**

A pointer to a string that contains the name of the property to remove.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.