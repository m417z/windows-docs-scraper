# XMBYTEN4::XMBYTEN4(const int8_t)

## Description

Initializes a new instance of [XMBYTEN4](https://learn.microsoft.com/windows/win32/api/directxpackedvector/ns-directxpackedvector-xmbyten4) from a four element `int8_t` array argument.

This constructor initializes a new instance of **XMBYTEN4** from a four element `int8_t` array argument.

**Note** This constructor is only available under C++.

## Parameters

### `pArray`

Four element `int8_t` array containing the values used to initialize the four components of a new instance of **XMBYTEN4**.

## Remarks

Input values are not normalized. The following pseudocode demonstrates the operation of this constructor:

```cpp
XMBYTEN4 instance;
instance.x = pArray[0];
instance.y = pArray[1];
instance.z = pArray[2];
instance.w = pArray[3];
```

## See also

[XMBYTEN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmbyten4)

[XMBYTEN4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmbyten4-ctor)