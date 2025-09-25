# _DXGKARG_SETTARGETADJUSTEDCOLORIMETRY2 structure

## Description

Describes the colorimetry and SDR white level for a video present target. Used in the [DXGKDDI_SETTARGETADJUSTEDCOLORIMETRY2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_settargetadjustedcolorimetry2) callback function.

## Members

### `TargetId`

The identifier of a display adapter's video present target.

### `AdjustedColorimetry`

A [DXGK_COLORIMETRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_colorimetry) structure containing the colorimetry related fields for the monitor attached to this target after the OS has processed the display device descriptor, all overrides and any adjustments.

### `SdrWhiteLevel`

This represents the SDR (standard dynamic range) white level value in nits for all SDR content displayed to the video present target.

The OS assumes that all SDR content it is given is at 80 nits and by default this white level is appropriate.

The user may request that the OS boost the white level of all SDR content. When a boost is applied, the OS and the driver are responsible for boosting all SDR content appropriately when the white level is not set at 80 nits.

The driver is responsible for boosting the hardware cursor when it is in use.

This adjustment should be applied as follows:

```cpp
RGBout = RGBin * (SDRWhiteLevel / 80);
```

The driver is also potentially responsible for boosting the contents of an SDR MPO (multi-plane overlay) plane. The driver should use the SDR white level given by the plane attributes to make the determination of whether it should boost the SDR MPO plane.

## Remarks

## See also