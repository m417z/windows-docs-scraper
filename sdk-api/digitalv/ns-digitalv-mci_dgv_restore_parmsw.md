# MCI_DGV_RESTORE_PARMSW structure

## Description

The **MCI_DGV_RESTORE_PARMS** structure contains information for the [MCI_RESTORE](https://learn.microsoft.com/windows/desktop/Multimedia/mci-restore) command for digital-video devices.

## Members

### `dwCallback`

The low-order word specifies a window handle used for the MCI_NOTIFY flag.

### `lpstrFileName`

Pointer to a null-terminated string containing the filename from which the frame buffer information will be restored.

### `ptOffset`

### `ptExtent`

### `rc`

Rectangle containing positioning information. [RECT](https://learn.microsoft.com/previous-versions//ms536136(v=vs.85)) structures are handled differently in MCI than in other parts of Windows; in MCI, **rc.right** contains the width of the rectangle and **rc.bottom** contains its height.

## Remarks

When assigning data to the members of this structure, set the corresponding flags in the *fdwCommand* parameter of the [mciSendCommand](https://learn.microsoft.com/previous-versions/dd757160(v=vs.85)) function to validate the members.

> [!NOTE]
> The digitalv.h header defines MCI_DGV_RESTORE_PARMS as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[MCI](https://learn.microsoft.com/windows/desktop/Multimedia/mci)

[MCI Structures](https://learn.microsoft.com/windows/desktop/Multimedia/mci-structures)

[MCI_RESTORE](https://learn.microsoft.com/windows/desktop/Multimedia/mci-restore)

[RECT](https://learn.microsoft.com/previous-versions//ms536136(v=vs.85))

[mciSendCommand](https://learn.microsoft.com/previous-versions/dd757160(v=vs.85))