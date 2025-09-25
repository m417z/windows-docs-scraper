# MCI_DGV_CUT_PARMS structure

## Description

The **MCI_DGV_CUT_PARMS** structure contains parameters for the [MCI_CUT](https://learn.microsoft.com/windows/desktop/Multimedia/mci-cut) command for digital-video devices.

## Members

### `dwCallback`

The low-order word specifies a window handle used for the MCI_NOTIFY flag.

### `dwFrom`

Starting position for cut.

### `dwTo`

Ending position for cut.

### `ptOffset`

### `ptExtent`

### `rc`

Rectangle describing area to be cut. [RECT](https://learn.microsoft.com/previous-versions//ms536136(v=vs.85)) structures are handled differently in MCI than in other parts of Windows; in MCI, **rc.right** contains the width of the rectangle and **rc.bottom** contains its height.

### `dwAudioStream`

Audio stream.

### `dwVideoStream`

Video stream.

## Remarks

When assigning data to the members of this structure, set the corresponding flags in the *fdwCommand* parameter of the [mciSendCommand](https://learn.microsoft.com/previous-versions/dd757160(v=vs.85)) function to validate the members.

## See also

[MCI](https://learn.microsoft.com/windows/desktop/Multimedia/mci)

[MCI Structures](https://learn.microsoft.com/windows/desktop/Multimedia/mci-structures)

[MCI_CUT](https://learn.microsoft.com/windows/desktop/Multimedia/mci-cut)

[RECT](https://learn.microsoft.com/previous-versions//ms536136(v=vs.85))

[mciSendCommand](https://learn.microsoft.com/previous-versions/dd757160(v=vs.85))