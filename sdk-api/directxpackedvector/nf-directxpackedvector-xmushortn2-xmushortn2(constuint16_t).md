# XMUSHORTN2::XMUSHORTN2(const uint16_t)

## Description

Initializes a new instance of [XMUSHORTN2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmushortn2) from a two element `uint16_t` array argument.

This constructor initializes a new instance of **XMUSHORTN2** from a from a two element `uint16_t` array argument.

**Note** This constructor is only available under C++.

## Parameters

### `pArray`

Two element **uint16_t** array containing the values used to initialize the two components of a new instance of XMUSHORTN2.

## Remarks

Input values are not normalized. The following pseudocode demonstrates the operation of this constructor:

```cpp
XMUSHORTN2 instance;
instance.x = pArray[0];
instance.y = pArray[1];
```

## See also

[XMUSHORTN2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmushortn2)

[XMUSHORTN2 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmushortn2-ctor)