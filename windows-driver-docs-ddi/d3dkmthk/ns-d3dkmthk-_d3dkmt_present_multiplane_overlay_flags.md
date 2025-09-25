# D3DKMT_PRESENT_MULTIPLANE_OVERLAY_FLAGS structure

## Description

Present multi-plane overlay flags.

## Members

### `FlipStereo`

Specifies whether the driver should flip both left and right images of a stereo allocation.

### `FlipStereoTemporaryMono`

Specifies whether the driver should use the left image of a stereo allocation for the right and left portions of a stereo frame. The driver performs the same present operation as with **FlipStereo**, except that it should scan out only from the left image to produce both images of a stereo frame.

### `FlipStereoPreferRight`

Specifies that when the driver clones a stereo primary allocation to a mono monitor, it should use the right image.

The **FlipStereoTemporaryMono** and **FlipStereoPreferRight** members can't both be set at the same time.

### `FlipDoNotWait`

A UINT value that specifies whether the OpenGL installable client driver (ICD) requires that the present operation wait for the number of queued flip surfaces to fall below a particular limit before the operation begins. Setting this member indicates that the ICD does not require waiting. The default limit for the number of queued flip surfaces is three.

### `FlipDoNotFlip`

A UINT value that specifies whether to insert queued waits into the rendering stream. Setting this member indicates to flip to the same surface that is currently being scanned out.

### `FlipRestart`

A UINT value that specifies whether to restart a flip to a new surface.

### `DurationValid`

Indicates whether the duration is valid.

### `HDRMetaDataValid`

Indicates whether the HDR metadata is valid.

### `HMD`

The HMD (head mounted display).

### `TrueImmediate`

If a present interval is 0, allow tearing rather than override a previously queued flip.

### `FromDDisplay`

Indicates the present is from DirectDisplay.

### `Reserved`

Reserved for internal use.

### `Value`

The value used to operate over the other members.

## Remarks

## See also