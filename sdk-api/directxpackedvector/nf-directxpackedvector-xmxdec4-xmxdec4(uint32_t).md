# XMXDEC4::XMXDEC4(uint32_t)

## Description

Initializes a new instance of `XMXDEC4` from a `uint32_t6` variable containing
component data in a packed format.

This constructor initializes a new instance of [XMXDEC4](https://msdn.microsoft.com/5b46e0fb-e4a5-49c4-8084-0c631d43d4f7) from a
`uint32_t` variable containing component data in a packed format.

**Note** This constructor is only available under C++.

## Parameters

### `Packed`

The values of the four components of the new instance of `XMXDEC4` are
stored in the argument `Packed` as follows:

## Remarks

The values of the four components of the new instance of `XMXDEC4` are stored in
the argument `Packed` as follows:

* The first 10 bits (bits 0-9) of **Packed** assigned, as an integer, to
  the **x** member of the instance of `XMXDEC4` constructed.
* The second 10 bits (bits 10-19) of **Packed** assigned, as an integer, to
  the **y** member of the instance of `XMXDEC4` constructed.
* The third 10 bits (bits 20-29) of **Packed** assigned, as an integer, to
  the **z** member of the instance of `XMXDEC4` constructed.
* The last 2 bits (bits 30-31) of **Packed** assigned, as an unsigned integer, to
  the **w** member of the instance of `XMXDEC4` constructed.

## See also

**Reference**

[XMXDEC4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmxdec4)

[XMXDEC4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmxdec4-ctor)