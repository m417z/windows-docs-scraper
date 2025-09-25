# D3D12DDI_VIDEO_PROCESS_ALPHA_BLENDING_0020 structure

## Description

Specifies whether alpha blending is enabled and, if so, the planar alpha value.

## Members

### `Enable`

Specifies whether alpha blending is enabled.

### `Alpha`

The planar alpha value. The value can range from 0.0 (transparent) to 1.0 (opaque). If the **Enable** member is false, this value is ignored.

## Remarks

For each pixel, the destination color value is computed as the following:

```cpp
Cd = Cs * (As * Ap * Ae) + Cd * (1.0 - As * Ap * Ae)
```

The variables in this equation are as follows:

* **Cd** = The color value of the destination pixel.
* **Cs** = The color value of the source pixel.
* **As** = The per-pixel source alpha.
* **Ap** = The planar alpha value.
* **Ae** = The palette-entry alpha value, or 1.0.