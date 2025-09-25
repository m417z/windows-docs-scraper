# KSAC3_ERROR_CONCEALMENT structure

## Description

The KSAC3_ERROR_CONCEALMENT structure specifies how errors in an AC-3-encoded stream should be concealed during playback.

## Members

### `fRepeatPreviousBlock`

Specifies whether to repeat the previous block when an error occurs. If **TRUE**, the decoder repeats the last block not in error as long as errors are detected in the input stream. If **FALSE**, the decoder mutes. A muted output stream does not necessarily result in any data packets. Instead, the renderer might substitute a more reliable stream or simply output silence.

### `fErrorInCurrentBlock`

Specifies whether the current block contains an error. If **TRUE**, the current block contains an error. If **FALSE**, the current block has no errors.

## Remarks

This structure is used by the [KSPROPERTY_AC3_ERROR_CONCEALMENT](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-ac3-error-concealment) property.

## See also

[KSPROPERTY_AC3_ERROR_CONCEALMENT](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-ac3-error-concealment)