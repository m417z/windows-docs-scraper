# XMUBYTE2::XMUBYTE2(const float)

## Description

Initializes a new instance of [XMUBYTE2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmubyte2) from a two-element `float` array argument.

This constructor initializes a new instance of **XMUBYTE2** from a two-element `float` array argument.

**Note** This constructor is only available with C++.

## Parameters

### `pArray`

Two-element **float** array containing the values used to initialize the two components of a new instance of **XMUBYTE2**.

## Remarks

The magnitude of each member of the *pArray* argument to the constructor will be clamped to the range supported by an 8-bit signed integer [0.0, 255.0].

The following pseudocode demonstrates the operation of this constructor:

```cpp
XMUBYTE2 instance;

instance.x = (uint8_t)min( max( pArray[0] 0.0 ), 255.0 );
instance.y = (uint8_t)min( max( pArray[1] 0.0 ), 255.0 );
```

## See also

[XMUBYTE2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmubyte2)

[XMUBYTE2 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmubyte2-ctor)