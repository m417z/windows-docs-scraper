# XMUBYTE2::XMUBYTE2(const uint8_t)

## Description

Initializes a new instance of [**XMUBYTE2**](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmubyte2) from a two-element `int8_t` array argument.

This constructor initializes a new instance of **XMUBYTE2** from a two-element `int8_t` array argument.

**Note** This constructor is only available with C++.

## Parameters

### `pArray`

Two-element **int8_t** array containing the values used to initialize the two components of a new instance of **XMUBYTE2**.

## Remarks

The following pseudocode demonstrates the operation of this constructor:

```cpp
XMUBYTE2 instance;
instance.x = pArray[0];
instance.y = pArray[1];
```

## See also

[XMUBYTE2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmubyte2)

[XMUBYTE2 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmubyte2-ctor)