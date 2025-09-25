## Description

Reserved for system use. Do not use.

## Members

### `HwSchSupported`

Supports hardware-accelerated GPU scheduling.

### `HwSchEnabled`

Indicates that hardware-accelerated GPU scheduling is enabled.

### `HwSchEnabledByDefault`

Indicates that hardware-accelerated GPU scheduling is enabled by default.

### `IndependentVidPnVSyncControl`

The driver supports independent VidPn VSync control.

### `Reserved`

Reserved.

### `Value`

An alternative way to access the cap bits.

## Remarks

The graphics kernel uses **D3DKMT_WDDM_2_7_CAPS** to store various capabilities introduced in Windows Display Driver Model (WDDM) version 2.7. The driver provides its support capabilities during initialization, so it already knows all the values specified in this structure.