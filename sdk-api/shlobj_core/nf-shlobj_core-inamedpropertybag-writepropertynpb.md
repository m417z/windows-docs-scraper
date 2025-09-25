# INamedPropertyBag::WritePropertyNPB

## Description

Saves a property to the named property bag.

## Parameters

### `pszBagname` [in]

Type: **PCWSTR**

A pointer to a string that contains the name of the property bag.

### `pszPropName` [in]

Type: **PCWSTR**

A pointer to a string that contains the name of the property to write.

### `pVar` [in]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

A pointer to a **VARIANT** that holds the new property value.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.