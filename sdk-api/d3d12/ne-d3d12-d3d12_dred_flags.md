# D3D12_DRED_FLAGS enumeration

## Description

> [!NOTE]
> As of Windows 10, version 1903, **D3D12_DRED_FLAGS** is deprecated, and it may not be available in future versions of Windows.

Defines constants used in the [D3D12_DEVICE_REMOVED_EXTENDED_DATA structure](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_device_removed_extended_data) to specify control flags for the Direct3D runtime. Values can be bitwise OR'd together.

## Constants

### `D3D12_DRED_FLAG_NONE` (0x0)

Typically specifies that Device Removed Extended Data (DRED) is disabled, except for when user-initiated feedback is used to produce a repro, or when otherwise enabled by Windows via automatic detection of process-instability issues. This is the default value.

### `D3D12_DRED_FLAG_FORCE_ENABLE` (0x1)

Forces DRED to be enabled, regardless of the system state.

### `D3D12_DRED_FLAG_DISABLE_AUTOBREADCRUMBS` (0x2)

Disables DRED auto breadcrumbs.

## Remarks

## See also

* [Core enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)
* [D3D12_DEVICE_REMOVED_EXTENDED_DATA structure](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_device_removed_extended_data)
* [Use DRED to diagnose GPU faults](https://learn.microsoft.com/windows/desktop/direct3d12/use-dred)