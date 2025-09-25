# XMFLOAT2::XMFLOAT2(const float)

## Description

Initializes a new instance of `XMFLOAT2` from a two element `float` array
argument.

This constructor initializes a new instance of [XMFLOAT2](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmfloat2) from a from
a two element `float` array argument.

**Note** This constructor is only available under C++.

## Parameters

### `pArray`

Two element `float` array containing the values used to initialize the
two components of a new instance of `XMFLOAT2`.

## Remarks

```

	XMFLOAT2 instance;
	instance.x = pArray[0];
	instance.y = pArray[1];
	instance.z = pArray[2];
	instance.w = pArray[3];

```

## See also

**Reference**

[XMFLOAT2](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmfloat2)

[XMFLOAT2 Constructors](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmfloat2-xmfloat2(constfloat))