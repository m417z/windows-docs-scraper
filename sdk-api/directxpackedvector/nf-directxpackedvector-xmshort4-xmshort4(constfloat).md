# XMSHORT4::XMSHORT4(const float)

## Description

Initializes a new instance of [XMSHORT4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmshort4) from a four element `float` array argument.

This constructor initializes a new instance of **XMSHORT4** from a four element `float` array argument.

**Note** This constructor is only available under C++.

## Parameters

### `pArray`

Four element `float` array containing the values used to initialize the four components of a new instance of **XMSHORT4**.

## Remarks

The magnitude of each member of the *pArray* argument to the constructor will be clamped to the range supported by a 16-bit unsigned integer [-32767.0, 32767.0].

The following pseudocode demonstrates the operation of this constructor:

```cpp
XMSHORT4 instance;

instance.x = (int16_t)min( max( pArray[0] -32767.0 ), 32767.0 );
instance.y = (int16_t)min( max( pArray[1] -32767.0 ), 32767.0 );
instance.z = (int16_t)min( max( pArray[2] -32767.0 ), 32767.0 );
instance.w = (int16_t)min( max( pArray[3] -32767.0 ), 32767.0 );
```

## See also

[XMSHORT4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmshort4)

[XMSHORT4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmshort4-ctor)