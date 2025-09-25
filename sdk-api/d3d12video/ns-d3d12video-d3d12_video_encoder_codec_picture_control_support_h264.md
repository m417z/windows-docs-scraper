## Description

Represents picture control support settings for H.264 video encoding.

## Members

### `MaxL0ReferencesForP`

The maximum value allowed in the slice headers for (num_ref_idx_l0_active_minus1 +1) when encoding P frames. This is equivalent to the maximum size of an L0 for a P frame supported.

### `MaxL0ReferencesForB`

The maximum value allowed in the slice headers for (num_ref_idx_l0_active_minus1 +1) when encoding B frames. This is equivalent to the maximum size of an L0 for a B frame supported.

### `MaxL1ReferencesForB`

The maximum value allowed in the slice headers for (num_ref_idx_l1_active_minus1 +1) when encoding B frames. This is equivalent to the maximum size of an L1 for a B frame supported.

### `MaxLongTermReferences`

The maximum number of references used in a frame that can be marked as long term reference.

### `MaxDPBCapacity`

The maximum number of unique pictures that can be used from the DPB the caller manages (number of unique indices in L0 union L1) for a given [EncodeFrame](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist2-encodeframe) command on the underlying hardware.

## Remarks

## See also