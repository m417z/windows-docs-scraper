# XMBYTE2::XMBYTE2(const float)

## Description

Initializes a new instance of [XMBYTE2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmbyte2) from a two-element `float` array argument.

This constructor initializes a new instance of **XMBYTE2** from a two-element `float` array argument.

**Note** This constructor is only available with C++.

## Parameters

### `pArray`

Two-element `float` array containing the values used to initialize the two components of a new instance of **XMBYTE2**.

## Remarks

The magnitude of each member of the **pArray** argument to the constructor will be clamped to the range supported by an 8-bit signed integer [-127.0, 127.0].

The following pseudocode demonstrates the operation of this constructor:

```cpp
XMBYTE2 instance;

instance.x = (int8_t)min( max( pArray[0] -127.0 ), 127.0 );
instance.y = (int8_t)min( max( pArray[1] -127.0 ), 127.0 );
```

## See also

[XMBYTE2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmbyte2)

[XMBYTE2 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmbyte2-ctor)