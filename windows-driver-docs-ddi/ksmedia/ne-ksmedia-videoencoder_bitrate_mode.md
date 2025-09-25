# VIDEOENCODER_BITRATE_MODE enumeration

## Description

The VIDEOENCODER_BITRATE_MODE enumeration describes the bit rate encoding modes supported by the device.

## Constants

### `ConstantBitRate`

 Specifies that the encoding bit rate is constant.

### `VariableBitRateAverage`

Specifies that the encoding bit rate is variable, with the specified bit rate used as a guaranteed average over a specified window. The default window size is considered to be 5 minutes. That is, this guarantees that the average bit rate over the window period (5 minutes) will not exceed that specified in [ENCAPIPARAM_BITRATE](https://learn.microsoft.com/windows-hardware/drivers/stream/encapiparam-bitrate).

### `VariableBitRatePeak`

Specifies that the encoding bit rate is variable with the specified bit rate used as an average with a peak not to exceed the specified peak bit rate over a specified window. The default window size is considered to be 500ms (classically one GOP). That is, this bit rate is "constant quality" − the bit rate is expected to average around [ENCAPIPARAM_BITRATE](https://learn.microsoft.com/windows-hardware/drivers/stream/encapiparam-bitrate) but may spike above this. It cannot exceed the bit rate specified in [ENCAPIPARAM_PEAK_BITRATE](https://learn.microsoft.com/windows-hardware/drivers/stream/encapiparam-peak-bitrate).

## Remarks

For all three modes, [ENCAPIPARAM_BITRATE](https://learn.microsoft.com/windows-hardware/drivers/stream/encapiparam-bitrate) must be set to the expected average bit rate over a 5 minute period.

When **VariableBitRatePeak** mode is used, the [ENCAPIPARAM_PEAK_BITRATE](https://learn.microsoft.com/windows-hardware/drivers/stream/encapiparam-peak-bitrate) must also be set to the peak bit rate, which the VBR encoder must not exceed over a 500ms period (typically one GOP for MPEG-2 video).

## See also

[ENCAPIPARAM_BITRATE](https://learn.microsoft.com/windows-hardware/drivers/stream/encapiparam-bitrate)

[ENCAPIPARAM_BITRATE_MODE](https://learn.microsoft.com/windows-hardware/drivers/stream/encapiparam-bitrate-mode)

[ENCAPIPARAM_PEAK_BITRATE](https://learn.microsoft.com/windows-hardware/drivers/stream/encapiparam-peak-bitrate)