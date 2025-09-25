# MCI_DGV_RECT_PARMS structure

## Description

The **MCI_DGV_RECT_PARMS** structure contains parameters for the [MCI_FREEZE](https://learn.microsoft.com/windows/desktop/Multimedia/mci-freeze), [MCI_PUT](https://learn.microsoft.com/windows/desktop/Multimedia/mci-put), [MCI_UNFREEZE](https://learn.microsoft.com/windows/desktop/Multimedia/mci-unfreeze), and [MCI_WHERE](https://learn.microsoft.com/windows/desktop/Multimedia/mci-where) commands for digital-video devices.

## Members

### `dwCallback`

The low-order word specifies a window handle used for the MCI_NOTIFY flag.

### `ptOffset`

### `ptExtent`

### `rc`

Rectangle containing positioning information. [RECT](https://learn.microsoft.com/previous-versions//ms536136(v=vs.85)) structures are handled differently in MCI than in other parts of Windows; in MCI, **rc.right** contains the width of the rectangle and **rc.bottom** contains its height.

## Remarks

The [MCI_DGV_FREEZE_PARMS](https://learn.microsoft.com/windows/desktop/api/digitalv/ns-digitalv-mci_dgv_rect_parms), [MCI_DGV_PUT_PARMS](https://learn.microsoft.com/previous-versions/dd743397(v=vs.85)), **MCI_DGV_UNFREEZE_PARMS** and **MCI_DGV_WHERE_PARMS** structures are identical to the **MCI_DGV_RECT_PARMS** structure.

When assigning data to the members of this structure, set the corresponding flags in the *fdwCommand* parameter of the [mciSendCommand](https://learn.microsoft.com/previous-versions/dd757160(v=vs.85)) function to validate the members.

## See also

[MCI](https://learn.microsoft.com/windows/desktop/Multimedia/mci)

[MCI Structures](https://learn.microsoft.com/windows/desktop/Multimedia/mci-structures)

[MCI_FREEZE](https://learn.microsoft.com/windows/desktop/Multimedia/mci-freeze)

[MCI_PUT](https://learn.microsoft.com/windows/desktop/Multimedia/mci-put)

[MCI_UNFREEZE](https://learn.microsoft.com/windows/desktop/Multimedia/mci-unfreeze)

[MCI_WHERE](https://learn.microsoft.com/windows/desktop/Multimedia/mci-where)

[RECT](https://learn.microsoft.com/previous-versions//ms536136(v=vs.85))

[mciSendCommand](https://learn.microsoft.com/previous-versions/dd757160(v=vs.85))