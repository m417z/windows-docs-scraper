# XMUBYTE4::XMUBYTE4(const uint8_t)

## Description

Initializes a new instance of [XMUBYTE4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmubyte4) from a four element `float` array argument.

This constructor initializes a new instance of **XMUBYTE4** from a four element `float` array argument.

**Note** This constructor is only available under C++.

## Parameters

### `pArray`

Four element **float** array containing the values used to initialize the four components of a new instance of **XMUBYTE4**.

## Remarks

The magnitude of each member of the *pArray* argument to the constructor will be clamped to the range supported by an 8-bit signed integer [0.0, 255.0].

The following pseudocode demonstrates the operation of this constructor:

```cpp
XMUBYTE4 instance;

instance.x = (uint8_t)min( max( pArray[0] 0.0 ), 255.0 );
instance.y = (uint8_t)min( max( pArray[1] 0.0 ), 255.0 );
instance.z = (uint8_t)min( max( pArray[2] 0.0 ), 255.0 );
instance.w = (uint8_t)min( max( pArray[3] 0.0 ), 255.0 );
```

## See also

[XMUBYTE4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmubyte4)

[XMUBYTE4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmubyte4-ctor)