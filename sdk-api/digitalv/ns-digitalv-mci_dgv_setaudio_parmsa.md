# MCI_DGV_SETAUDIO_PARMSA structure

## Description

The **MCI_DGV_SETAUDIO_PARMS** structure contains parameters for the [MCI_SETAUDIO](https://learn.microsoft.com/windows/desktop/Multimedia/mci-setaudio) command for digital-video devices.

## Members

### `dwCallback`

The low-order word specifies a window handle used for the MCI_NOTIFY flag.

### `dwItem`

Constant indicating the target adjustment. For a list of possible values, see the [MCI_SETAUDIO](https://learn.microsoft.com/windows/desktop/Multimedia/mci-setaudio) command.

### `dwValue`

Adjustment level.

### `dwOver`

Transmission length.

### `lpstrAlgorithm`

Pointer to a null-terminated string containing the name of the audio-compression algorithm.

### `lpstrQuality`

Pointer to a null-terminated string containing a descriptor of the audio-compression algorithm.

## Remarks

When assigning data to the members of this structure, set the corresponding flags in the *fdwCommand* parameter of the [mciSendCommand](https://learn.microsoft.com/previous-versions/dd757160(v=vs.85)) function to validate the members.

> [!NOTE]
> The digitalv.h header defines MCI_DGV_SETAUDIO_PARMS as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[MCI](https://learn.microsoft.com/windows/desktop/Multimedia/mci)

[MCI Structures](https://learn.microsoft.com/windows/desktop/Multimedia/mci-structures)

[MCI_SETAUDIO](https://learn.microsoft.com/windows/desktop/Multimedia/mci-setaudio)

[mciSendCommand](https://learn.microsoft.com/previous-versions/dd757160(v=vs.85))