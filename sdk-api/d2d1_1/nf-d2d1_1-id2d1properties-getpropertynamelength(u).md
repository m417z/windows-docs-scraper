# ID2D1Properties::GetPropertyNameLength(U)

## Description

Gets the number of characters for the given property name. This is a template overload. See Remarks.

## Parameters

### `index`

Type: **U**

The index of the property name to retrieve.

## Return value

Type: **UINT32**

This method returns the size in characters of the name corresponding to the given property index, or zero if the property index does not exist.

## Remarks

The value returned by this method can be used to ensure that the buffer size for [GetPropertyName](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1properties-getpropertyname(uint32_pwstr_uint32)) is appropriate.

```
template<typename U>
    UINT32 GetPropertyNameLength(
        U index
        ) CONST;
```

## See also

[D2D1_PROPERTY](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_property)

[D2D1_SUBPROPERTY](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_subproperty)

[ID2D1DeviceContext::CreateEffect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-createeffect)

[ID2D1Properties](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1properties)