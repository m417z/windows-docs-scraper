# XMUBYTEN4::XMUBYTEN4(const uint8_t)

## Description

Initializes a new instance of [XMUBYTEN4](https://learn.microsoft.com/windows/win32/api/directxpackedvector/ns-directxpackedvector-xmubyten4) from a four element `uint8_t` array argument.

This constructor initializes a new instance of **XMUBYTEN4** from a four element `uint8_t` array argument.

**Note** This constructor is only available under C++.

## Parameters

### `pArray`

Four element *uint8_t* array containing the values used to initialize the four components of a new instance of **XMUBYTEN4**.

## Remarks

Input values are not normalized. The following pseudocode demonstrates the operation of this constructor:

```cpp
XMUBYTEN4 instance;
instance.x = pArray[0];
instance.y = pArray[1];
instance.z = pArray[2];
instance.w = pArray[3];

```

## See also

[XMUBYTEN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmubyten4)

[XMUBYTEN4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmubyten4-ctor)