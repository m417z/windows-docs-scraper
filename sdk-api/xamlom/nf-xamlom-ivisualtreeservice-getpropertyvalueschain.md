# IVisualTreeService::GetPropertyValuesChain

## Description

Gets an array of all the
properties set on the element passed in, and an array of all the styles involved in setting the effective values of the properties.

## Parameters

### `instanceHandle` [in]

A handle to the element to query properties on.

### `pSourceCount` [out]

The count of the property sources array.

### `ppPropertySources` [out]

An array of property sources.

### `pPropertyCount` [out]

The count of the property values array.

### `ppPropertyValues` [out]

An array of property values.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code. This
method should not fail in normal conditions.

## Remarks

**GetPropertyValuesChain** returns an array of [PropertyChainValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/ns-xamlom-propertychainvalue) structs that represents all the
properties set on the element passed in. It also returns an array of [PropertyChainSource](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/ns-xamlom-propertychainsource) structs that represents all the styles involved in setting the effective value of each property.

## See also

[IVisualTreeService](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/nn-xamlom-ivisualtreeservice)