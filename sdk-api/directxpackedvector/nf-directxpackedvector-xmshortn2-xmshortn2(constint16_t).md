# XMSHORTN2::XMSHORTN2(const int16_t)

## Description

Initializes a new instance of [XMSHORTN2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmshortn2) from a two element `int16_t` array argument.

This constructor initializes a new instance of **XMSHORTN2** from a two element `int16_t` array argument.

**Note** This constructor is only available under C++.

## Parameters

### `pArray`

Two element `int16_t` array containing the values used to initialize the two components of a new instance of **XMSHORTN2**.

## Remarks

Input values are not normalized. The following pseudocode demonstrates the operation of this constructor:

```cpp
XMSHORTN2 instance;
instance.x = pArray[0];
instance.y = pArray[1];
```

## See also

[XMSHORTN2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmshortn2)

[XMSHORTN2 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmshortn2-ctor)