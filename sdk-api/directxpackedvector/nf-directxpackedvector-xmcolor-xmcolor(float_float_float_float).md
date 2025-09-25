# XMCOLOR::XMCOLOR(float,float,float,float)

## Description

Initializes a new instance of `XMCOLOR` from four `float` arguments.

This constructor initializes a new instance of [XMCOLOR](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmcolor)  from four
`float` arguments.

**Note** This constructor is only available under C++.

## Parameters

### `_r`

Normalized value for the *red* channel of a 32-bit ARGB color
stored in the new instance of `XMCOLOR`. The value of this argument
should be in the range [0.0 - 1.0].

### `_g`

Normalized value for the *green* channel of a 32-bit ARGB
color stored in the new instance of `XMCOLOR`. The value of this
argument should be in the range [0.0 - 1.0].

### `_b`

Normalized value for the *blue* channel of a 32-bit ARGB
color stored in the new instance of `XMCOLOR`. The value of this
argument should be in the range [0.0 - 1.0].

### `_a`

Normalized value for the *alpha* channel of a 32-bit ARGB
color stored in the new instance of `XMCOLOR`. The value of this
argument should be in the range [0.0 - 1.0].

## Remarks

During the instantiation of an instance of `XMCOLOR`, all input arguments to
this constructor are clamped to a range of [0.0, 1.0], multiplied by `255.0f`,
as well as rounded, and before being stored in the appropriate structure member.

The following pseudocode demonstrates the operation of this constructor, which takes
advantage of the `union` of the four components of the `XMCOLOR` vector with an instance of `uint32_t` in the definition of the structure:

```

        XMCOLOR instance;
	_a1 = min( max( _a, 0.0 ), 1.0 );
	_r1 = min( max( _r, 0.0 ), 1.0 );
	_g1 = min( max( _g, 0.0 ), 1.0 );
	_b1 = min( max( _b, 0.0 ), 1.0 );

	_a1 = round ( _a1 * 255.0f );
	_r1 = round ( _r1 * 255.0f );
	_g1 = round ( _g1 * 255.0f );
	_b1 = round ( _b1 * 255.0f );

	instance.v =  ( (uint32_t)_a1  << 24) |
                      ( (uint32_t)_r1  << 16) |
                      ( (uint32_t)_g1  <<  8) |
                      ( (uint32_t)_b1 );

```

## See also

**Reference**

[XMCOLOR](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmcolor)

[XMCOLOR Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmcolor-ctor)