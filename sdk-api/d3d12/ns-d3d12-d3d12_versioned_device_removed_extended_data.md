# D3D12_VERSIONED_DEVICE_REMOVED_EXTENDED_DATA structure

## Description

Represents versioned Device Removed Extended Data (DRED) data, so that debuggers and debugger extensions can access DRED data.

## Members

### `Version`

A [D3D12_DRED_VERSION](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_dred_version) value, specifying a DRED version. This value determines which inner data member (of the union) is active.

### `Dred_1_0`

A [D3D12_DEVICE_REMOVED_EXTENDED_DATA](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_device_removed_extended_data) value, containing DRED version 1.0 data.

### `Dred_1_1`

A [D3D12_DEVICE_REMOVED_EXTENDED_DATA1](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_device_removed_extended_data1) value, containing DRED version 1.1 data.

## See also

* [Core structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)
* [Use DRED to diagnose GPU faults](https://learn.microsoft.com/windows/desktop/direct3d12/use-dred)