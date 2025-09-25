# XMUBYTEN4::XMUBYTEN4(float,float,float,float)

## Description

Initializes a new instance of `XMUBYTEN4` from four `float` arguments.

This constructor initializes a new instance of [XMUBYTEN4](https://msdn.microsoft.com/552002c1-0000-44a6-9f43-9c958a8d1aa3) from four
`float` arguments.

**Note** This constructor is only available under C++.

## Parameters

### `_x`

A normalized value for the x-coordinate of the vector.

This argument should be between 0.0 and 1.0. During the instantiation of an instance
of `XMUBYTEN4`, it is multiplied by `255.0f`, and then
stored as the **x** member of the structure.

### `_y`

A normalized value for the y-coordinate of the vector, the **y** of the new
instance of `XMUBYTEN4`

This argument should be between 0.0 and 1.0. During the instantiation of an
instance of `XMUBYTEN4`, it is multiplied by `255.0f`, and then
stored as the **y** member of the structure.

### `_z`

A normalized value for the z-coordinate of the vector, the **z** of the new
instance of `XMUBYTEN4`

This argument should be between 0.0 and 1.0. During the instantiation of an
instance of `XMUBYTEN4`, it is multiplied by `255.0f`, and then
stored as the **z** member of the structure.

### `_w`

A normalized value for the w-coordinate of the vector, the **w** of the new
instance of `XMUBYTEN4`

This argument should be between 0.0 and 1.0, During the instantiation of an
instance of `XMUBYTEN4`, it is multiplied by `255.0f`, and then
stored as the **w** member of the structure.

## Remarks

The magnitude of each argument to the constructor will be clamped to the range supported by an
8-bit unsigned integer [0, 255.0].

The following pseudocode demonstrates the operation of this constructor, which takes
advantage of the `union` of the four components of the `XMUBYTEN4` vector with
an instance of `uint32_t` in the definition of the structure:

```

	XMUBYTEN4 instance;
	_x1=min( max( _x, 0.0 ), 1.0 );
	_y1=min( max( _y, 0.0 ), 1.0 );
	_z1=min( max( _z, 0.0 ), 1.0 );
	_w1=min( max( _w, 0.0 ), 1.0 );
	_x = round( _x *  255.0f);
	_y = round( _y *  255.0f);
	_z = round( _z *  255.0f);
	_w = round( _w *  255.0f);
	instance.x = (uint8_t)_x1;
	instance.y = (uint8_t)_y1;
	instance.z = (uint8_t)_z1;
	instance.w = (uint8_t)_w1;

```

## See also

**Reference**

[XMUBYTEN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmubyten4)

[XMUBYTEN4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmubyten4-ctor)