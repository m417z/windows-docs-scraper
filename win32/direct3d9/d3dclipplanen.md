# D3DCLIPPLANEn macro

Defines bit patterns that enable user-defined clipping planes. These macros are defined as a convenience when setting values for the D3DRS\_CLIPPLANEENABLE render state.

## Parameters

This macro has no parameters.

## Return value

This macro does not return a value.

## Remarks

User-defined clipping planes are enabled when the value set in the D3DRS\_CLIPPLANEENABLE render state contains one or more set bits (that is, is not 0). The value of the render-state is not important; the system does not interpret the value as a number. Rather, the value enables the clipping plane whose corresponding bit is set. Bit 0 controls the state of the first clipping plane (at index 0), bit 1 the second plane, and so on.

The bit patterns that these macros create can be combined by using a logical OR operation to simultaneously enable multiple clipping planes. Omitting one of these macros from the combination effectively disables the clipping plane at that index.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Macros](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-macros)

