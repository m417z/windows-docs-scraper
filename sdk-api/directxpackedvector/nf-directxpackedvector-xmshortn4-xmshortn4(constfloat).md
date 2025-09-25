# XMSHORTN4::XMSHORTN4(const float)

## Description

Initializes a new instance of [XMSHORTN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmshortn4) from a four element `float` array argument.

This constructor initializes a new instance of **XMSHORTN4** from a from a four element `float` array argument.

**Note** This constructor is only available under C++.

## Parameters

### `pArray`

Four element floating point array containing the values used to initialize the four components of a new instance of **XMSHORTN4**.

## Remarks

Array elements are mapped to the vector components of a new instance of **XMSHORTN4** as follows:

| Vector Component | Array Element | Range | Description |
|------------------|---------------|-------|--|
| x | pArray[0] | -1.0, 1.0 | During instantiation, pArray[0] is clamped between -1 and 1, multiplied by 32767.0f and assigned to x. |
| y | pArray[1] | -1.0, 1.0 | During instantiation, pArray[1] is clamped between -1 and 1, multiplied by 32767.0f, and then assigned to y. |
| z | pArray[2] | -1.0, 1.0 | During instantiation, pArray[2] is clamped between -1 and 1, multiplied by 32767.0f, and then assigned to z. |
| w | pArray[3] | -1.0, 1.0 | During instantiation, pArray[3] is clamped between -1 and 1, multiplied by 32767.0f, and then assigned to w. |

The following pseudocode demonstrates the operation of this constructor:

```cpp
XMSHORTN4 instance;
_x1=min( max( pArray[0], -1.0 ), 1.0 );
_y1=min( max( pArray[1], -1.0 ), 1.0 );
_z1=min( max( pArray[2], -1.0 ), 1.0 );
_w1=min( max( pArray[3], -1.0 ), 1.0 );
_x1 = round( _x1 * 32767.0f);
_y1 = round( _y1 * 32767.0f);
_z1 = round( _z1 * 32767.0f);
_w1 = round( _w1 * 32767.0f);
instance._x = _x1;
instance._y = _y1;
instance._z = _z1;
instance._w = _w1;
```

## See also

[XMSHORTN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmshortn4)

[XMSHORTN4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmshortn4-ctor)