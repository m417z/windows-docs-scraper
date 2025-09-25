# MCI_DGV_WINDOW_PARMSA structure

## Description

The **MCI_DGV_WINDOW_PARMS** structure contains parameters for [MCI_WINDOW](https://learn.microsoft.com/windows/desktop/Multimedia/mci-window) command for digital-video devices.

## Members

### `dwCallback`

The low-order word specifies a window handle used for the MCI_NOTIFY flag.

### `hWnd`

Handle to the display window. If this member is MCI_DGV_WINDOW_HWND, the system uses a default window.

### `wReserved1`

### `nCmdShow`

Window-display command.

### `wReserved2`

### `lpstrText`

Window caption.

## Remarks

When assigning data to the members of this structure, set the corresponding flags in the *fdwCommand* parameter of the [mciSendCommand](https://learn.microsoft.com/previous-versions/dd757160(v=vs.85)) function to validate the members

> [!NOTE]
> The digitalv.h header defines MCI_DGV_WINDOW_PARMS as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[MCI](https://learn.microsoft.com/windows/desktop/Multimedia/mci)

[MCI Structures](https://learn.microsoft.com/windows/desktop/Multimedia/mci-structures)

[MCI_WINDOW](https://learn.microsoft.com/windows/desktop/Multimedia/mci-window)

[mciSendCommand](https://learn.microsoft.com/previous-versions/dd757160(v=vs.85))