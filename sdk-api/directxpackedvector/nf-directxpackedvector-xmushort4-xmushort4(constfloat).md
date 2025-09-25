# XMUSHORT4::XMUSHORT4(const float)

## Description

Initializes a new instance of [XMUSHORT4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmushort4) from a four element `float` array argument.

This constructor initializes a new instance of **XMUSHORT4** from a four element `float` array argument.

**Note** This constructor is only available under C++.

## Parameters

### `pArray`

Four element **float** array containing the values used to initialize the four components of a new instance of **XMUSHORT4**.

## Remarks

The magnitude of each member of the *pArray* argument to the constructor will be clamped to the range supported by a 16-bit signed integer [0, 65535.0].

The following pseudocode demonstrates the operation of this constructor:

```cpp
XMUSHORT4 instance;

instance.x = (uint16_t)min( max( pArray[0] 0.0 ), 65535.0 );
instance.y = (uint16_t)min( max( pArray[1] 0.0 ), 65535.0 );
instance.z = (uint16_t)min( max( pArray[2] 0.0 ), 65535.0 );
instance.w = (uint16_t)min( max( pArray[3] 0.0 ), 65535.0 );
```

## See also

[XMUSHORT4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmushort4)

[XMUSHORT4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmushort4-ctor)