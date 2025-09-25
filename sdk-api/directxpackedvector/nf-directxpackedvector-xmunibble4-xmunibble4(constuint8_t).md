# XMUNIBBLE4::XMUNIBBLE4(const uint8_t)

## Description

Initializes a new instance of [XMUNIBBLE4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmunibble4) from a four element `int8_t` array argument.

This constructor initializes a new instance of **XMUNIBBLE4** from a four element `int8_t` array argument.

**Note** This is only available for C++ based development.

## Parameters

### `pArray`

Four element character array containing the values used to initialize the four components of a new instance of **XMUNIBBLE4**.

## Remarks

Array elements are mapped to the vector components of a new instance of **XMUNIBBLE4** as follows:

| XMUNIBBLE4 Member | Array Element | Range |
|---------------|----------|-------|
| x | pArray[0] | 0, 15 |
| y | pArray[1] | 0, 15 |
| z | pArray[2] | 0, 15 |
| w | pArray[3] | 0, 15 |

Elements of *pArray* will be clamped to the permitted range prior to assignment to the appropriate member of **XMUNIBBLE4**.

The following pseudocode demonstrates the operation of this constructor, which takes advantage of the union of the four components of the **XMUNIBBLE4** vector with an instance of uint16_t in the definition of the structure:
```cpp
XMUNIBBLE4 instance;
_x1=min( max( pArray[0], 0 ), 15 );
_y1=min( max( pArray[1], 0 ), 15 );
_z1=min( max( pArray[2], 0 ), 15 );
_w1=min( max( pArray[3], 0 ), 15 );

instance.v =  ( (uint16_t)_w1 << 12) |
                (((uint16_t)_z1 & 0xF) << 8) |
                (((uint16_t)_y1 & 0xF) << 4) |
                (((uint16_t)_x1 & 0xF));
```

## See also

[XMUNIBBLE4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmunibble4)

[XMUNIBBLE4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmunibble4-ctor)