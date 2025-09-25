# XMUINT2::XMUINT2(const uint32_t)

## Description

Initializes a new instance of [XMUINT2](https://learn.microsoft.com/windows/desktop/direct3dhlsl/xmuint2) from a two element `uint32_t` array argument.

This constructor initializes a new instance of **XMUINT2** from a two element `uint32_t` array argument.

**Note** This constructor is only available under C++.

## Parameters

### `pArray`

Two element **uint32_t** array containing the values used to initialize the two components of a new instance of **XMUINT2**.

## Remarks

```cpp
XMUINT2 instance;
instance.x = pArray[0];
instance.y = pArray[1];
instance.z = pArray[2];
instance.w = pArray[3];
```

## See also

[XMUINT2](https://learn.microsoft.com/windows/desktop/direct3dhlsl/xmuint2)

[XMUINT2 Constructors](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmuint2-xmuint2(constuint32_t))