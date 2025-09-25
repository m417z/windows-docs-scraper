# D3D11_COUNTER_INFO structure

## Description

Information about the video card's performance counter capabilities.

## Members

### `LastDeviceDependentCounter`

Type: **[D3D11_COUNTER](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_counter)**

Largest device-dependent counter ID that the device supports. If none are supported, this value will be 0. Otherwise it will be greater than or equal to D3D11_COUNTER_DEVICE_DEPENDENT_0. See [D3D11_COUNTER](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_counter).

### `NumSimultaneousCounters`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of counters that can be simultaneously supported.

### `NumDetectableParallelUnits`

Type: **UINT8**

Number of detectable parallel units that the counter is able to discern. Values are 1 ~ 4. Use NumDetectableParallelUnits to interpret the values of the VERTEX_PROCESSING, GEOMETRY_PROCESSING, PIXEL_PROCESSING, and OTHER_GPU_PROCESSING counters.

## Remarks

This structure is returned by [ID3D11Device::CheckCounterInfo](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-checkcounterinfo).

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-structures)