# _DXGK_MONITORLINKINFO_CAPABILITIES structure

## Description

Flags which describe the capabilities for driving the monitor.

## Members

### `Stereo`

If TRUE and resources are not constrained by other paths, stereo display modes are supported.

### `WideColorSpace`

If TRUE, the driver has the hardware capability to perform 3x3 rotation matrix to transform RGB values from the gamut defined by the sRGB/709 primaries to the panel’s primaries. The driver can also send any necessary control signaling to the connected display to indicate the correct interpretation of the pixel data being sent. This includes handling signed input in the range (-2.0 to 2.0). The driver must do this with all input surface formats 8888, 10-10-102, and fp16.

### `HighColorSpace`

If TRUE, the driver supports all of the above WideColorSpace gamut functionality and also has the ability to apply the appropriate transfer curve for that display. This means accepting canonical color space data in the range [-128.0 to 256.0] and sending any necessary control signaling to the connected display to indicate the correct interpretation.

### `DynamicColorSpace`

If TRUE, the display miniport driver supports seamless changing of the wire format bits per color channel on this display if no other attributes are changed which would cause a glitch. If FALSE, seamless changing of bits per color channel is not supported.

### `DynamicBitsPerColorChannel`

If TRUE, the display miniport driver supports seamless changing of the wire format color encoding on this display if no other attributes are changed which would cause a glitch. If FALSE, seamless changing of color encoding is not supported.

### `DynamicColorEncodingFormat`

If TRUE, the display miniport driver supports seamless changing of the color space on this display if no other attributes are changed which would cause a glitch. If FALSE, seamless changing of color space is not supported.

### `DedicatedTimingGeneration`

If TRUE, the timing generation for this display is independent from the timing generation of other displays such that mode enumeration for this target may be performed in isolation from other active targets. Changing timing on this display does not change the timings available for any other display and vice versa.

In general, this flag is target based rather than based on the combination of the target and the attached display. However, there may be cases where some baseline capability is dedicated but beyond the baseline resources that are shared across targets. In this case, if the attached display’s maximum requirements fit within the baseline, the driver would be able to report the timing generation as dedicated and therefore enable optimized enumeration of cofunctional timings.

### `TargetIndependentPrimary`

Indicates that the target can support the HDR pixel format.

Used to indicate that the primary surfaces that are used to scan out to this display may be used on other targets on this adapter that set this flag and vice versa. This would allow primary surfaces to be shared across targets or moved from one target to another. Once this flag is set on a VidPn target, OS will not specify the VidPn source ID on the primary allocations which will be used crossing the VidPn sources connected to the VidPn targets with this capability in the same SyncLock group.

In WDDM 2.4 and WDDM 2.5, the only use of this capability is to verify that it is set when the SyncLockIdentical flag is set.

>[!Note]
>This flag is deprecated in WDDM 2.6 and must be set to 0.

### `SyncLockIdentical`

The display attached to this target can be synchronized to other displays on this adapter which also support synchronization if the target modes are identical.

Supported starting in WDDM 2.4.

### `Hdr10Plus`

The display supports HDR10Plus as per the [HDR10Plus](https://hdr10plus.org/) spec.

### `DolbyVisionLowLatency`

Supports dolby vision at low latency.

### `VariableRefresh`

### `Reserved`

This value is reserved for system use.

### `Value`