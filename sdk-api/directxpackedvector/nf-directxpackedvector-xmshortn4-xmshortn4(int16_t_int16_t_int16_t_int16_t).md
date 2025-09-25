# XMSHORTN4::XMSHORTN4(int16_t,int16_t,int16_t,int16_t)

## Description

Initializes a new instance of `XMSHORTN4` from four `int16_t` arguments.

This constructor initializes a new instance of [XMSHORTN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmshortn4) from four
`int16_t` arguments.

**Note** This constructor is only available under C++.

## Parameters

### `_x`

Value of the x-coordinate of the vector, the **x** member of the new
`XMSHORTN4` instance.

### `_y`

Value of the y-coordinate of the vector, the **y** member of the new
`XMSHORTN4` instance.

### `_z`

Value of the z-coordinate of the vector, the **z** member of the new
`XMSHORTN4` instance.

### `_w`

Value of the w-coordinate of the vector, the **w** member of the new
`XMSHORTN4` instance.

## Remarks

Input values are not normalized. The following pseudocode demonstrates the operation of
this constructor:

```

	XMSHORTN4 instance;

	instance.x = _x;
	instance.y = _y;
	instance.z = _z;
	instance.w = _w;

```

## See also

**Reference**

[XMSHORTN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmshortn4)

[XMSHORTN4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmshortn4-ctor)