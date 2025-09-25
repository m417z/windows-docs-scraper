# XMUNIBBLE4::XMUNIBBLE4(const float)

## Description

Initializes a new instance of [XMUNIBBLE4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmunibble4) from a four element `float` array argument.

This constructor initializes a new instance of XMUNIBBLE4 from a from a four element `float` array argument.

**Note** This is only available for C++ based development.

## Parameters

### `pArray`

Four element floating point array containing the values used to initialize the four components of a new instance of **XMUNIBBLE4**.

## Remarks

Array elements are mapped to the vector components of a new instance of **XMUNIBBLE4** as follows:

| XMUNIBBLE4 Member | Array Element | Range |
|---------------|----------|-------|
| x | pArray[0] | 0.0, 15.0 |
| y | pArray[1] | 0.0, 15.0 |
| z | pArray[2] | 0.0, 15.0 |
| w | pArray[3] | 0.0, 15.0 |

Elements of *pArray* will be clamped to the permitted range prior to assignment to the appropriate member of **XMUNIBBLE4**.

The following pseudocode demonstrates the operation of this constructor, which takes advantage of the union of the four components of the **XMUNIBBLE4** vector with an instance of **uint16_t** in the definition of the structure:

```cpp
XMUNIBBLE4 instance;
_x1=min( max( pArray[0], 0 ), 15.0 );
_y1=min( max( pArray[1], 0 ), 15.0 );
_z1=min( max( pArray[2], 0 ), 15.0 );
_w1=min( max( pArray[3], 0 ), 15.0 );

instance.v =  ( (uint16_t)_w1 << 12) |
                (((uint16_t)_z1 & 0xF) << 8) |
                (((uint16_t)_y1 & 0xF) << 4) |
                (((uint16_t)_x1 & 0xF));
```

## See also

[XMUNIBBLE4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmunibble4)

[XMUNIBBLE4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmunibble4-ctor)