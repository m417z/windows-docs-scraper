# XMUDECN4::XMUDECN4(float,float,float,float)

## Description

This constructor initializes a new instance of [XMUDECN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmudecn4) from four
normalized `float` arguments.

**Note** This constructor is only available under C++.

## Parameters

### `_x`

A normalized value for the x-coordinate of the vector.

This argument should be between 0.0 and 1.0; during the instantiation of an
instance of `XMUDECN4`, it is multiplied by `1023.0f` and then
stored as the **x** member of the structure.

### `_y`

A normalized value for the y-coordinate of the vector, the **y** of the
new instance of `XMUDECN4`.

This argument should be between 0.0 and 1.0; during the instantiation of an
instance of `XMUDECN4`, it is multiplied by `1023.0f` and then
stored as the **y** member of the structure.

### `_z`

A normalized value for the z-coordinate of the vector, the **z** of the
new instance of `XMUDECN4`.

This argument should be between 0.0 and 1.0; during the instantiation of an
instance of `XMUDECN4`, it is multiplied by `1023.0f` and then
stored as the **z** member of the structure.

### `_w`

A normalized value for the w-coordinate of the vector, the **w** of the
new instance of `XMUDECN4`.

This argument should be between -1.0 and 1.0; during the instantiation of
an instance of [XMCOLOR](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmcolor), it is multiplied by `3.0f` and then
stored as the **w** member of the structure.

## Remarks

All input values,*_x*,*_y*, *_z*, and *_w* are
clamped to a range of -1.0 to 1.0.

The following pseudocode demonstrates the operation of this constructor, which takes
advantage of the `union` of the four components of the `XMDECN4` vector with an instance of `uint32_t` in the definition of the structure:

```

    	XMDECN4 instance;
	_x1=min( max( _x, 0.0 ), 1.0 );
	_y1=min( max( _y, 0.0 ), 1.0 );
	_z1=min( max( _z, 0.0 ), 1.0 );
	_w1=min( max( _w, 0.0 ), 1.0 );
	_x = round( _x *  1023.0f);
	_y = round( _y *  1023.0f);
	_z = round( _z *  1023.0f);
	_w = round( _w *  3.0f);

	instance.v =  ( (uint32_t)_w1 << 30) |
                      (((uint32_t)_z1 & 0x3FF) << 20) |
                      (((uint32_t)_y1 & 0x3FF) << 10) |
                      (((uint32_t)_x1 & 0x3FF));
	
```

## See also

**Reference**

[XMUDECN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmudecn4)

[XMUDECN4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmudecn4-ctor)