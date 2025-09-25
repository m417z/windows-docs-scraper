# XMUSHORTN2::XMUSHORTN2(float,float)

## Description

Initializes a new instance of `XMUSHORTN2` from two normalized `float` arguments.

This constructor initializes a new instance of [XMUSHORTN2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmushortn2) from two
normalized `float` arguments.

**Note** This constructor is only available under C++.

## Parameters

### `_x`

A normalized value for the x-coordinate of the vector.

This argument should be between 0.0 and 1.0; during the instantiation of an
instance of `XMUSHORTN2`, it is multiplied by `65535.0f` and
then stored as the **x** member of the structure.

### `_y`

A normalized value for the y-coordinate of the vector, the **y** of the
new instance of `XMUSHORTN2`.

This argument should be between 0.0 and 1.0; during the instantiation of an
instance of `XMUSHORTN2`, it is multiplied by `65535.0f` and
then stored as the **y** member of the structure.

## Remarks

All input values,*_x* and *_y* are clamped to a range of 0.0 to 1.0.

The following pseudocode demonstrates the operation of this constructor:

```

	XMUSHORTN2 instance;
	_x1=min( max( _x, 0.0 ), 1.0 );
	_y1=min( max( _y, 0.0 ), 1.0 );
	_x1 = round( _x1 * 65535.0f);
	_y1 = round( _y1 * 65535.0f);
	instance._x = _x1;
	instance._y = _y1;
	
```

## See also

**Reference**

[XMUSHORTN2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmushortn2)

[XMUSHORTN2 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmushortn2-ctor)