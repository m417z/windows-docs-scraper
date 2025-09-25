# XMBYTEN2::XMBYTEN2(const float)

## Description

Initializes a new instance of [XMBYTEN2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmbyten2) from a two-element `float` array argument.

This constructor initializes a new instance of **XMBYTEN2** from a two-element `float` array argument.

**Note** This constructor is only available with C++.

## Parameters

### `pArray`

Two-element `float` array containing the values used to initialize the two components of a new instance of **XMBYTEN2**.

## Remarks

| Vector Component | Array Element | Range | Description |
|-----------------|----------------|-------|-|
| x | pArray[0] | -1.0, 1.0 | During instantiation, pArray[0] is clamped between -1 and 1, multiplied by 127.0f and assigned to x. |
| y | pArray[1] | -1.0, 1.0 | During instantiation, pArray[1] is clamped between -1 and 1, multiplied by 127.0f, and then assigned to y. |

The following pseudocode demonstrates the operation of this constructor:

```cpp
XMBYTEN2 instance;
_x1=min( max( pArray[0], -1.0 ), 1.0 );
_y1=min( max( pArray[1], -1.0 ), 1.0 );
_x1 = round( _x1 *  127.0f);
_y1 = round( _y1 *  127.0f);
instance.x = (int8_t)_x1;
instance.y = (int8_t)_y1;
```

## See also

[XMBYTEN2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmbyten2)

[XMBYTEN2 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmbyten2-ctor)