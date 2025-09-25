# XMSHORTN2::XMSHORTN2(const float)

## Description

Initializes a new instance of [XMSHORTN2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmshortn2) from a two element `float` array argument.

This constructor initializes a new instance of **XMSHORTN2** from a two element `float` array argument.

**Note** This constructor is only available under C++.

## Parameters

### `pArray`

Two element floating point array containing the values used to initialize the two components of a new instance of **XMSHORTN2**.

## Remarks

Array elements are mapped to the vector components of a new instance of **XMSHORTN2** as follows:

| Vector Component | Array Element | Range | Description |
|------------------|---------------|-------|--|
| x | pArray[0] | -1.0, 1.0 | During instantiation, pArray[0] is clamped between -1 and 1, multiplied by 32767.0f and assigned to x. |
| y | pArray[1] | -1.0, 1.0 | During instantiation, pArray[1] is clamped between -1 and 1, multiplied by 32767.0f, and then assigned to y. |

The following pseudocode demonstrates the operation of this constructor:

```cpp
XMSHORTN2 instance;
_x1=min( max( pArray[0], -1.0 ), 1.0 );
_y1=min( max( pArray[1], -1.0 ), 1.0 );
_x1 = round( _x1 * 32767.0f);
_y1 = round( _y1 * 32767.0f);
instance._x = _x1;
instance._y = _y1;
```

## See also

[XMSHORTN2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmshortn2)

[XMSHORTN2 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmshortn2-ctor)