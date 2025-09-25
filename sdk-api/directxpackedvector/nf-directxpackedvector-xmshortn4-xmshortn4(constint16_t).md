# XMSHORTN4::XMSHORTN4(const int16_t)

## Description

Initializes a new instance of [XMSHORTN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmshortn4) from a four element `int16_t` array argument.

This constructor initializes a new instance of **XMSHORTN4** from a four element `int16_t` array argument.

**Note** This constructor is only available under C++.

## Parameters

### `pArray`

Four element `int16_t` array containing the values used to initialize the four components of a new instance of **XMSHORTN4**.

## Remarks

Input values are not normalized. The following pseudocode demonstrates the operation of this constructor:

```cpp
XMSHORTN4 instance;
instance.x = pArray[0];
instance.y = pArray[1];
instance.z = pArray[2];
instance.w = pArray[3];
```

## See also

[XMSHORTN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmshortn4)

[XMSHORTN4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmshortn4-ctor)