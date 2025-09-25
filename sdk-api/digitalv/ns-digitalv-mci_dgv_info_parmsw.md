# MCI_DGV_INFO_PARMSW structure

## Description

The **MCI_DGV_INFO_PARMS** structure contains parameters for the [MCI_INFO](https://learn.microsoft.com/windows/desktop/Multimedia/mci-info) command for digital-video devices.

## Members

### `dwCallback`

The low-order word specifies a window handle used for the MCI_NOTIFY flag.

### `lpstrReturn`

Pointer to buffer for return string.

### `dwRetSize`

Size, in bytes, of return buffer.

### `dwItem`

Constant describing information to return.

## Remarks

When assigning data to the members of this structure, set the corresponding flags in the *fdwCommand* parameter of the [mciSendCommand](https://learn.microsoft.com/previous-versions/dd757160(v=vs.85)) function to validate the members.

> [!NOTE]
> The digitalv.h header defines MCI_DGV_INFO_PARMS as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[MCI](https://learn.microsoft.com/windows/desktop/Multimedia/mci)

[MCI Structures](https://learn.microsoft.com/windows/desktop/Multimedia/mci-structures)

[MCI_INFO](https://learn.microsoft.com/windows/desktop/Multimedia/mci-info)

[mciSendCommand](https://learn.microsoft.com/previous-versions/dd757160(v=vs.85))