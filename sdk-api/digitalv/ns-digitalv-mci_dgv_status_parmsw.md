# MCI_DGV_STATUS_PARMSW structure

## Description

The **MCI_DGV_STATUS_PARMS** structure contains parameters for the [MCI_STATUS](https://learn.microsoft.com/windows/desktop/Multimedia/mci-status) command for digital-video devices.

## Members

### `dwCallback`

The low-order word specifies a window handle used for the MCI_NOTIFY flag.

### `dwReturn`

Buffer for return information.

### `dwItem`

Identifies capability being queried.

### `dwTrack`

Length or number of tracks.

### `lpstrDrive`

Specifies the approximate amount of disk space that can be obtained by the [MCI_RESERVE](https://learn.microsoft.com/windows/desktop/Multimedia/mci-reserve) command.

### `dwReference`

Specifies the approximate location of the nearest previous intraframe-encoded image.

## Remarks

When assigning data to the members of this structure, set the corresponding flags in the *fdwCommand* parameter of the [mciSendCommand](https://learn.microsoft.com/previous-versions/dd757160(v=vs.85)) function to validate the members.

> [!NOTE]
> The digitalv.h header defines MCI_DGV_STATUS_PARMS as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[MCI](https://learn.microsoft.com/windows/desktop/Multimedia/mci)

[MCI Structures](https://learn.microsoft.com/windows/desktop/Multimedia/mci-structures)

[MCI_RESERVE](https://learn.microsoft.com/windows/desktop/Multimedia/mci-reserve)

[MCI_STATUS](https://learn.microsoft.com/windows/desktop/Multimedia/mci-status)

[mciSendCommand](https://learn.microsoft.com/previous-versions/dd757160(v=vs.85))