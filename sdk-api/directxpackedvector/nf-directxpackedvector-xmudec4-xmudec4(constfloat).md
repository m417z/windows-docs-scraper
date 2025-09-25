# XMUDEC4::XMUDEC4(const float)

## Description

Initializes a new instance of [XMUDEC4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmudec4) from a four element `float` array argument.

This constructor initializes a new instance of **XMUDEC4** from a four element `float` array argument.

**Note** This constructor is only available under C++.

## Parameters

### `pArray`

Four element floating point array containing the values used to initialize the four components of a new instance of **XMUDEC4**.

## Remarks

As **XMUDEC4** represents a four component integer vector, the fractional part of an element of *pArray* will be truncated.

Array elements are mapped to the vector components of a new instance of **XMUDEC4** as follows:

| XMUDEC4 Member | Array Element | Range |
|------------------|---------------|-------|
| x | pArray[0] | -0.0, 1023.0 |
| y | pArray[1] | -0.0, 1023.0 |
| z | pArray[2] | -0.0, 1023.0 |
| w | pArray[3] | 0, 3 |

Elements of *pArray* will be clamped to the permitted range prior to assignment to the appropriate member of **XMUDEC4**.

The following pseudocode demonstrates the operation of this constructor, which takes advantage of the union of the four components of the **XMUDEC4** vector with an instance of **uint32_t** in the definition of the structure:

```cpp
XMUDEC4 instance;
_x1=min( max( pArray[0], 0.0 ), 1023.0 );
_y1=min( max( pArray[1], 0.0 ), 1023.0 );
_z1=min( max( pArray[2], 0.0 ), 1023.0 );
_w1=min( max( pArray[3], 0.0 ), 3.0 );

instance.v =  ( (uint32_t)_w1 << 30) |
              (((uint32_t)_z1 & 0x3FF) << 20) |
              (((uint32_t)_y1 & 0x3FF) << 10) |
              (((uint32_t)_x1 & 0x3FF));
```

## See also

[XMUDEC4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmudec4)

[XMUDEC4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmudec4-ctor)