# ID2D1Properties::GetType(U)

## Description

Gets the [D2D1_PROPERTY_TYPE](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_property_type) of the selected property.

This is a template overload. See Remarks.

## Parameters

### `index`

Type: **U**

The index of the property for which the type will be retrieved.

## Return value

Type: **[D2D1_PROPERTY_TYPE](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_property_type)**

This method returns a [D2D1_PROPERTY_TYPE](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_property_type)-typed value for the type of the selected property.

## Remarks

If the property does not exist, the method returns [D2D1_PROPERTY_TYPE_UNKNOWN](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_property_type).

```
template<typename U>
    D2D1_PROPERTY_TYPE GetType(
        U index
        ) CONST;
```

## See also

[D2D1_PROPERTY](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_property)

[D2D1_PROPERTY_TYPE](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_property_type)

[D2D1_SUBPROPERTY](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_subproperty)

[ID2D1Properties](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1properties)