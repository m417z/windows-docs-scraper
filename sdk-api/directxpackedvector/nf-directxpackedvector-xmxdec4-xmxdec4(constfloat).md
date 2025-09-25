# XMXDEC4::XMXDEC4(const float)

## Description

Initializes a new instance of [XMXDEC4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmxdec4) from a four element `float` array argument.

This constructor initializes a new instance of **XMXDEC4** from a four element `float` array argument.

**Note** This constructor is only available under C++.

## Parameters

### `pArray`

Four element floating point array containing the values used to initialize the four components of a new instance of **XMXDEC4**.

## Remarks

As XMXDEC4 represents a four component integer vector, the fractional part of an element of *pArray* will be truncated.

Array elements are mapped to the vector components of a new instance of **XMXDEC4** as follows:

| XMXDEC4 Member | Array Element | Range |
|---------------|----------|-------|
| x | pArray[0] | -511, 511 |
| y | pArray[1] | -511, 511 |
| z | pArray[2] | -511, 511 |
| w | pArray[3] | 0, 3 |

Elements of *pArray* will be clamped to the permitted range prior to assignment to the appropriate member of XMXDEC4.

The following pseudocode demonstrates the operation of this constructor, which takes advantage of the union of the four components of the **XMXDEC4** vector with an instance of **uint32_t** in the definition of the structure:

```cpp
XMXDEC4 instance;
_x1=min( max( pArray[0], -511.0 ), 511.0 );
_y1=min( max( pArray[1], -511.0 ), 511.0 );
_z1=min( max( pArray[2], -511.0 ), 511.0 );
_w1=min( max( pArray[3], 0.0 ), 3.0 );

instance.v =  ( (int32_t)_w1 << 30) |
              (((int32_t)_z1 & 0x3FF) << 20) |
              (((int32_t)_y1 & 0x3FF) << 10) |
              (((uint32_t)_x1 & 0x3FF));
```

## See also

[XMXDEC4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmxdec4)

[XMXDEC4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmxdec4-ctor)