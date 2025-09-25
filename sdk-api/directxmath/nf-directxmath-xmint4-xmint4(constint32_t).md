# XMINT4::XMINT4(const int32_t)

## Description

Initializes a new instance of `XMINT4` from a four element `int32_t` array
argument.

This constructor initializes a new instance of [XMINT4](https://learn.microsoft.com/windows/desktop/direct3dhlsl/xmint4) from a from
a four element `int32_t` array argument.

**Note** This constructor is only available under C++.

## Parameters

### `pArray`

Four element `int32_t` array containing the values used to initialize the
four components of a new instance of `XMINT4`.

## Remarks

The following pseudocode demonstrates the operation of this constructor:

```

	XMINT4 instance;
	instance.x = pArray[0];
	instance.y = pArray[1];
	instance.z = pArray[2];
	instance.w = pArray[3];

```

## See also

**Reference**

[XMINT4](https://learn.microsoft.com/windows/desktop/direct3dhlsl/xmint4)

[XMINT4 Constructors](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmint4-xmint4(constint32_t))