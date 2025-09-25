# DXGI_ADAPTER_FLAG enumeration

## Description

Identifies the type of DXGI adapter.

## Constants

### `DXGI_ADAPTER_FLAG_NONE:0`

Specifies no flags.

### `DXGI_ADAPTER_FLAG_REMOTE:1`

Value always set to 0. This flag is reserved.

### `DXGI_ADAPTER_FLAG_SOFTWARE:2`

Specifies a software adapter. For more info about this flag, see [new info in Windows 8 about enumerating adapters](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-programming-guide-dxgi).

**Direct3D 11:** This enumeration value is supported starting with Windows 8.

### `DXGI_ADAPTER_FLAG_FORCE_DWORD:0xffffffff`

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile
to a size other than 32 bits. This value is not used.

## Remarks

The **DXGI_ADAPTER_FLAG** enumerated type is used by the **Flags** member of the [DXGI_ADAPTER_DESC1](https://learn.microsoft.com/windows/desktop/api/dxgi/ns-dxgi-dxgi_adapter_desc1) or [DXGI_ADAPTER_DESC2](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ns-dxgi1_2-dxgi_adapter_desc2) structure to
identify the type of DXGI adapter.

## See also

[DXGI Enumerations](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-enums)