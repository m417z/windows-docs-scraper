# XMUDECN4::XMUDECN4(const float)

## Description

Initializes a new instance of [XMUDECN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmudecn4) from a four element `float` array argument.

This constructor initializes a new instance of **XMUDECN4** from a four element `float` array argument.

**Note** This constructor is only available under C++.

## Parameters

### `pArray`

Four element floating point array containing the values used to initialize the four components of a new instance of XMUDECN4.

## Remarks

Array elements are mapped to the vector components of a new instance of **XMUDECN4** as follows:

| Vector Component | Array Element | Range | Description |
|------------------|---------------|-------|--|
| x | pArray[0] | 0.0, 1.0 | During instantiation, pArray[0] is clamped between 0 and 1, multiplied by 1023.0f and assigned to **x**. |
| y | pArray[1] | 0.0, 1.0 | During instantiation, pArray[1] is clamped between 0 and 1, multiplied by 1023.0f, and then assigned to **y**. |
| z | pArray[2] | 0.0, 1.0 | During instantiation, pArray[2] is clamped between 0 and 1, multiplied by 1023.0f, and then assigned to **z**. |
| w | pArray[3] | 0.0, 1.0 | During instantiation, pArray[3] is clamped between 0 and 1, and then assigned to **w**. This argument should be between 0.0 and 1.0; during the instantiation of an instance of **XMUDECN4**, it is multiplied by 3.0f and then stored as the **w** member of the structure. |

```cpp
XMUDECN4 instance;
_x1=min( max( pArray[0], 0.0 ), 1.0 );
_y1=min( max( pArray[1], 0.0 ), 1.0 );
_z1=min( max( pArray[2], 0.0 ), 1.0 );
_w1=min( max( pArray[3], 0.0 ), 1.0 );
_x = round( _x *  1023.0f);
_y = round( _y *  1023.0f);
_z = round( _z *  1023.0f);
_w = round( _w *  3.0f);

instance.v =  ( (uint32_t)_w1 << 30) |
                (((uint32_t)_z1 & 0x3FF) << 20) |
                (((uint32_t)_y1 & 0x3FF) << 10) |
                (((uint32_t)_x1 & 0x3FF));
```

## See also

[XMUDECN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmudecn4)

[XMUDECN4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmudecn4-ctor)