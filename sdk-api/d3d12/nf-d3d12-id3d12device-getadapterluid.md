# ID3D12Device::GetAdapterLuid

## Description

Gets a locally unique identifier for the current device (adapter).

## Return value

Type: **[LUID](https://learn.microsoft.com/windows/desktop/api/ntdef/ns-ntdef-luid)**

The locally unique identifier for the adapter.

## Remarks

This method returns a unique identifier for the adapter that is specific to the adapter hardware.
Applications can use this identifier to define robust mappings across various APIs (Direct3D 12, DXGI).

A locally unique identifier (LUID) is a 64-bit value that is guaranteed to be unique only on the system on which it was generated.
The uniqueness of a locally unique identifier (LUID) is guaranteed only until the system is restarted.

## See also

[ID3D12Device](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12device)