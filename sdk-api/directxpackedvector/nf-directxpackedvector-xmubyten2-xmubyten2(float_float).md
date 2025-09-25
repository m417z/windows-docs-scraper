# XMUBYTEN2::XMUBYTEN2(float,float)

## Description

Initializes a new instance of `XMUBYTEN2` from two `float` arguments.

This constructor initializes a new instance of [XMUBYTEN2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmubyten2)  from two `float` arguments.

**Note** This constructor is only available with C++.

## Parameters

### `_x`

A normalized value for the x-coordinate of the vector.

This argument should be between 0.0 and 1.0. During the instantiation of an instance
of `XMUBYTEN2`, it is
multiplied by `255.0f`, and then stored as the **x** member of the structure.

### `_y`

A normalized value for the y-coordinate of the vector, the **y**
of the new instance of `XMUBYTEN2`.

This argument should be between 0.0 and 1.0. During the instantiation of an instance
of `XMUBYTEN2`, it is
multiplied by `255.0f`, and then stored as the **y** member of the structure.

## Remarks

The magnitude of each argument to the constructor will be clamped to the range supported by an 8-bit unsigned integer
[0, 255.0].

The following pseudocode demonstrates the operation of this constructor, which takes advantage of the `union` of the four components of the `XMUBYTEN2` vector with an instance of `uint32_t` in the definition of
the structure:

```

	XMUBYTEN2 instance;
	_x1=min( max( _x, 0.0 ), 1.0 );
	_y1=min( max( _y, 0.0 ), 1.0 );
	_x = round( _x *  255.0f);
	_y = round( _y *  255.0f);
	instance.x = (uint8_t)_x1;
	instance.y = (uint8_t)_y1;

```

## See also

**Reference**

[XMUBYTEN2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmubyten2)

[XMUBYTEN2 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmubyten2-ctor)