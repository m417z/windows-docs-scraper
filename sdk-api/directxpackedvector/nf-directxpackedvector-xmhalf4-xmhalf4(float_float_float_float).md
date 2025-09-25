# XMHALF4::XMHALF4(float,float,float,float)

## Description

Initializes a new instance of `XMHALF4` from four `float` arguments.

This constructor initializes a new instance of [XMHALF4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmhalf4) from four
`float` arguments.

**Note** This constructor is only available under C++.

## Parameters

### `_x`

Value of the x-coordinate of the vector, the **x** member of the new
`XMHALF4` instance.

### `_y`

Value of the y-coordinate of the vector, the **y** member of the new
`XMHALF4` instance.

### `_z`

Value of the z-coordinate of the vector, the **z** member of the new
`XMHALF4` instance.

### `_w`

Value of the w-coordinate of the vector, the **w** member of the new
`XMHALF4` instance.

## Remarks

If the magnitude of one of this constructor's floating point arguments cannot be
represented by the `HALF` type, the corresponding member of the new instance of
`XMHALF4` will be infinity for a 16-bit integer (+0x7FFF).

The following pseudocode demonstrates the operation of this constructor using the XNA
Math [XMConvertFloatToHalf](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/nf-directxpackedvector-xmconvertfloattohalf) function:

```

	XMHALF4 instance;

	instance.x = XMConvertFloatToHalf(_x);
	instance.y = XMConvertFloatToHalf(_y);
	instance.z = XMConvertFloatToHalf(_z);
	instance.w = XMConvertFloatToHalf(_w);

```

## See also

**Reference**

[XMConvertFloatToHalf](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/nf-directxpackedvector-xmconvertfloattohalf)

[XMHALF4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmhalf4)

[XMHALF4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmhalf4-ctor)