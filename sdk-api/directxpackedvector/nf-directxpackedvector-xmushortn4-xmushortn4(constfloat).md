# XMUSHORTN4::XMUSHORTN4(const float)

## Description

Initializes a new instance of [XMUSHORTN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmushortn4) from a four element `float` array argument.

This constructor initializes a new instance of **XMUSHORTN4** from a four element `float` array argument.

**Note** This constructor is only available under C++.

## Parameters

### `pArray`

Four element floating point array containing the values used to initialize the four components of a new instance of **XMUSHORTN4**.

## Remarks

Array elements are mapped to the vector components of a new instance of **XMUSHORTN4** as follows:

| Vector Component | Array Element | Range | Description |
|------------------|---------------|-------|--|
| x | pArray[0] | 0.0, 1.0 | During instantiation, pArray[0] is clamped between 0 and 1, multiplied by 65535.0f and assigned to x. |
| y | pArray[1] | 0.0, 1.0 | During instantiation, pArray[1] is clamped between 0 and 1, multiplied by 65535.0f, and then assigned to y. |
| z | pArray[2] | 0.0, 1.0 | During instantiation, pArray[2] is clamped between 0 and 1, multiplied by 65535.0f, and then assigned to z. |
| w | pArray[3] | 0.0, 1.0 | During instantiation, pArray[3] is clamped between 0 and 1, multiplied by 65535.0f, and then assigned to w. |

The following pseudocode demonstrates the operation of this constructor:

```cpp
XMUSHORTN4 instance;
_x1=min( max( pArray[0], 0.0 ), 1.0 );
_y1=min( max( pArray[1], 0.0 ), 1.0 );
_z1=min( max( pArray[2], 0.0 ), 1.0 );
_w1=min( max( pArray[3], 0.0 ), 1.0 )
_x1 = round( _x1 * 65535.0f);
_y1 = round( _y1 * 65535.0f);
_z1 = round( _z1 * 65535.0f);
_w1 = round( _w1 * 65535.0f);
instance._x = _x1;
instance._y = _y1;
instance._z = _z1;
instance._w = _w1;
```

## See also

[XMUSHORTN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmushortn4)

[XMUSHORTN4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmushortn4-ctor)