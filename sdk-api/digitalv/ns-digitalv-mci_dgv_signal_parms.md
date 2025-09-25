# MCI_DGV_SIGNAL_PARMS structure

## Description

The **MCI_DGV_SIGNAL_PARMS** structure contains parameters for the [MCI_SIGNAL](https://learn.microsoft.com/windows/desktop/Multimedia/mci-signal) command for digital-video devices.

## Members

### `dwCallback`

The low-order word specifies a window handle used for the MCI_NOTIFY flag.

### `dwPosition`

Position to be marked.

### `dwPeriod`

Interval of the position marks.

### `dwUserParm`

User value associated with signals.

## Remarks

When assigning data to the members of this structure, set the corresponding flags in the *fdwCommand* parameter of the [mciSendCommand](https://learn.microsoft.com/previous-versions/dd757160(v=vs.85)) function to validate the members.

## See also

[MCI](https://learn.microsoft.com/windows/desktop/Multimedia/mci)

[MCI Structures](https://learn.microsoft.com/windows/desktop/Multimedia/mci-structures)

[MCI_SIGNAL](https://learn.microsoft.com/windows/desktop/Multimedia/mci-signal)

[mciSendCommand](https://learn.microsoft.com/previous-versions/dd757160(v=vs.85))