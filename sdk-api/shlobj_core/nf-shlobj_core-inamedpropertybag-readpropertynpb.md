# INamedPropertyBag::ReadPropertyNPB

## Description

Causes a property to be read from the named property bag.

## Parameters

### `pszBagname` [in]

Type: **PCWSTR**

A pointer to a string that contains the name of the property bag.

### `pszPropName` [in]

Type: **PCWSTR**

A pointer to a string that contains the name of the property to be read.

### `pVar` [in, out]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

The address of a **VARIANT** that, when this method returns successfully, receives the property value.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.