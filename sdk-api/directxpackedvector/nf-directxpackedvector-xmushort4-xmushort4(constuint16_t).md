# XMUSHORT4::XMUSHORT4(const uint16_t)

## Description

Initializes a new instance of [XMUSHORT4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmushort4) from a four element `uint16_t` array argument.

This constructor initializes a new instance of **XMUSHORT4** from a four element `uint16_t` array argument.

**Note** This constructor is only available under C++.

## Parameters

### `pArray`

Four element **uint16_t** array containing the values used to initialize the four components of a new instance of **XMUSHORT4**.

## Remarks

The following pseudocode demonstrates the operation of this constructor:

```cpp
XMUSHORT4 instance;
instance.x = pArray[0];
instance.y = pArray[1];
instance.z = pArray[2];
instance.w = pArray[3];
```

## See also

[XMUSHORT4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmushort4)

[XMUSHORT4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmushort4-ctor)