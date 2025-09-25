## Description

Reserved for system use. Do not use.

## Members

### `NativeGpuFenceSupported`

Specifies whether the native GPU fence feature is supported by this GPU. For more information about the native GPU fence feature, see [Native GPU fence](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects).

### `Reserved`

Reserved for system use.

### `Value`

An alternative way to access the cap bits.

## Remarks

The graphics kernel uses **D3DKMT_WDDM_3_1_CAPS** to store various capabilities introduced in WDDM version 3.1. The driver provides its support capabilities during initialization, so it already knows all the values specified in this structure.