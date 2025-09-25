# XMBYTEN4::XMBYTEN4(const float)

## Description

Initializes a new instance of [XMBYTEN4](https://learn.microsoft.com/windows/win32/api/directxpackedvector/ns-directxpackedvector-xmbyten4) from a four element `float` array argument.

This constructor initializes a new instance of **XMBYTEN4** from a from a four element `float` array argument.

**Note** This constructor is only available under C++.

## Parameters

### `pArray`

Four element `float` array containing the values used to initialize the four components of a new instance of **XMBYTEN4**.

## Remarks

| Vector Component | Array Element | Range | Description |
|------------------|---------------|-------|-|
| x | pArray[0] | -1.0, 1.0 | During instantiation, pArray[0] is clamped between -1 and 1, multiplied by 127.0f and assigned to x. |
| y | pArray[1] | -1.0, 1.0 | During instantiation, pArray[1] is clamped between -1 and 1, multiplied by 127.0f, and then assigned to y. |
| z | pArray[2] | -1.0, 1.0 | During instantiation, pArray[2] is clamped between -1 and 1, multiplied by 127.0f, and then assigned to z. |
| w | pArray[3] | -1.0, 1.0 | During instantiation, pArray[3] is clamped between -1 and 1, multiplied by 127.0f, and then assigned to w. |

The following pseudocode demonstrates the operation of this constructor:

```cpp
XMBYTEN4 instance;
_x1=min( max( pArray[0], -1.0 ), 1.0 );
_y1=min( max( pArray[1], -1.0 ), 1.0 );
_z1=min( max( pArray[2], -1.0 ), 1.0 );
_w1=min( max( pArray[3], -1.0 ), 1.0 );
_x1 = round( _x1 *  127.0f);
_y1 = round( _y1 *  127.0f);
_z1 = round( _z1 *  127.0f);
_w1 = round( _w1 *  127.0f);
instance.x = (int8_t)_x1;
instance.y = (int8_t)_y1;
instance.z = (int8_t)_z1;
instance.w = (int8_t)_w1;
```

## See also

[XMBYTEN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmbyten4)

[XMBYTEN4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmbyten4-ctor)