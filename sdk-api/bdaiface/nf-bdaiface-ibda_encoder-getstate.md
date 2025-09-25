# IBDA_Encoder::GetState

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Queries the current state of the Encoder Service.

## Parameters

### `AudioBitrateMax` [out]

Receives the maximum audio bit rate.

### `AudioBitrateMin` [out]

Receives the minimum audio bit rate.

### `AudioBitrateMode` [out]

Receives the audio compression mode. The following values are defined.

| Value | Meaning |
| --- | --- |
| **PBDA_Encoder_BitrateMode_Constant**<br><br>0x00000001 | Constant bit rate (CBR) mode. |
| **PBDA_Encoder_BitrateMode_Variable**<br><br>0x00000002 | Variable bit rate (VBR) mode. |
| **PBDA_Encoder_BitrateMode_Average**<br><br>0x00000003 | Average bit rate (ABR) mode. |

### `AudioBitrateStepping` [out]

Receives the minimum increment for the audio bit rate.

### `AudioBitrate` [out]

Receives the audio bit rate.

### `AudioMethodID` [out]

Receives the active audio encoder method.

### `AvailableAudioPrograms` [out]

Receives the number of audio programs available to the encoder.

### `AudioProgram` [out]

Receives the program number of the audio program that is currently being encoded.

### `VideoBitrateMax` [out]

Receives the maximum video bit rate.

### `VideoBitrateMin` [out]

Receives the minimum video bit rate.

### `VideoBitrateMode` [out]

Receives the video compression mode. For a list of values, see *AudioBitrateMode*.

### `VideoBitrate` [out]

Receives the video bit rate.

### `VideoBitrateStepping` [out]

Receives the minimum increment for the video bit rate.

### `VideoMethodID` [out]

Receives the active video encoder method.

### `SignalSourceID` [out]

Receives the identifier of the signal source. The value is an auxiliary connector ID, as returned by the [IBDA_AUX::EnumCapability](https://learn.microsoft.com/windows/desktop/api/bdaiface/nf-bdaiface-ibda_aux-enumcapability) method.

### `SignalFormat` [out]

Receives a value from the [AnalogVideoStandard](https://learn.microsoft.com/windows/win32/api/strmif/ne-strmif-analogvideostandard) enumeration. This value specifies the analog video standard that is received on the auxiliary input.

### `SignalLock` [out]

Receives the value **TRUE** if the device has a signal lock, and **FALSE** otherwise.

### `SignalLevel` [out]

Receives the signal level in decibels.

### `SignalToNoiseRatio` [out]

Receives a value between 0 and 100, indicating the signal-to-noise ratio.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IBDA_Encoder](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_encoder)