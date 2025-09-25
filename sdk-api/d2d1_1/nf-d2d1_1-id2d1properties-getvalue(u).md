# ID2D1Properties::GetValue(U)

## Description

Gets the value of the property by index. This is a template overload. See Remarks.

## Parameters

### `index`

Type: **U**

The index of the property from which the value is to be obtained.

## Return value

Type: **T**

Returns the value requested.

## Remarks

```
template<typename T, typename U>
    T GetValue(
        U index
        ) const;
```

## See also

[D2D1_PROPERTY](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_property)

[D2D1_SUBPROPERTY](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_subproperty)

[ID2D1DeviceContext::CreateEffect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-createeffect)

[ID2D1Properties](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1properties)