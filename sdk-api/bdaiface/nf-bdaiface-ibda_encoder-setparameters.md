# IBDA_Encoder::SetParameters

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Sets the parameters for the Encoder Service.

## Parameters

### `AudioBitrateMode` [in]

The audio compression mode. The following values are defined.

| Value | Meaning |
| --- | --- |
| **PBDA_Encoder_BitrateMode_Constant**<br><br>0x00000001 | Constant bit rate (CBR) mode. |
| **PBDA_Encoder_BitrateMode_Variable**<br><br>0x00000002 | Variable bit rate (VBR) mode. |
| **PBDA_Encoder_BitrateMode_Average**<br><br>0x00000003 | Average bit rate (ABR) mode. |

### `AudioBitrate` [in]

The audio bit rate.

### `AudioMethodID` [in]

The active audio encoder method.

### `AudioProgram` [in]

The audio program number.

### `VideoBitrateMode` [in]

The video compression mode. For a list of values, see *AudioBitrateMode*.

### `VideoBitrate` [in]

The video bit rate.

### `VideoMethodID` [in]

The active video encoder method.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IBDA_Encoder](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_encoder)