# D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT structure

## Description

Details the adapter's GPU virtual address space limitations, including maximum address bits per resource and per process.

## Members

### `MaxGPUVirtualAddressBitsPerResource`

The maximum GPU virtual address bits per resource.

Some adapters have significantly less bits available per resource than per process, while other adapters have significantly greater bits available per resource than per process. The latter scenario tends to happen in less common scenarios, like when running a 32-bit process on certain UMA adapters.
When per resource capabilities are greater than per process, the greater per resource capabilities can only be leveraged by reserved resources or NULL mapped pages.

### `MaxGPUVirtualAddressBitsPerProcess`

The maximum GPU virtual address bits per process.

When this value is nearly equal to the available residency budget, [Evict](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-evict) will not be a feasible option to manage residency. See [MakeResident](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-makeresident) for more details.

## Remarks

See the enumeration constant D3D12_FEATURE_GPU_VIRTUAL_ADDRESS_SUPPORT in the [D3D12_FEATURE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_feature) enumeration.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)

[D3D12_FEATURE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_feature)