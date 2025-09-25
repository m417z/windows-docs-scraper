# D3DKMT_WDDM_2_0_CAPS structure

## Description

Reserved for system use. Do not use.

## Members

### `Support64BitAtomics`

Supports 64-bit atomics.

### `GpuMmuSupported`

Supports GPU memory management.

### `IoMmuSupported`

Supports input/output memory management.

### `FlipOverwriteSupported`

Supports flip overwrite.

### `SupportContextlessPresent`

Supports contextless present display.

### `SupportSurpriseRemoval`

Supports surprise removal.

### `Reserved`

Reserved.

### `Value`

An alternative way to access the cap bits.

## Remarks

The graphics kernel uses **D3DKMT_WDDM_2_0_CAPS** to store various capabilities introduced in Windows Display Driver Model (WDDM) version 2.0. The driver provides its support capabilities during initialization, so it already knows all the values specified in this structure.