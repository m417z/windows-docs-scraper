# XMBYTEN4::XMBYTEN4(float,float,float,float)

## Description

Initializes a new instance of `XMBYTEN4` from four `float` arguments.

This constructor initializes a new instance of [XMBYTEN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmbyten4)  from four
`float` arguments.

**Note** This constructor is only available under C++.

## Parameters

### `_x`

A normalized value for the x-coordinate of the vector.

This argument should be between -1.0 and 1.0. During the instantiation of
an instance of `XMBYTEN4`, it is multiplied by `127.0f` and
then stored as the **x** member of the structure.

### `_y`

A normalized value for the y-coordinate of the vector, the **y** of the
new instance of `XMBYTEN4`

This argument should be between -1.0 and 1.0. During the instantiation of
an instance of `XMBYTEN4`, it is multiplied by `127.0f` and
then stored as the **y** member of the structure.

### `_z`

A normalized value for the z-coordinate of the vector, the **z** of the
new instance of `XMBYTEN4`

This argument should be between -1.0 and 1.0. During the instantiation of
an instance of `XMBYTEN4`, it is multiplied by `127.0f` and
then stored as the **z** member of the structure.

### `_w`

A normalized value for the w-coordinate of the vector, the **w** of the
new instance of `XMBYTEN4`

This argument should be between -1.0 and 1.0. During the instantiation of
an instance of `XMBYTEN4`, it is multiplied by `127.0f` and
then stored as the **w** member of the structure.

## Remarks

The magnitude of each argument to the constructor will be clamped to the range supported
by an 8-bit signed integer [-127.0, 127.0].

The following pseudocode demonstrates the operation of this constructor, which takes
advantage of the `union` of the four components of the `XMBYTEN4` vector with an instance of `uint32_t` in the definition of the structure:

```

	XMBYTEN4 instance;
	_x1=min( max( _x, -1.0 ), 1.0 );
	_y1=min( max( _y, -1.0 ), 1.0 );
	_z1=min( max( _z, -1.0 ), 1.0 );
	_w1=min( max( _w, -1.0 ), 1.0 );
	_x1 = round( _x1 *  127.0f);
	_y1 = round( _y1 *  127.0f);
	_z1 = round( _z1 *  127.0f);
	_w1 = round( _w1 *  127.0f);
	instance.x = (int8_t)_x1;
	instance.y = (int8_t)_y1;
	instance.z = (int8_t)_z1;
	instance.w = (int8_t)_w1;

```

## See also

**Reference**

[XMBYTEN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmbyten4)

[XMBYTEN4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmbyten4-ctor)