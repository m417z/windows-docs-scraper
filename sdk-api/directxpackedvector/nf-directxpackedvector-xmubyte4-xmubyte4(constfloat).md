# XMUBYTE4::XMUBYTE4(const float)

## Description

Initializes a new instance of [XMUBYTE4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmubyte4) from a four element `int8_t` array argument.

This constructor initializes a new instance of **XMUBYTE4** from a four element `int8_t` array argument.

**Note** This constructor is only available under C++.

## Parameters

### `pArray`

Four element *int8_t* array containing the values used to initialize the four components of a new instance of **XMUBYTE4** .

## Remarks

The following pseudocode demonstrates the operation of this constructor:

```cpp
XMUBYTE4 instance;
instance.x = pArray[0];
instance.y = pArray[1];
instance.z = pArray[2];
instance.w = pArray[3];
```

## See also

[XMUBYTE4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmubyte4)

[XMUBYTE4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmubyte4-ctor)