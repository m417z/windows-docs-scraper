## Description

Reserved for system use. Do not use.

## Members

### `PreemptionCaps`

Has preemption capabilities.

### `SupportNonVGA`

Supports non-VGA.

### `SupportSmoothRotation`

Supports smooth rotation.

### `SupportPerEngineTDR`

Supports per-engine timeout detection and recovery (TDR).

### `SupportKernelModeCommandBuffer`

Supports kernel-mode command buffer.

### `SupportCCD`

Supports Connecting and Configuring Displays (CCD).

### `SupportSoftwareDeviceBitmaps`

Supports software device bitmaps.

### `SupportGammaRamp`

Supports gamma ramp.

### `SupportHWCursor`

Supports hardware cursor.

### `SupportHWVSync`

Supports hardware Vsync.

### `SupportSurpriseRemovalInHibernation`

Supports surprise removal in hibernation.

### `Reserved`

Reserved.

### `Value`

An alternative way to access the cap bits.

## Remarks

The graphics kernel uses **D3DKMT_WDDM_1_2_CAPS** to store various capabilities introduced in Windows Display Driver Model (WDDM) version 1.2. The driver provides its support capabilities during initialization, so it already knows all the values specified in this structure.