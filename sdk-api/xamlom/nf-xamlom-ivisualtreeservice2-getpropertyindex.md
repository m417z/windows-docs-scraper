# IVisualTreeService2::GetPropertyIndex

## Description

Gets the property index for the specified property name.

## Parameters

### `object` [in]

The dependency object to get the property index from.

### `propertyName` [in]

The name of the dependency property for which to get the index.

### `pPropertyIndex` [out]

The index of the specified property.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | No property with *propertyName* was found, or the property cannot be applied to *object*. |

## Remarks

This index can be passed to the [GetProperty](https://learn.microsoft.com/previous-versions/windows/desktop/xaml_diagnostics/ivisualtreeservice2-getproperty) method in order to retrieve a specific property on an object.

## See also

[IVisualTreeService2](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/nn-xamlom-ivisualtreeservice2)