# XMSHORT4::XMSHORT4(const int16_t)

## Description

Initializes a new instance of [XMSHORT4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmshort4) from a four element `int16_t` array argument.

This constructor initializes a new instance of **XMSHORT4** from a from element `int16_t` array argument.

**Note** This constructor is only available under C++.

## Parameters

### `pArray`

Four element `int16_t` array containing the values used to initialize the four components of a new instance of **XMSHORT4**.

## Remarks

The following pseudocode demonstrates the operation of this constructor:

```cpp
XMSHORT4 instance;
instance.x = pArray[0];
instance.y = pArray[1];
instance.z = pArray[2];
instance.w = pArray[3];
```

## See also

[XMSHORT4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmshort4)

[XMSHORT4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmshort4-ctor)