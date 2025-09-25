# MCI_DGV_SET_PARMS structure

## Description

The **MCI_DGV_SET_PARMS** structure contains parameters for the [MCI_SET](https://learn.microsoft.com/windows/desktop/Multimedia/mci-set) command for digital-video devices.

## Members

### `dwCallback`

The low-order word specifies a window handle used for the MCI_NOTIFY flag.

### `dwTimeFormat`

Time format of device.

### `dwAudio`

Channel for audio output.

### `dwFileFormat`

File format.

### `dwSpeed`

Playback speed.

## Remarks

When assigning data to the members of this structure, set the corresponding flags in the *fdwCommand* parameter of the [mciSendCommand](https://learn.microsoft.com/previous-versions/dd757160(v=vs.85)) function to validate the members.

## See also

[MCI](https://learn.microsoft.com/windows/desktop/Multimedia/mci)

[MCI Structures](https://learn.microsoft.com/windows/desktop/Multimedia/mci-structures)

[MCI_SET](https://learn.microsoft.com/windows/desktop/Multimedia/mci-set)

[mciSendCommand](https://learn.microsoft.com/previous-versions/dd757160(v=vs.85))