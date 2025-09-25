# XMSHORTN2::XMSHORTN2(float,float)

## Description

Initializes a new instance of `XMSHORTN2` from two normalized `float` arguments.

This constructor initializes a new instance of [XMSHORTN2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmshortn2) from two
normalized `float` arguments.

**Note** This constructor is only available under C++.

## Parameters

### `_x`

A normalized value for the x-coordinate of the vector.

This argument should be between -1.0 and 1.0; during the instantiation of an
instance of `XMSHORTN2`, it is multiplied by `32767.0f` and
then stored as the **x** member of the structure.

### `_y`

A normalized value for the y-coordinate of the vector, the **y** of the
new instance of `XMSHORTN2`.

This argument should be between -1.0 and 1.0; during the instantiation of an
instance of `XMSHORTN2`, it is multiplied by `32767.0f` and
then stored as the **y** member of the structure.

## Remarks

All input values,*_x* and *_y* are clamped to a range of -1.0 to 1.0.

The following pseudocode demonstrates the operation of this constructor:

```

	XMSHORTN2 instance;
	_x1=min( max( _x, -1.0 ), 1.0 );
	_y1=min( max( _y, -1.0 ), 1.0 );
	_x1 = round( _x1 * 32767.0f);
	_y1 = round( _y1 * 32767.0f);
	instance._x = _x1;
	instance._y = _y1;
	
```

## See also

**Reference**

[XMSHORTN2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmshortn2)

[XMSHORTN2 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmshortn2-ctor)