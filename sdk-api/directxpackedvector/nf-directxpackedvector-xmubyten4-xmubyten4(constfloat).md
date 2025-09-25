# XMUBYTEN4::XMUBYTEN4(const float)

## Description

Initializes a new instance of [XMUBYTEN4](https://learn.microsoft.com/windows/win32/api/directxpackedvector/ns-directxpackedvector-xmubyten4) from a four element `float` array argument.

This constructor initializes a new instance of **XMUBYTEN4** from a from a four element `float` array argument.

**Note** This constructor is only available under C++.

## Parameters

### `pArray`

Four element **float** array containing the values used to initialize the four components of a new instance of **XMUBYTEN4**.

## Remarks

| Vector Component | Array Element | Range | Description |
|------------------|---------------|-------|--|
| x | pArray[0] | 0.0, 1.0 | During instantiation, pArray[0] is clamped between 0 and 1, multiplied by 255.0f and assigned to x. |
| y | pArray[1] | 0.0, 1.0 | During instantiation, pArray[1] is clamped between 0 and 1, multiplied by 255.0f, and then assigned to y. |
| z | pArray[2] | 0.0, 1.0 | During instantiation, pArray[2] is clamped between 0 and 1, multiplied by 255.0f, and then assigned to z. |
| w | pArray[3] | 0.0, 1.0 | During instantiation, pArray[3] is clamped between 0 and 1, multiplied by 255.0f, and then assigned to w. |

The following pseudocode demonstrates the operation of this constructor:

```cpp
XMUBYTEN4 instance;
_x1=min( max( pArray[0], 0.0 ), 1.0 );
_y1=min( max( pArray[1], 0.0 ), 1.0 );
_z1=min( max( pArray[2], 0.0 ), 1.0 );
_w1=min( max( pArray[3], 0.0 ), 1.0 );
_x1 = round( _x1 *  255.0f);
_y1 = round( _y1 *  255.0f);
_z1 = round( _z1 *  255.0f);
_w1 = round( _w1 *  255.0f);
instance.x = (uint8_t)_x1;
instance.y = (uint8_t)_y1;
instance.z = (uint8_t)_z1;
instance.w = (uint8_t)_w1;
```

## See also

[XMUBYTEN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmubyten4)

[XMUBYTEN4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmubyten4-ctor)