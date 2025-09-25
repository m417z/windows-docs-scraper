# XMUINT3::XMUINT3(const uint32_t)

## Description

Initializes a new instance of [XMUINT3](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmuint3) from a three element `uint32_t` array argument.

This constructor initializes a new instance of **XMUINT3** from a three-element `uint32_t` array argument.

**Note** This constructor is only available under C++.

## Parameters

### `pArray`

Three-element **uint32_t** array containing the values used to initialize the three components of a new instance of **XMUINT3**.

## Remarks

The following pseudocode demonstrates the operation of this constructor:

```cpp
XMUINT3 instance;
instance.x =  pArray[0];
instance.y =  pArray[1];
instance.z =  pArray[2];
```

## See also

[XMUINT3](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmuint3)

[XMUINT3 Constructors](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmuint3-xmuint3(constuint32_t))