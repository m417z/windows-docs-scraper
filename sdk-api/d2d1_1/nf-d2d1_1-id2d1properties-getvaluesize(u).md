# ID2D1Properties::GetValueSize(U)

## Description

Gets the size of the property value in bytes, using the property index. This is a template overload. See Remarks.

## Parameters

### `index`

Type: **U**

The index of the property.

## Return value

Type: **UINT32**

This method returns size of the value in bytes, using the property index

## Remarks

This method returns zero if *index* does not exist.

```
template<typename U>
    UINT32 GetValueSize(
        U index
        ) CONST;
```

## See also

[ID2D1Properties](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1properties)