# XMU565::XMU565(const uint8_t)

## Description

Initializes a new instance of [XMU565](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmu565) from a three element `int8_t` array.

This constructor initializes a new instance of **XMU565** from a three element `int8_t` array.

**Note** This is only available for C++ based development.

## Parameters

### `pArray`

Three element character array containing the values used to initialize the x-, y- and z-components of a new instance of XMU565.

## Remarks

Array elements and the **_w** argument are mapped to the vector components of a new instance of XMU565 as follows:

| XMU565 Member | Argument | Range |
|---------------|----------|-------|
| x | pArray[0] | 0, 31 |
| y | pArray[1] | 0, 63 |
| z | pArray[2] | 0, 31 |

Arguments to the constructors will be clamped to the permitted range prior to assignment to the appropriate member of **XMU565**.

The following pseudocode demonstrates the operation of this constructor, which takes advantage of the union of the three components of the XMU565vector with an instance of **uint16_t** in the definition of the structure:

```cpp
XMU565 instance;
_x1=min( max( pArray[0], 0 ), 31);
_y1=min( max( pArray[1], 0 ), 63 );
_z1=min( max( pArray[2], 0 ), 31 );

instance.v= ((z & 0x1F) << 11) |
            ((y & 0x3F) << 5) |
            ((x & 0x1F));
```

## See also

[XMU565](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmu565)

[XMU565 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmu565-ctor)