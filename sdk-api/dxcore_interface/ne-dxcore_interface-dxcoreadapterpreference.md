## Description

Defines constants that specify DXCore adapter preferences to be used as list-sorting criteria. You can sort a DXCore adapter list by passing an array of **DXCoreAdapterPreference** to [IDXCoreAdapterList::Sort](https://learn.microsoft.com/windows/win32/dxcore/dxcore_interface/nf-dxcore_interface-idxcoreadapterlist-sort).

## Constants

### `Hardware:0`

Specifies a preference for hardware adapters (as opposed to software adapters).

### `MinimumPower:1`

Specifies a preference for the minimum-powered GPU (such as an integrated graphics processor, or iGPU).

### `HighPerformance:2`

Specifies a preference for the highest-performance GPU, such as an external graphics processor (xGPU), if available, or discrete graphics processor (dGPU) if available.

## See also

[IDXCoreAdapterList::Sort](https://learn.microsoft.com/windows/win32/dxcore/dxcore_interface/nf-dxcore_interface-idxcoreadapterlist-sort), [DXCore reference](https://learn.microsoft.com/windows/win32/dxcore/dxcore-reference), [Using DXCore to enumerate adapters](https://learn.microsoft.com/windows/win32/dxcore/dxcore-enum-adapters)