# D3D12_DRED_ENABLEMENT enumeration

## Description

Defines constants (used by the [ID3D12DeviceRemovedExtendedDataSettings interface](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12deviceremovedextendeddatasettings)) that specify how individual Device Removed Extended Data (DRED) features are enabled. As of DRED version 1.1, the default value for all settings is **D3D12_DRED_ENABLEMENT_SYSTEM_CONTROLLED**.

## Constants

### `D3D12_DRED_ENABLEMENT_SYSTEM_CONTROLLED` (0)

Specifies that a DRED feature is enabled only when DRED is turned on by the system automatically (for example, when a user is reproducing a problem via FeedbackHub).

### `D3D12_DRED_ENABLEMENT_FORCED_OFF` (1)

Specifies that a DRED feature should be force-disabled, regardless of the system state.

### `D3D12_DRED_ENABLEMENT_FORCED_ON` (2)

Specifies that a DRED feature should be force-enabled, regardless of the system state.

## Remarks

## See also

* [Core enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)
* [Use DRED to diagnose GPU faults](https://learn.microsoft.com/windows/desktop/direct3d12/use-dred)