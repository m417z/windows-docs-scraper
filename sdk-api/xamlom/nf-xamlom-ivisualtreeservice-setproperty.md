# IVisualTreeService::SetProperty

## Description

Sets a property value on a XAML element.

## Parameters

### `instanceHandle` [in]

A handle to the element to set the property on.

### `value` [in]

A handle to the value to set on the element property.

### `propertyIndex` [in]

The index (in the XAML runtime cache) of the property to set.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The caller of **SetProperty** must know the index of the property to be set by first calling
[GetPropertyValuesChain](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/nf-xamlom-ivisualtreeservice-getpropertyvalueschain) and finding the property they want to set and retrieving its index.
They must also have an **InstanceHandle** to a value, either by calling [CreateInstance](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/nf-xamlom-ivisualtreeservice-createinstance), or caching
an earlier instance of some shared property, such as **SolidColorBrush**.

## See also

[IVisualTreeService](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/nn-xamlom-ivisualtreeservice)