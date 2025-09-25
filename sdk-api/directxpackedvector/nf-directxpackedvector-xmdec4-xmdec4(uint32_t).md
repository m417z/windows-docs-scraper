# XMDEC4::XMDEC4(uint32_t)

## Description

Initializes a new instance of `XMDEC4` from a `uint32_t` variable containing
component data in a packed format.

This constructor initializes a new instance of [XMDEC4](https://msdn.microsoft.com/a52fa5e4-ee45-4256-a06a-6984d63b5578) from a
`uint32_t` variable containing component data in a packed format.

**Note** This constructor is only available under C++.

## Parameters

### `Packed`

The values of the four components of the new instance of `XMDEC4` are
stored in the argument `Packed` as follows:

## Remarks

The values of the four components of the new instance of `XMDEC4` are stored in
the argument `Packed` as follows:

* The first 10 bits (bits 0-9) of **Packed** assigned, as an integer, to
  the **x** member of the instance of `XMDEC4` constructed.
* The second 10 bits (bits 10-19) of **Packed** assigned, as an integer, to
  the **y** member of the instance of `XMDEC4` constructed.
* The third 10 bits (bits 20-29) of **Packed** assigned, as an integer, to
  the **z** member of the instance of `XMDEC4` constructed.
* The last 2 bits (bits 30-31) of **Packed** assigned, as an integer, to
  the **w** member of the instance of `XMDEC4` constructed.

## See also

**Reference**

[XMDEC4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmdec4)

[XMDEC4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmdec4-ctor)