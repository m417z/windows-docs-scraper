# XMBYTEN2::XMBYTEN2(float,float)

## Description

Initializes a new instance of `XMBYTEN2` from two `float` arguments.

This constructor initializes a new instance of [XMBYTEN2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmbyten2)  from two `float` arguments.

**Note** This constructor is only available with C++.

## Parameters

### `_x`

A normalized value for the x-coordinate of the vector.

This argument should be between -1.0 and 1.0. During the instantiation
of an instance of `XMBYTEN2`, it
is multiplied by `127.0f`, and then stored as the **x** member of the structure.

### `_y`

A normalized value for the y-coordinate of the vector, the **y** of the new instance of `XMBYTEN2`.

This argument should be between -1.0 and 1.0. During the instantiation
of an instance of `XMBYTEN2`, it
is multiplied by `127.0f`, and then stored as the **y** member of the structure.

## Remarks

The magnitude of each argument to the constructor will be clamped to the range supported by an 8-bit signed integer
[-127.0, 127.0].

The following pseudocode demonstrates the operation of this constructor, which takes advantage of the `union` of the four components of the `XMBYTEN2` vector with an instance of `uint32_t` in the definition of the
structure:

```

      XMBYTEN2 instance;
      _x1=min( max( _x, -1.0 ), 1.0 );
      _y1=min( max( _y, -1.0 ), 1.0 );
      _x1 = round( _x1 *  127.0f);
      _y1 = round( _y1 *  127.0f);
      instance.x = (int8_t)_x1;
      instance.y = (int8_t)_y1;

```

## See also

**Reference**

[XMBYTEN2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmbyten2)

[XMBYTEN2 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmbyten2-ctor)