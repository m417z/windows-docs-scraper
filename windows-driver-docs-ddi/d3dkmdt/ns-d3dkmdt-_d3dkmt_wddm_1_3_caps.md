# D3DKMT_WDDM_1_3_CAPS structure

## Description

Reserved for system use. Do not use.

## Members

### `SupportMiracast`

Supports Miracast.

### `IsHybridIntegratedGPU`

The display is hybrid integrated GPU.

### `IsHybridDiscreteGPU`

The display is hybrid discrete GPU.

### `SupportPowerManagementPStates`

Supports power management states.

### `SupportVirtualModes`

Supports virtual modes.

### `SupportCrossAdapterResource`

Supports cross adapter resource.

### `Reserved`

Reserved.

### `Value`

An alternative way to access the cap bits.

## Remarks

The graphics kernel uses **D3DKMT_WDDM_1_3_CAPS** to store various capabilities introduced in Windows Display Driver Model (WDDM) version 1.3. The driver provides its support capabilities during initialization, so it already knows all the values specified in this structure.