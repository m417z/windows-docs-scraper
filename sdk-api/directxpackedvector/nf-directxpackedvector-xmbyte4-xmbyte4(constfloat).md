# XMBYTE4::XMBYTE4(const float)

## Description

Initializes a new instance of [XMBYTE4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmbyte4) from a four element `float` array argument.

This constructor initializes a new instance of `XMBYTE4` from a four element `float` array argument.

**Note** This constructor is only available under C++.

## Parameters

### `pArray`

Four element `float` array containing the values used to initialize the four components of a new instance of **XMBYTE4**.

## Remarks

The magnitude of each member of the **pArray** argument to the constructor will be clamped to the range supported by an 8-bit signed integer [-127.0, 127.0].

The following pseudocode demonstrates the operation of this constructor:

```cpp
XMBYTE4 instance;

instance.x = (int8_t)min( max( pArray[0] -127.0 ), 127.0 );
instance.y = (int8_t)min( max( pArray[1] -127.0 ), 127.0 );
instance.z = (int8_t)min( max( pArray[2] -127.0 ), 127.0 );
instance.w = (int8_t)min( max( pArray[3] -127.0 ), 127.0 );
```

## See also

[XMBYTE4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmbyte4)

[XMBYTE4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmbyte4-ctor)