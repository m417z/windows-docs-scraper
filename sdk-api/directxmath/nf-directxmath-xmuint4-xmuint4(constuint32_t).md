# XMUINT4::XMUINT4(const uint32_t)

## Description

Initializes a new instance of [XMUINT4](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmuint4) from a four element `uint32_t` array argument.

This constructor initializes a new instance of **XMUINT4** from a four element `uint32_t` array argument.

**Note** This constructor is only available under C++.

## Parameters

### `pArray`

Four element **uint32_t** array containing the values used to initialize the four components of a new instance of **XMUINT4**.

## Remarks

The following pseudocode demonstrates the operation of this constructor:

```cpp
XMUINT4 instance;
instance.x = pArray[0];
instance.y = pArray[1];
instance.z = pArray[2];
instance.w = pArray[3];
```

## See also

[XMUINT4](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmuint4)

[XMUINT4 Constructors](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmuint4-xmuint4(constuint32_t))