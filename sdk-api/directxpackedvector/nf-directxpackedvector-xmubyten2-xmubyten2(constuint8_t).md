# XMUBYTEN2::XMUBYTEN2(const uint8_t)

## Description

Initializes a new instance of [XMUBYTEN2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmubyten2) from a two-element `uint8_t` array argument.

This constructor initializes a new instance of **XMUBYTEN2** from a two-element `uint8_t` array argument.

**Note** This constructor is only available with C++.

## Parameters

### `pArray`

Two-element *uint8_t* array containing the values used to initialize the two components of a new instance of **XMUBYTEN2**.

## Remarks

Input values are not normalized. The following pseudocode demonstrates the operation of this constructor:

```cpp
XMUBYTEN2 instance;
instance.x = pArray[0];
instance.y = pArray[1];
```

## See also

[XMUBYTEN2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmubyten2)

[XMUBYTEN2 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmubyten2-ctor)