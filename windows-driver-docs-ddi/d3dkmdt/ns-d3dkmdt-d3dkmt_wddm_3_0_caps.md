## Description

Reserved for system use. Do not use.

## Members

### `HwFlipQueueSupportState`

DXGK_FEATURE_SUPPORT_*XXX* value that specifies the driver support state for GPU-supported hardware flip queue. This field can be one of the following values:

| Value | Meaning |
| ----- | ------- |
| DXGK_FEATURE_SUPPORT_ALWAYS_OFF | When a driver doesn't support a feature, it doesn't call into QueryFeatureSupport with that feature ID. This value is provided for implementation convenience of enumerating possible driver support states for a particular feature. |
| DXGK_FEATURE_SUPPORT_EXPERIMENTAL | Driver support for a feature is in the experimental state. |
| DXGK_FEATURE_SUPPORT_STABLE | Driver support for a feature is in the stable state. |
| DXGK_FEATURE_SUPPORT_ALWAYS_ON | Driver support for a feature is in the always on state. The driver doesn't operate without this feature enabled. |

### `HwFlipQueueEnabled`

Specifies whether the hardware flip queue is currently enabled for this GPU.

### `DisplayableSupported`

Specifies whether displayable feature is supported.

### `Reserved`

Reserved.

### `Value`

An alternative way to access the cap bits.

## Remarks

The graphics kernel uses **D3DKMT_WDDM_3_0_CAPS** to store various capabilities introduced in Windows Display Driver Model (WDDM) version 3.0. The driver provides its support capabilities during initialization, so it already knows all the values specified in this structure.