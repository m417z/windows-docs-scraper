# XMFLOAT3A::XMFLOAT3A(const float)

## Description

Initializes a new instance of `XMFLOAT3` from a three element `float` array argument.

This constructor initializes a new instance of [XMFLOAT3](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmfloat3) from a from a three element
`float` array argument.

**Note** This constructor is only available under C++.

## Parameters

### `pArray`

Three element floating point array containing the values used to initialize the three components of a new instance of
`XMFLOAT3`.

## Remarks

The following pseudocode demonstrates the operation of this constructor:

```

	XMFLOAT3 instance;
	instance.x =  pArray[0];
	instance.y =  pArray[1];
	instance.z =  pArray[2];

```

## See also

**Reference**

[XMFLOAT3](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmfloat3)

[XMFLOAT3 Constructors](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmfloat3-xmfloat3(constfloat))