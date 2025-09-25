# XMSHORT2::XMSHORT2(const float)

## Description

Initializes a new instance of [XMSHORT2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmshort2) from a two element `float` array argument.

This constructor initializes a new instance of **XMSHORT2** from a two element `float` array argument.

**Note** This constructor is only available under C++.

## Parameters

### `pArray`

Two element `float` array containing the values used to initialize the two components of a new instance of **XMSHORT2**.

## Remarks

The magnitude of each member of the *pArray* argument to the constructor will be clamped to the range supported by a 16-bit signed integer [-32767.0, 32767.0].

The following pseudocode demonstrates the operation of this constructor:

```cpp
XMSHORT2 instance;

instance.x = (int16_t)min( max( pArray[0] -32767.0 ), 32767.0 );
instance.y = (int16_t)min( max( pArray[1] -32767.0 ), 32767.0 );
```

## See also

[XMSHORT2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmshort2)

[XMSHORT2 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmshort2-ctor)