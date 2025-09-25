# MCI_DGV_STEP_PARMS structure

## Description

The **MCI_DGV_STEP_PARMS** structure contains parameters for the [MCI_STEP](https://learn.microsoft.com/windows/desktop/Multimedia/mci-step) command for digital-video devices.

## Members

### `dwCallback`

The low-order word specifies a window handle used for the MCI_NOTIFY flag.

### `dwFrames`

Number of frames to step.

## Remarks

When assigning data to the members of this structure, set the corresponding flags in the *fdwCommand* parameter of the [mciSendCommand](https://learn.microsoft.com/previous-versions/dd757160(v=vs.85)) function to validate the members.

## See also

[MCI](https://learn.microsoft.com/windows/desktop/Multimedia/mci)

[MCI Structures](https://learn.microsoft.com/windows/desktop/Multimedia/mci-structures)

[MCI_STEP](https://learn.microsoft.com/windows/desktop/Multimedia/mci-step)

[mciSendCommand](https://learn.microsoft.com/previous-versions/dd757160(v=vs.85))