# XMU555::XMU555(const uint8_t,bool)

## Description

Initializes a new instance of [XMU555](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmu555) from a three element `int8_t` array and one `bool` argument.

This constructor initializes a new instance of **XMU555** from a three element `int8_t` array (specifying x-, y- and z-components) and one <`bool` argument (specifying a w-component).

**Note** This is only available for C++ based development.

## Parameters

### `pArray`

Three element character array containing the values used to initialize the x-, y- and z-components of a new instance of **XMU555**.

### `_w`

The value of the instance's w-component.

## Remarks

Array elements and the **_w** argument are mapped to the vector components of a new instance of **XMU555** as follows:

| XMU555 Member | Argument | Range |
|---------------|----------|-------|
| x | pArray[0] | 0, 31 |
| y | pArray[1] | 0, 31 |
| z | pArray[2] | 0, 31 |
| w | _w | 0, 1 |

Arguments to the constructors will be clamped to the permitted range prior to assignment to the appropriate member of **XMU555**.

The following pseudocode demonstrates the operation of this constructor, which takes advantage of the union of the four components of the **XMU555** vector with an instance of **uint16_t** in the definition of the structure:

```cpp
XMU555 instance;
_x1=min( max( pArray[0], 0 ), 31 );
_y1=min( max( pArray[1], 0 ), 31 );
_z1=min( max( pArray[2], 0 ), 31 );
_w1=min( max( _w, 0 ), 1 );

instance.v =  (((uint16_t)_w1 ? 0x8000 : 0) |
              (((uint16_t)_z1 & 0x1F) << 10) |
              (((uint16_t)_y1 & 0x1F) << 5) |
              (((uint16_t)_x1 & 0x1F)));
```

## See also

[XMU555](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmu555)

[XMU555 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmu555-ctor)