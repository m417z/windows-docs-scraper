# MCI_DGV_LIST_PARMSA structure

## Description

The **MCI_DGV_LIST_PARMS** structure contains the information for the [MCI_LIST](https://learn.microsoft.com/windows/desktop/Multimedia/mci-list) command for digital-video devices.

## Members

### `dwCallback`

The low-order word specifies a window handle used for the MCI_NOTIFY flag.

### `lpstrReturn`

Buffer for return string.

### `dwLength`

Length, in bytes, of buffer.

### `dwNumber`

Index of item in list.

### `dwItem`

Type of list item.

### `lpstrAlgorithm`

String containing algorithm name.

## Remarks

When assigning data to the members of this structure, set the corresponding flags in the *fdwCommand* parameter of the [mciSendCommand](https://learn.microsoft.com/previous-versions/dd757160(v=vs.85)) function to validate the members.

> [!NOTE]
> The digitalv.h header defines MCI_DGV_LIST_PARMS as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[MCI](https://learn.microsoft.com/windows/desktop/Multimedia/mci)

[MCI Structures](https://learn.microsoft.com/windows/desktop/Multimedia/mci-structures)

[MCI_LIST](https://learn.microsoft.com/windows/desktop/Multimedia/mci-list)

[mciSendCommand](https://learn.microsoft.com/previous-versions/dd757160(v=vs.85))