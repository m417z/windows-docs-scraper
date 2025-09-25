# MCI_DGV_UPDATE_PARMS structure

## Description

The **MCI_DGV_UPDATE_PARMS** structure contains parameters for the [MCI_UPDATE](https://learn.microsoft.com/windows/desktop/Multimedia/mci-update) command.

## Members

### `dwCallback`

The low-order word specifies a window handle used for the MCI_NOTIFY flag.

### `ptOffset`

### `ptExtent`

### `rc`

Rectangle containing positioning information. [RECT](https://learn.microsoft.com/previous-versions//ms536136(v=vs.85)) structures are handled differently in MCI than in other parts of Windows; in MCI, **rc.right** contains the width of the rectangle and **rc.bottom** contains its height.

### `hDC`

Handle to display context.

### `wReserved0`

## Remarks

When assigning data to the members of this structure, set the corresponding flags in the *fdwCommand* parameter of the [mciSendCommand](https://learn.microsoft.com/previous-versions/dd757160(v=vs.85)) function to validate the members.

## See also

[MCI](https://learn.microsoft.com/windows/desktop/Multimedia/mci)

[MCI Structures](https://learn.microsoft.com/windows/desktop/Multimedia/mci-structures)

[MCI_UPDATE](https://learn.microsoft.com/windows/desktop/Multimedia/mci-update)

[RECT](https://learn.microsoft.com/previous-versions//ms536136(v=vs.85))

[mciSendCommand](https://learn.microsoft.com/previous-versions/dd757160(v=vs.85))