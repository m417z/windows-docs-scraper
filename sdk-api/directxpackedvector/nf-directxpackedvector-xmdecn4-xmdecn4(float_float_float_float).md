# XMDECN4::XMDECN4(float,float,float,float)

## Description

Initializes a new instance of `XMDECN4` from four normalized `float` arguments.

This constructor initializes a new instance of [XMDECN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmdecn4) from four
normalized `float` arguments.

**Note** This constructor is only available under C++.

## Parameters

### `_x`

A normalized value for the x-coordinate of the vector.

This argument should be between -1.0 and 1.0; during the instantiation of
an instance of `XMDECN4`, it is multiplied by `511.0f` and
then stored as the **x** member of the structure.

### `_y`

A normalized value for the y-coordinate of the vector, the **y** of the
new instance of `XMDECN4`.

This argument should be between -1.0 and 1.0; during the instantiation of
an instance of `XMDECN4`, it is multiplied by `511.0f` and
then stored as the **y** member of the structure.

### `_z`

A normalized value for the z-coordinate of the vector, the **z** of the
new instance of `XMDECN4`.

This argument should be between -1.0 and 1.0; during the instantiation of
an instance of `XMDECN4`, it is multiplied by `511.0f` and
then stored as the **z** member of the structure.

### `_w`

A normalized value for the w-coordinate of the vector, the **w** of the
new instance of `XMDECN4`.

This argument should be between -1.0 and 1.0.

## Remarks

All input values,*_x*,*_y*, *_z*, and *_w* are
clamped to a range of -1.0 to 1.0.

The following pseudocode demonstrates the operation of this constructor, which takes
advantage of the `union` of the four components of the `XMDECN4` vector with an instance of `uint32_t` in the definition of the structure:

```

    	XMDECN4 instance;
	_x1=min( max( _x, -1.0 ), 1.0 );
	_y1=min( max( _y, -1.0 ), 1.0 );
	_z1=min( max( _z, -1.0 ), 1.0 );
	_w1=min( max( _w, -1.0 ), 1.0 );
	_x1 = round( _x1 *  511.0f);
	_y1 = round( _y1 *  511.0f);
	_z1 = round( _z1 *  511.0f);

	instance.v =  ( (int32_t)_w1 << 30) |
                      (((int32_t)_z1 & 0x3FF) << 20) |
                      (((int32_t)_y1 & 0x3FF) << 10) |
                      (((int32_t)_x1 & 0x3FF));
	
```

## See also

**Reference**

[XMDECN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmdecn4)

[XMDECN4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmdecn4-ctor)