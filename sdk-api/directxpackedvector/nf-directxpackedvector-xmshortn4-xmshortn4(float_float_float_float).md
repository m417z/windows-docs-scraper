# XMSHORTN4::XMSHORTN4(float,float,float,float)

## Description

Initializes a new instance of `XMSHORTN4` from four normalized `float` arguments.

This constructor initializes a new instance of [XMSHORTN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmshortn4) from a
four normalized `float` arguments.

**Note** This constructor is only available under C++.

## Parameters

### `_x`

A normalized value for the x-coordinate of the vector.

This argument should be between -1.0 and 1.0; during the instantiation of
an instance of `XMSHORTN4`, it is multiplied by `32767.0f` and
then stored as the **x** member of the structure.

### `_y`

A normalized value for the y-coordinate of the vector, the **y** of the
new instance of `XMSHORTN4`.

This argument should be between -1.0 and 1.0; during the instantiation of
an instance of `XMSHORTN4`, it is multiplied by `32767.0f` and
then stored as the **y** member of the structure.

### `_z`

A normalized value for the z-coordinate of the vector, the **z** of the
new instance of `XMSHORTN4`.

This argument should be between -1.0 and 1.0; during the instantiation of
an instance of `XMSHORTN4`, it is multiplied by `32767.0f` and
then stored as the **z** member of the structure.

### `_w`

A normalized value for the w-coordinate of the vector, the **w** of the
new instance of `XMSHORTN4`.

This argument should be between -1.0 and 1.0; during the instantiation of
an instance of `XMSHORTN4`, it is multiplied by `32767.0f` and
then stored as the **w** member of the structure.

## Remarks

All input values,*_x*,*_y*, *_z*, and *_w* are
clamped to a range of -1.0 to 1.0.

The following pseudocode demonstrates the operation of this constructor:

```

	XMSHORTN4 instance;
	_x1=min( max( _x, -1.0 ), 1.0 );
	_y1=min( max( _y, -1.0 ), 1.0 );
	_z1=min( max( _z, -1.0 ), 1.0 );
	_w1=min( max( _w, -1.0 ), 1.0 );
	_x1 = round( _x1 * 32767.0f);
	_y1 = round( _y1 * 32767.0f);
	_z1 = round( _z1 * 32767.0f);
	_w1 = round( _w1 * 32767.0f);
	instance._x = _x1;
	instance._y = _y1;
	instance._z = _z1;
	instance._w = _w1;
	
```

## See also

**Reference**

[XMSHORTN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmshortn4)

[XMSHORTN4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmshortn4-ctor)