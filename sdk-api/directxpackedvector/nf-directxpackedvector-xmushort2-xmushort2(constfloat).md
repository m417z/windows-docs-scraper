# XMUSHORT2::XMUSHORT2(const float)

## Description

Initializes a new instance of [XMUSHORT2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmushort2) from a two element `float` array argument.

This constructor initializes a new instance of **XMUSHORT2** from a from a two element `float` array argument.

**Note** This constructor is only available under C++.

## Parameters

### `pArray`

Two element **float** array containing the values used to initialize the two components of a new instance of XMUSHORT2.

## Remarks

The magnitude of each member of the *pArray* argument to the constructor will be clamped to the range supported by a 16-bit unsigned integer [0.0, 65535.0].

The following pseudocode demonstrates the operation of this constructor:

```cpp
XMUSHORT2 instance;

instance.x = (uint16_t)min( max( pArray[0] 0.0 ), 65535.0 );
instance.y = (uint16_t)min( max( pArray[1] 0.y0 ), 65535.0 );
```

## See also

[XMUSHORT2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmushort2)

[XMUSHORT2 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmushort2-ctor)