# KS_SEEKING_FLAGS enumeration

## Description

The KS_SEEKING_FLAGS enumeration lists positioning options that can be used in conjunction with the [KSPROPERTY_POSITIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_positions) structure.

## Constants

### `KS_SEEKING_NoPositioning`

### `KS_SEEKING_AbsolutePositioning`

### `KS_SEEKING_RelativePositioning`

### `KS_SEEKING_IncrementalPositioning`

### `KS_SEEKING_PositioningBitsMask`

### `KS_SEEKING_SeekToKeyFrame`

### `KS_SEEKING_ReturnTime`

## Remarks

The minidriver sets these flag values in a [KSPROPERTY_POSITIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_positions) structure that it then submits in a [KSPROPERTY_MEDIASEEKING_POSITIONS](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-mediaseeking-positions) property request.

## See also

[KSPROPERTY_MEDIASEEKING_POSITIONS](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-mediaseeking-positions)

[KSPROPERTY_POSITIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_positions)