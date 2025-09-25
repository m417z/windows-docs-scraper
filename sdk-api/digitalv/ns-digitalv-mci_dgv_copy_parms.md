# MCI_DGV_COPY_PARMS structure

## Description

The **MCI_DGV_COPY_PARMS** structure contains parameters for the [MCI_COPY](https://learn.microsoft.com/windows/desktop/Multimedia/mci-copy) command for digital-video devices.

## Members

### `dwCallback`

The low-order word specifies a window handle used for the MCI_NOTIFY flag.

### `dwFrom`

Starting position for copy.

### `dwTo`

Ending position for copy.

### `ptOffset`

### `ptExtent`

### `rc`

Rectangle describing area to be copied. Be aware that [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structures are handled differently in MCI than in other parts of Windows; in MCI, **rc.right** contains the width of the rectangle and **rc.bottom** contains its height.

### `dwAudioStream`

Audio stream.

### `dwVideoStream`

Video stream.

## Remarks

When assigning data to the members of this structure, set the corresponding flags in the *fdwCommand* parameter of the [mciSendCommand](https://learn.microsoft.com/previous-versions/dd757160(v=vs.85)) function to validate the members.

## See also

[MCI](https://learn.microsoft.com/windows/desktop/Multimedia/mci)

[MCI Structures](https://learn.microsoft.com/windows/desktop/Multimedia/mci-structures)

[MCI_COPY](https://learn.microsoft.com/windows/desktop/Multimedia/mci-copy)

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

[mciSendCommand](https://learn.microsoft.com/previous-versions/dd757160(v=vs.85))